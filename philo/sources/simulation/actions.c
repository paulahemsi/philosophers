/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 20:38:48 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(long long int time, int philo_number, pthread_mutex_t *text, char *status, char *color)
{
	pthread_mutex_lock(text);
	printf("%s%-10lld %-3d %-20s%s\n", color, time, philo_number, status, RESET_COLOR);
	pthread_mutex_unlock(text);
}

void	sleeping(t_philo *philo)
{
	if (*philo->death)
		return ;
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, SLEEPING, GREEN);
	do_action(philo->time->to_sleep);
}

void	eat(t_philo *philo)
{
	if (*philo->death)
		return ;
	philo->last_meal = get_current_time();
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, EATING, V_GREEN);
	do_action(philo->time->to_eat);
	pthread_mutex_unlock(&philo->forks[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->forks[philo->hand[RIGHT]]);
}

void	think(t_philo *philo)
{
	if (*philo->death)
		return ;
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, THINKING, P_GREEN);
}

void	take_forks(t_philo *philo)
{
	if (*philo->death)
		return ;
	pthread_mutex_lock(&philo->forks[philo->hand[LEFT]]);
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, FORK, D_GREEN);
	pthread_mutex_lock(&philo->forks[philo->hand[RIGHT]]);
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, FORK, D_GREEN);
}
