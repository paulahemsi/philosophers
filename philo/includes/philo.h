/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:37:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 10:04:35 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "error.h"
#include "colors.h"
#include "structs.h"
#include "simulation.h"

/*
** parser.c
*/
void	parse_arguments(int argc, char **argv, t_dinner *dinner);

/*
** utils/
*/
int		ft_isdigit(int c);
double	philo_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

#endif
