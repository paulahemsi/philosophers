/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 13:40:14 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_ptr)
{
	t_philo *philo;
	int i = 0;

	philo = (t_philo *)philo_ptr;
	while(i < 1000)
	{
		printf("START TIME: %lld\n", philo->time->start);
		take_forks(philo->time->start, philo->fork, philo->index);
		eat(philo->time->start, philo->time->to_eat, philo->fork, philo->index);
		sleeping(philo->time->start, philo->time->to_sleep, philo->index);
		think(philo->time->start, philo->index);
		i++;
	}
	return (philo_ptr);
}

void	start_simulation(t_dinner *dinner, int i)
{
	pthread_t	philosopher[200];

	while (i++ <= dinner->total)
		if (pthread_create(&philosopher[i], NULL, &routine, &dinner->philo[i]) != 0)
			printf("TODO error msg + sair do programa\n");
}
