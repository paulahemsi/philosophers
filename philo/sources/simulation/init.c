/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:58:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/22 20:35:05 by phemsi-a         ###   ########.fr       */
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

static void	init_philos(t_philo *philo, t_dinner *dinner, int total, int i)
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
	while (i++ <= total)
		pthread_mutex_init(&mutex->fork[i], NULL);
	pthread_mutex_init(&mutex->text, NULL);
	pthread_mutex_init(&mutex->death, NULL);
}

static bool	only_one_philo(t_dinner *dinner)
{
	if (dinner->total == 1)
	{
		printf("%s%-10d %-3d %-20s%s\n", D_GREEN, 0, 1, FORK, RESET);
		dinner->time_of_death = dinner->time.to_die + 1;
		dinner->end = 1;
		delay(dinner->time.to_die);
		return (true);
	}
	return (false);
}

bool	init_simulation(t_dinner *dinner)
{
	t_philo		philo[202];

	init_philos(philo, dinner, dinner->total, 0);
	init_mutexes(&dinner->mutex, dinner->total, 0);
	if (only_one_philo(dinner))
		return (true);
	if (!start_simulation(dinner, philo))
		return (false);
	return (true);
}
