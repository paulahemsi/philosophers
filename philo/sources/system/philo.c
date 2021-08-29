/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:14:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/29 14:24:07 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(long long time, int index)
{
	printf("%s%-10lld %-3d %-20s%s\n", H_RED, time, index, DIED, RESET);
}

static void	print_full(int times_to_eat)
{
	printf("%s%s %d %s%s\n", BOLD_H_YELLOW, END_1, times_to_eat, END_2, RESET);
}

static void	print_end_message(t_dinner	*dinner)
{
	if (dinner->time_of_death)
		print_death(dinner->time_of_death, dinner->end);
	else
		print_full(dinner->time.must_eat);
}

static void	destroy_mutexes(t_mutex *mutex, int total, int i)
{
	while (i++ <= total)
		pthread_mutex_destroy(&mutex->fork[i]);
	pthread_mutex_destroy(&mutex->text);
	//pthread_mutex_destroy(&mutex->death);
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
