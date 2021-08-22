/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 21:22:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_status(long long time, t_philo *philo, char *status, char *color)
{
	int	index;

	index = philo->index;
	if (anyone_dead(philo))
		return (false);
	pthread_mutex_lock(&philo->dinner->mutex.text);
	printf("%s%-10lld %-3d %-20s%s\n", color, time, index, status, RESET);
	pthread_mutex_unlock(&philo->dinner->mutex.text);
	return (true);
}

bool	sleeping(t_philo *philo)
{
	long long int	start;

	start = philo->dinner->time.start;
	if (!print_status(get_elapsed_time(start), philo, SLEEP, GREEN))
		return (false);
	do_action(philo->dinner->time.to_sleep, philo);
	return (true);
}

static void	take_forks(t_philo *philo)
{
	long long int	start;

	start = philo->dinner->time.start;
	pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	print_status(get_elapsed_time(start), philo, FORK, D_GREEN);
	pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	print_status(get_elapsed_time(start), philo, FORK, D_GREEN);

	// long long int	start;

	// start = philo->dinner->time.start;
	// pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	// if (!print_status(get_elapsed_time(start), philo, FORK, D_GREEN))
	// 	return (false);
	// pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	// if (!print_status(get_elapsed_time(start), philo, FORK, D_GREEN))
	// 	return (false);
	// return (true);
}

bool	eat(t_philo *philo)
{
	long long int	start;

	start = philo->dinner->time.start;
	take_forks(philo);
	// if (!take_forks(philo))
	// 	return (false);
	philo->last_meal = get_elapsed_time(start);
	if (!print_status(get_elapsed_time(start), philo, EAT, V_GREEN))
		return (false);
	do_action(philo->dinner->time.to_eat, philo);
	philo->eaten_times++;
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	return (true);
}

bool	think(t_philo *philo)
{
	long long int	start;

	start = philo->dinner->time.start;
	if (!print_status(get_elapsed_time(start), philo, THINK, P_GREEN))
		return (false);
	return (true);
}
