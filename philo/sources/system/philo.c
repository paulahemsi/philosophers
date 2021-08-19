/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:14:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/18 19:49:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(long long time, int index, pthread_mutex_t *text)
{
	pthread_mutex_lock(text);
	printf("%s%-10lld %-3d %-20s%s\n", H_RED, time, index, DIED, RESET);
	pthread_mutex_unlock(text);
}

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (error(argc, argv))
		return (EXIT_FAILURE);
	ft_memset(&dinner, 0, sizeof(t_dinner));
	parse_arguments(argc, argv, &dinner);
	init_simulation(&dinner);
	while (!dinner.death)
		continue ;
	printf("TIME OF DEATH %lld\n", dinner.time_of_death);
	print_death(dinner.time_of_death, dinner.death, &dinner.mutex.text);
	return (0);
}
