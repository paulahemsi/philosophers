/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:43:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 13:26:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(long long int time, int philo_number, char *status)
{
	printf("%lld %d %s\n", time, philo_number, status);
}

void	sleeping(long long int start_time, long long int duration, int index)
{
	print_status(get_elapsed_time(start_time), index, SLEEPING);
	do_action(duration);
}

void	eat(long long int start_time, long long int duration, pthread_mutex_t *fork, int index)
{
	print_status(get_elapsed_time(start_time), index, EATING);
	do_action(duration);
	pthread_mutex_unlock(&fork[LEFT]);
	pthread_mutex_unlock(&fork[RIGHT]);
	print_status(get_elapsed_time(start_time), index, "STOP EATING");
}

void	think(long long int start_time, int index)
{
	print_status(get_elapsed_time(start_time), index, THINKING);
}

void	take_forks(long long int start_time, pthread_mutex_t *fork, int index)
{
	pthread_mutex_lock(&fork[LEFT]);
	print_status(get_elapsed_time(start_time), index, FORK);
	pthread_mutex_lock(&fork[RIGHT]);
	print_status(get_elapsed_time(start_time), index, FORK);
}
