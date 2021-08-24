/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:37:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/23 21:30:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "colors.h"
# include "structs.h"
# include "error.h"
# include "actions.h"
# include "end.h"
# include "time.h"

bool	init_simulation(t_dinner *dinner);
bool	start_simulation(t_dinner *dinner, t_philo *philo);
void	*routine(void *philo_ptr);
bool	is_even(int philo);
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
int		ft_strcmp(const char *s1, const char *s2);

#endif
