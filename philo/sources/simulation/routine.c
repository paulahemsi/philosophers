/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:41:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 22:38:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_even(int philo)
{
	if (philo % 2 == 0)
		return true;
	return false;
}

void	*routine(void *philo_ptr)
{
	t_philo		*philo;
	pthread_t	end_searcher;

	philo = (t_philo *)philo_ptr;
	if (is_even(philo->index))
		delay(10, philo);
	pthread_create(&end_searcher, NULL, verify_end_conditions, philo);
	while(eat(philo) && sleeping(philo) && think(philo))
		continue ;
	pthread_detach(end_searcher);
	return (NULL);
}
