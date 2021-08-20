/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/20 19:48:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_death(t_philo *philo)
{
	long long int	now;

	if (anyone_dead(philo))
		return (true);
	if (philo->last_meal == 0)
		return (false);
	now = get_elapsed_time(philo->time.start);
	if ((now - philo->last_meal) > philo->time.to_die)
	{
		printf("MORRI! Ass.%d\n", philo->index);
		pthread_mutex_lock(&philo->mutex->death);
		*philo->death = philo->index;
		*philo->time_of_death = now;
		pthread_mutex_unlock(&philo->mutex->death);
		return (true);
	}
	return (false);
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
		delay(philo->time.to_eat / 10);
	while(eat(philo) && sleeping(philo) && think(philo))
		continue ;
	return (NULL);
}

void	start_simulation(t_dinner *dinner, int i)
{
	pthread_t	philosopher[201];

	while (++i <= dinner->total)
		if (pthread_create(&philosopher[i - 1], NULL, &routine, &dinner->philo[i]) != 0)
			printf("TODO error msg + sair do programa\n");
	i = 0;
	// while (++i <= dinner->total)
	// 	pthread_detach(philosopher[i]);
}
