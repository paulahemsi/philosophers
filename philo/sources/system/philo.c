/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:14:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 19:35:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("seconds: %ld\nmicro seconds: %ld\n", current_time.tv_sec, current_time.tv_usec);
}

int	main(int argc, char **argv)
{
	if (error(argc, argv))
		return (EXIT_FAILURE);
	parse_arguments(argc, argv);
	print_time();
	return (0);
}
