/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 20:30:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death(t_philo *philo)
{
	if ((get_current_time() - philo->last_meal) > philo->time->to_die)
	{
		*philo->death = true;
		print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, DIED, H_RED);
	}
}

void	*routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	while(true && !(*philo->death))
	{
		take_forks(philo);
		eat(philo);
		sleeping(philo);
		think(philo);
		check_death(philo);
	}
	return (philo_ptr);
}

void	start_simulation(t_dinner *dinner, int i)
{
	pthread_t	philosopher[200];

	while (++i <= dinner->total)
		if (pthread_create(&philosopher[i], NULL, &routine, &dinner->philo[i]) != 0)
			printf("TODO error msg + sair do programa\n");
}
