/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:58:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 16:09:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosophers(t_philo *philo, t_dinner *dinner, int total, int i)
{
	while (++i <= total)
	{
		philo[i].index = i;
		philo[i].hand[0] = i;
		philo[i].hand[1] = i + 1;
		if (i == total)
			philo[i].hand[1] = 1;
		philo[i].dinner = dinner;
	}
}

static void	init_mutexes(t_mutex *mutex, int total, int i)
{
	while(i++ <= total)
		pthread_mutex_init(&mutex->fork[i], NULL);
	pthread_mutex_init(&mutex->text, NULL);
	pthread_mutex_init(&mutex->death, NULL);
}

bool	init_simulation_fail(t_dinner *dinner)
{
	t_philo		philo[201];

	ft_memset(&philo, 0, sizeof(t_philo));
	init_mutexes(&dinner->mutex, dinner->total, 0);
	dinner->time.start = get_current_time();
	init_philosophers(philo, dinner, dinner->total, 0);
	if (start_simulation_failed(dinner, philo, 0))
		return (true);
	return (false);
}
