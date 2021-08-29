/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:34:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/29 14:22:35 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	full_stomach(t_philo *philo)
{
	if (philo->dinner->time.must_eat)
		if (philo->eaten_times >= philo->dinner->time.must_eat)
			return (true);
	return (false);
}

bool	anyone_dead(t_philo *philo)
{
	if (philo->dinner->end)
		return (true);
	return (false);
}

static bool	define_death(t_philo *philo, long long int now)
{
	pthread_mutex_lock(&philo->eating);
	philo->dinner->end = philo->index;
	philo->dinner->time_of_death = now;
	pthread_mutex_unlock(&philo->eating);
	return (true);
}

static bool	ended(t_philo *philo)
{
	long long int	now;

	if (anyone_dead(philo) || full_stomach(philo))
		return (true);
	now = get_elapsed_time(philo->dinner->time.start);
	if (((now - philo->last_meal) > philo->dinner->time.to_die))
		return (define_death(philo, now));
	return (false);
}

void	*verify_end_conditions(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (!ended(philo))
		continue ;
	return (NULL);
}
