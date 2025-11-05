/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:05:45 by apetoyan          #+#    #+#             */
/*   Updated: 2025/07/30 18:41:20 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now_s(void)
{
	struct timeval	time;
	long			now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

int	left_right(t_vars *vars, t_params **p, t_philo **ph)
{
	vars->left_fork = (*ph)->id;
	vars->right_fork = (vars->left_fork + 1) % (*p)->n_ph;
	if (vars->left_fork < vars->right_fork)
	{
		vars->is_first = vars->left_fork;
		vars->is_second = vars->right_fork;
	}
	else
	{
		vars->is_first = vars->right_fork;
		vars->is_second = vars->left_fork;
	}
	pthread_mutex_lock(&(*p)->death_lock);
	if ((*p)->someone_died)
	{
		pthread_mutex_unlock(&(*p)->death_lock);
		return (0);
	}
	pthread_mutex_unlock(&(*p)->death_lock);
	return (1);
}

void	smart_sleep(long ms, t_params *p)
{
	long	start;

	start = now_s() + ms;
	while (now_s() < start)
	{
		pthread_mutex_lock(&p->death_lock);
		if (p->someone_died)
		{
			pthread_mutex_unlock(&p->death_lock);
			break ;
		}
		pthread_mutex_unlock(&p->death_lock);
		usleep(500);
	}
}

int	dinner_part(t_params **p, t_philo **ph, t_vars *vars)
{
	if (!left_right(&(*vars), &(*p), &(*ph)))
		return (1);
	pthread_mutex_lock(&(*p)->noone[(*vars).is_first]);
	sms_func(&(*p), &(*ph), "has taken a fork");
	if ((*p)->n_ph != 1)
	{
		pthread_mutex_lock(&(*p)->noone[(*vars).is_second]);
		sms_func(&(*p), &(*ph), "has taken a fork");
		pthread_mutex_lock(&(*p)->meal_lock);
		(*ph)->last_meal_ms = now_s();
		(*ph)->eat_count++;
		pthread_mutex_unlock(&(*p)->meal_lock);
		sms_func(&(*p), &(*ph), "is eating");
		smart_sleep((*p)->time_to_eat, (*p));
	}
	pthread_mutex_unlock(&(*p)->noone[(*vars).is_first]);
	if ((*p)->n_ph != 1)
	{
		pthread_mutex_unlock(&(*p)->noone[(*vars).is_second]);
		if ((*p)->must_eat_cnt > 0 && (*ph)->eat_count >= (*p)->must_eat_cnt)
			return (1);
		sms_func(&(*p), &(*ph), "is sleeping");
		smart_sleep((*p)->time_to_sleep, (*p));
	}
	return (0);
}

void	*dinner(void *arg)
{
	t_philo		*ph;
	t_params	*p;
	t_vars		vars;

	ph = (t_philo *)arg;
	p = ph->pm;
	if (ph->id % 2 == 0 && p->n_ph != 1)
		smart_sleep(p->time_to_eat / 10, p);
	while (1)
	{
		if (dinner_part(&p, &ph, &vars))
			break ;
		pthread_mutex_lock(&p->death_lock);
		if (p->someone_died)
		{
			pthread_mutex_unlock(&p->death_lock);
			break ;
		}
		pthread_mutex_unlock(&p->death_lock);
		if (p->n_ph != 1)
			sms_func(&p, &ph, "is thinking");
		else
			smart_sleep(p->time_to_die + 2, p);
	}
	return (NULL);
}
