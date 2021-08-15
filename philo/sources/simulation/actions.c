/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 18:08:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(long long int time, int philo_number, pthread_mutex_t *text, char *status)
{
	pthread_mutex_lock(text);
	printf("%lld %d %s\n", time, philo_number, status);
	pthread_mutex_unlock(text);
}

void	sleeping(t_philo *philo)
{
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, SLEEPING);
	do_action(philo->time->to_sleep);
}

void	eat(t_philo *philo)
{
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, EATING);
	do_action(philo->time->to_eat);
	pthread_mutex_unlock(&philo->forks[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->forks[philo->hand[RIGHT]]);
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, "STOP EATING");
}

void	think(t_philo *philo)
{
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, THINKING);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->hand[LEFT]]);
	pthread_mutex_lock(&philo->mutex->text);
	printf("fork adress: %p\n", &philo->forks[philo->hand[LEFT]]);
	pthread_mutex_unlock(&philo->mutex->text);
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, FORK);
	pthread_mutex_lock(&philo->forks[philo->hand[RIGHT]]);
	pthread_mutex_lock(&philo->mutex->text);
	printf("fork adress: %p\n", &philo->forks[philo->hand[RIGHT]]);
	pthread_mutex_unlock(&philo->mutex->text);
	print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, FORK);
}
