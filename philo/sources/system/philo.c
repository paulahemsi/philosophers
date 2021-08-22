/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:14:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 20:33:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(long long time, int index, pthread_mutex_t *text)
{
	pthread_mutex_lock(text);
	printf("%s%-10lld %-3d %-20s%s\n", H_RED, time, index, DIED, RESET);
	pthread_mutex_unlock(text);
}

static void	destroy_mutexes(t_mutex *mutex, int total, int i)
{
	while(i++ <= total)
		pthread_mutex_init(&mutex->fork[i], NULL);
	pthread_mutex_init(&mutex->text, NULL);
	pthread_mutex_init(&mutex->death, NULL);
	pthread_mutex_init(&mutex->end, NULL);
	pthread_mutex_init(&mutex->eaten, NULL);
}

static void	print_end_message(t_dinner	*dinner)
{
	if (dinner->time_of_death)
		print_death(dinner->time_of_death, dinner->end, &dinner->mutex.text);
	else
		printf("%s%s %-3d %-20s%s\n", H_YELLOW, END_1, dinner->time.must_eat, END_2, RESET);
}

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (!check_errors(argc, argv))
		return (EXIT_FAILURE);
	parse_arguments(argc, argv, &dinner);
	if (!init_simulation(&dinner))
		return (EXIT_FAILURE);
	print_end_message(&dinner);
	destroy_mutexes(&dinner.mutex, dinner.total, 0);
	return (0);
}
