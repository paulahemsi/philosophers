/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 16:22:03 by phemsi-a         ###   ########.fr       */
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
	now = get_elapsed_time(philo->dinner->time.start);
	if ((now - philo->last_meal) > philo->dinner->time.to_die)
	{
		printf("MORRI! Ass.%d\n", philo->index);
		pthread_mutex_lock(&philo->dinner->mutex.death);
		philo->dinner->death = philo->index;
		philo->dinner->time_of_death = now;
		pthread_mutex_unlock(&philo->dinner->mutex.death);
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
		delay(philo->dinner->time.to_eat / 10);
	while(eat(philo) && sleeping(philo) && think(philo))
		continue ;
	return (NULL);
}

bool	start_simulation_failed(t_dinner *dinner, t_philo *philo, int i)//?mudar retorno da error_msg para tirar esse failed?
{
	pthread_t	philosopher[201]; //?mudar para malloc?

	while (++i <= dinner->total)
		if (pthread_create(&philosopher[i - 1], NULL, &routine, &philo[i]) != 0)
			return (error_msg(THREAD_ERROR));
	while (!dinner->death)
		continue ;
	i = 0;
	while (++i <= dinner->total)
		if (pthread_join(philosopher[i - 1], NULL) != 0)
			return (error_msg(THREAD_ERROR));
	return (false);
}
