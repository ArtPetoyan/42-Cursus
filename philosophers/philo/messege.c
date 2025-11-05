/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messege.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:59:01 by apetoyan          #+#    #+#             */
/*   Updated: 2025/07/28 20:51:09 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	write(2, "\n", 1);
	exit(1);
}

void	sms_func(t_params **p, t_philo **ph, char *str)
{
	pthread_mutex_lock(&(*p)->death_lock);
	if (!(*p)->someone_died)
		print_message((*ph), (*ph)->id + 1, str, now_s() - (*p)->start_ms);
	pthread_mutex_unlock(&(*p)->death_lock);
}

void	print_message(t_philo *p, int i, char *str, long time)
{
	pthread_mutex_lock(&p->pm->print_lock);
	printf("%ld %d %s\n", time, i, str);
	pthread_mutex_unlock(&p->pm->print_lock);
}

void	free_all(t_params *params, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < params->n_ph)
		pthread_mutex_destroy(&params->noone[i++]);
	pthread_mutex_destroy(&params->death_lock);
	pthread_mutex_destroy(&params->print_lock);
	pthread_mutex_destroy(&params->meal_lock);
	free(params->noone);
	free(philos);
}
