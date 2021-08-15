/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:58:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 13:21:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosophers(t_philo *philo, t_dinner *dinner, int total, int i)
{
	while (i++ <= total)
	{
		philo[i].index = i;
		philo[i].time[0] = *dinner->time;
		philo[i].fork[0] = dinner->fork[i];
		philo[i].fork[1] = dinner->fork[i + 1];
	}
}

static void	init_mutexes(t_dinner *dinner, t_mutex *mutex, int total, int i)
{
	while(i++ <= total)
		pthread_mutex_init(&dinner->fork[i], NULL);
	pthread_mutex_init(&mutex->text, NULL);
}

void	init_simulation(t_dinner *dinner)
{
	init_mutexes(dinner, &dinner->mutex, dinner->total, 0);
	dinner->time->start = get_current_time();
	printf("START AT: %lld\n", dinner->time->start);
	init_philosophers(dinner->philo, dinner, dinner->total, 0);
	start_simulation(dinner, 0);
}
