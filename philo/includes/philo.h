/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:37:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 23:04:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#include "colors.h"

typedef struct s_time
{
	int	to_eat;
	int	to_sleep;
	int	to_die;
}	t_time;

typedef struct s_philo
{
	int		total;
	t_time	time;
	int		must_eat;
}	t_philo;

#include "simulation.h"
/*
** parser.c
*/
void	parse_arguments(int argc, char **argv, t_philo *philo);

/*
** utils/
*/
int		ft_isdigit(int c);
double	philo_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

#endif
