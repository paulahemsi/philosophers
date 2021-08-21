/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 16:05:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	anyone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->mutex.death);
	if (philo->dinner->death)
	{
		pthread_mutex_unlock(&philo->dinner->mutex.death);
		return (true);
	}
	pthread_mutex_unlock(&philo->dinner->mutex.death);
	return (false);
}

bool	print_status(long long time, t_philo *philo, char *status, char *color)
{
	int	index;

	if (anyone_dead(philo) || is_death(philo))
		return (false);
	index = philo->index;
	pthread_mutex_lock(&philo->dinner->mutex.text);
	printf("%s%-10lld %-3d %-20s%s\n", color, time, index, status, RESET);
	pthread_mutex_unlock(&philo->dinner->mutex.text);
	return (true);
}

bool	sleeping(t_philo *philo)
{
	if (!print_status(get_elapsed_time(philo->dinner->time.start), philo, SLEEP, GREEN))
		return (false);
	do_action(philo->dinner->time.to_sleep, philo, "DORMINDO");
	return (true);
}

bool	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (false);
	if (!print_status(get_elapsed_time(philo->dinner->time.start), philo, EAT, V_GREEN))
		return (false);
	philo->last_meal = get_elapsed_time(philo->dinner->time.start);
	do_action(philo->dinner->time.to_eat, philo, "COMENDO");
	philo->dinner->time.has_eaten++;
	pthread_mutex_unlock(&philo->dinner->fork[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->dinner->fork[philo->hand[RIGHT]]);
	return (true);
}

bool	think(t_philo *philo)
{
	if (!print_status(get_elapsed_time(philo->dinner->time.start), philo, THINK, P_GREEN))
		return (false);
	return (true);
}

bool	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->fork[philo->hand[LEFT]]);
	if (!print_status(get_elapsed_time(philo->dinner->time.start), philo, FORK, D_GREEN))
		return (false);
	pthread_mutex_lock(&philo->dinner->fork[philo->hand[RIGHT]]);
	if (!print_status(get_elapsed_time(philo->dinner->time.start), philo, FORK, D_GREEN))
		return (false);
	return (true);
}
