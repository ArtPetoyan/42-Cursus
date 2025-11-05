/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:25:37 by apetoyan          #+#    #+#             */
/*   Updated: 2025/07/28 21:56:51 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_d_1(t_params **p, t_philo **philos, t_vars *vars)
{
	pthread_mutex_lock(&(*p)->meal_lock);
	vars->curent = now_s();
	if ((*p)->must_eat_cnt > 0
		&& (*philos)[vars->i].eat_count >= (*p)->must_eat_cnt)
		vars->count++;
	vars->curent_time = vars->curent - (*philos)[vars->i].last_meal_ms;
	if (vars->curent_time > (*p)->time_to_die)
	{
		pthread_mutex_lock(&(*p)->death_lock);
		(*p)->someone_died = 1;
		pthread_mutex_unlock(&(*p)->death_lock);
		pthread_mutex_unlock(&(*p)->meal_lock);
		print_message((*philos), vars->i + 1, "died", vars->curent
			- (*p)->start_ms);
		return (1);
	}
	pthread_mutex_unlock(&(*p)->meal_lock);
	return (0);
}

int	check_death(t_philo *philos, t_params *p)
{
	t_vars	vars;

	while (1)
	{
		vars.i = 0;
		vars.count = 0;
		while (vars.i < p->n_ph)
		{
			if (check_d_1(&p, &philos, &vars))
				return (1);
			vars.i++;
		}
		pthread_mutex_lock(&(p->meal_lock));
		if (p->must_eat_cnt > 0 && vars.count == p->n_ph)
		{
			pthread_mutex_unlock(&(p->meal_lock));
			return (0);
		}
		pthread_mutex_unlock(&(p->meal_lock));
		usleep(1000);
	}
	return (0);
}

void	main_1(t_params *pm, int argc, char **argv)
{
	pm->n_ph = ft_atoi(argv[1]);
	pm->time_to_die = ft_atoi(argv[2]);
	pm->time_to_eat = ft_atoi(argv[3]);
	pm->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		pm->must_eat_cnt = ft_atoi(argv[5]);
	else
		pm->must_eat_cnt = -1;
	if (pm->n_ph <= 0 || pm->time_to_die <= 0 || pm->time_to_eat <= 0
		|| pm->time_to_sleep <= 0 || (argc == 6 && pm->must_eat_cnt <= 0))
		error("atoi error");
	pm->someone_died = 0;
	pthread_mutex_init(&pm->death_lock, NULL);
	pthread_mutex_init(&pm->print_lock, NULL);
	pthread_mutex_init(&pm->meal_lock, NULL);
	pm->noone = ft_calloc(pm->n_ph, sizeof(pthread_mutex_t));
	if (!pm->noone)
		error("malloc error");
}

void	main_2(t_params *pm, t_philo **ph)
{
	int	i;

	i = 0;
	while (i < (*pm).n_ph)
		pthread_mutex_init(&(*pm).noone[i++], NULL);
	(*ph) = malloc(sizeof(t_philo) * (*pm).n_ph);
	if (!(*ph))
		error("malloc error");
	i = 0;
	(*pm).start_ms = now_s();
	while (i < (*pm).n_ph)
	{
		(*ph)[i].id = i;
		(*ph)[i].last_meal_ms = (*pm).start_ms;
		(*ph)[i].eat_count = 0;
		(*ph)[i].pm = &(*pm);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_params	pm;
	t_philo		*ph;
	int			i;

	if (argc < 5 || argc > 6)
		error("argument error");
	main_1(&pm, argc, argv);
	main_2(&pm, &ph);
	i = 0;
	while (i < pm.n_ph)
	{
		pthread_create(&ph[i].thread, NULL, dinner, &ph[i]);
		i++;
	}
	if (ph->eat_count != pm.must_eat_cnt)
		check_death(ph, &pm);
	i = 0;
	while (i < pm.n_ph && pm.n_ph != 1)
		pthread_join(ph[i++].thread, NULL);
	if (pm.n_ph == 1)
		pthread_join(ph[0].thread, NULL);
	free_all(&pm, ph);
	return (0);
}
