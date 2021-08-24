/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/23 21:31:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sleeping(t_philo *philo)
{
	if (!print_status(philo, SLEEP, GREEN))
		return (false);
	do_action(philo->dinner->time.to_sleep);
	return (true);
}

static void	take_forks(t_philo *philo)
{
	if (is_even(philo->index))
		pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	else
		pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	print_status(philo, FORK, D_GREEN);
	if (is_even(philo->index))
		pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	else
		pthread_mutex_lock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	print_status(philo, FORK, D_GREEN);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	philo->eaten_times++;
}

bool	eat(t_philo *philo)
{
	take_forks(philo);
	if (!print_status(philo, EAT, V_GREEN))
		return (false);
	do_action(philo->dinner->time.to_eat);
	drop_forks(philo);
	if (full_stomach(philo))
		return (false);
	return (true);
}

bool	think(t_philo *philo)
{
	if (!print_status(philo, THINK, P_GREEN))
		return (false);
	return (true);
}
