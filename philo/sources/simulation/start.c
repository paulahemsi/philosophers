/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:05:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 19:39:54 by phemsi-a         ###   ########.fr       */
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
		delay(philo->dinner->time.to_eat / 10);
	pthread_create(&end_searcher, NULL, verify_end_conditions, philo);
	while(eat(philo) && sleeping(philo) && think(philo))
		continue ;
	pthread_detach(end_searcher);
	return (NULL);
}

bool	start_simulation_failed(t_dinner *dinner, t_philo *philo, int i)//?mudar retorno da error_msg para tirar esse failed?
{
	pthread_t	philo_t[201];//?mudar para malloc?

	dinner->time.start = get_current_time();
	while (++i <= dinner->total)
		if (pthread_create(&philo_t[i - 1], NULL, &routine, &philo[i]) != 0)
			return (error_msg(THREAD_ERROR));
	while (!dinner->end)
		continue ;
	i = 0;
	while (++i <= dinner->total)
		if (pthread_join(philo_t[i - 1], NULL) != 0)
			return (error_msg(THREAD_ERROR));
	return (false);
}
