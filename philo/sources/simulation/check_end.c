/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:34:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 19:39:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	anyone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->mutex.death);
	if (philo->dinner->end)
	{
		pthread_mutex_unlock(&philo->dinner->mutex.death);
		return (true);
	}
	pthread_mutex_unlock(&philo->dinner->mutex.death);
	return (false);
}

bool	is_death(t_philo *philo)
{
	long long int	now;

	if (anyone_dead(philo))
		return (true);
	if (philo->last_meal == 0)
		return (false);
	now = get_elapsed_time(philo->dinner->time.start);
	if ((now - philo->last_meal) > philo->dinner->time.to_die)
	{
		pthread_mutex_lock(&philo->dinner->mutex.death);
		philo->dinner->end = philo->index;
		philo->dinner->time_of_death = now;
		pthread_mutex_unlock(&philo->dinner->mutex.death);
		return (true);
	}
	return (false);
}

void	*verify_end_conditions(void *philo_ptr)
{
	t_philo		*philo;

	philo = (t_philo *)philo_ptr;
	while (!is_death(philo))
		continue ;
	return (NULL);
}
