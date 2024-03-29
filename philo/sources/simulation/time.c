/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:51:24 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/22 20:34:07 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long int	get_elapsed_time(long long int start_time)
{
	return ((get_current_time() - start_time));
}

void	do_action(long long int time_in_ms)
{
	usleep(time_in_ms * 1000);
}

void	delay(int delay_time)
{
	usleep(delay_time * 1000);
}
