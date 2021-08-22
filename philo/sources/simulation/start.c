/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/22 18:15:12 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	create_threads(int total, t_philo *philo, pthread_t *thread, int i)
{
	while (++i <= total)
		if (pthread_create(&thread[i - 1], NULL, &routine, &philo[i]) != 0)
			return (error_msg(THREAD_C_ERROR));
	return (true);
}

static bool	join_threads(int total, pthread_t *philo_t, int i)
{
	while (++i <= total)
		if (pthread_join(philo_t[i - 1], NULL) != 0)
			return (error_msg(THREAD_J_ERROR));
	return (true);
}

bool	start_simulation(t_dinner *dinner, t_philo *philo)
{
	pthread_t	philo_t[200];

	dinner->time.start = get_current_time();
	if (!create_threads(dinner->total, philo, philo_t, 0))
		return (false);
	if (!join_threads(dinner->total, philo_t, 0))
		return (false);
	return (true);
}
