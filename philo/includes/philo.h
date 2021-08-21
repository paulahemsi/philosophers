/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:37:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 20:09:50 by phemsi-a         ###   ########.fr       */
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
#include "colors.h"
#include "structs.h"
#include "error.h"
#include "actions.h"
#include "end.h"
#include "time.h"


bool	init_simulation_fail(t_dinner *dinner);
bool	start_simulation_failed(t_dinner *dinner, t_philo *philo, int i);
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
