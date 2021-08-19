/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/19 19:01:10 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(long long time, t_philo *philo, char *status, char *color)
{
	int	index;

	index = philo->index;
	pthread_mutex_lock(&philo->mutex->text);
	printf("%s%-10lld %-3d %-20s%s\n", color, time, index, status, RESET);
	pthread_mutex_unlock(&philo->mutex->text);
}

void	sleeping(t_philo *philo)
{
	if (*philo->death)
		return ;
	print_status(get_elapsed_time(philo->time->start), philo, SLEEP, GREEN);
	do_action(philo->time->to_sleep, philo);
}

void	eat(t_philo *philo)
{
	if (*philo->death)
		return ;
	philo->last_meal = get_elapsed_time(philo->time->start);
	print_status(get_elapsed_time(philo->time->start), philo, EAT, V_GREEN);
	do_action(philo->time->to_eat, philo);
	pthread_mutex_unlock(&philo->forks[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->forks[philo->hand[RIGHT]]);
}

void	think(t_philo *philo)
{
	if (*philo->death)
		return ;
	print_status(get_elapsed_time(philo->time->start), philo, THINK, P_GREEN);
}

void	take_forks(t_philo *philo)
{
	if (*philo->death)
		return ;
	pthread_mutex_lock(&philo->forks[philo->hand[LEFT]]);
	print_status(get_elapsed_time(philo->time->start), philo, FORK, D_GREEN);
	pthread_mutex_lock(&philo->forks[philo->hand[RIGHT]]);
	print_status(get_elapsed_time(philo->time->start), philo, FORK, D_GREEN);
}
