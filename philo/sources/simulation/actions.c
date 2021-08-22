/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/22 11:58:37 by phemsi-a         ###   ########.fr       */
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
	do_action(philo->dinner->time.to_sleep);
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
}

bool	eat(t_philo *philo)
{
	long long int	start;

	start = philo->dinner->time.start;
	take_forks(philo);
	philo->last_meal = get_elapsed_time(start);
	if (!print_status(get_elapsed_time(start), philo, EAT, V_GREEN))
		return (false);
	do_action(philo->dinner->time.to_eat);
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->dinner->mutex.fork[philo->hand[RIGHT]]);
	philo->eaten_times++;
	if (full_stomach(philo))
	{
		// printf("vou retornar falso e preciso sair da minha rotina pq estou cheião. Ass:%d\n", philo->index);
		return (false);
	}
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
