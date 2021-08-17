/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/16 21:25:42 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_death(t_philo *philo)
{
	if (philo->last_meal == 0)
		return ;
	if ((get_current_time() - philo->last_meal) > philo->time->to_die)
	{
		*philo->death = true;
		print_status(get_elapsed_time(philo->time->start), philo->index, &philo->mutex->text, DIED, H_RED);
	}
}

static bool	is_even(int philo)
{
	if (philo % 2 == 0)
		return true;
	return false;
}

void	*routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	if (is_even(philo->index))
		delay(philo->time->to_eat / 10);
	while(true && !(*philo->death))
	{
		take_forks(philo);
		check_death(philo);
		eat(philo);
		sleeping(philo);
		think(philo);
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
