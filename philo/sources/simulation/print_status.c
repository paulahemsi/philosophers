/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:35:56 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/29 13:43:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_meal(t_philo *philo, long long int now, char *status)
{
	if (ft_strcmp(status, EAT) == 0)
		philo->last_meal = now;
}

static void	print(t_philo *philo, char *status, char *color)
{
	long long int	now;

	now = get_elapsed_time(philo->dinner->time.start);
	pthread_mutex_lock(&philo->dinner->mutex.text);
	printf("%s%-10lld ", color, now);
	printf("%-3d %-20s%s\n", philo->index, status, RESET);
	pthread_mutex_unlock(&philo->dinner->mutex.text);
	update_last_meal(philo, now, status);
}

bool	print_status(t_philo *philo, char *status, char *color)
{
	if (anyone_dead(philo))
		return (false);
	print(philo, status, color);
	return (true);
}
