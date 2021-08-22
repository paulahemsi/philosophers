/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:58:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 20:33:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	define_forks(t_philo *philo, int index, int last_philo)
{
	philo[index].hand[LEFT] = index;
	philo[index].hand[RIGHT] = index + 1;
	if (index == last_philo)
		philo[index].hand[RIGHT] = 1;
}

static void	init_philosophers(t_philo *philo, t_dinner *dinner, int total, int i)
{
	while (++i <= total)
	{
		ft_memset(&philo[i], 0, sizeof(t_philo));
		philo[i].index = i;
		define_forks(philo, i, total);
		philo[i].dinner = dinner;
	}
}

static void	init_mutexes(t_mutex *mutex, int total, int i)
{
	while(i++ <= total)
		pthread_mutex_init(&mutex->fork[i], NULL);
	pthread_mutex_init(&mutex->text, NULL);
	pthread_mutex_init(&mutex->death, NULL);
	pthread_mutex_init(&mutex->end, NULL);
	pthread_mutex_init(&mutex->eaten, NULL);
}

bool	init_simulation(t_dinner *dinner)
{
	t_philo		philo[201];

	init_philosophers(philo, dinner, dinner->total, 0);
	init_mutexes(&dinner->mutex, dinner->total, 0);
	if (!start_simulation(dinner, philo))
		return (false);
	return (true);
}
