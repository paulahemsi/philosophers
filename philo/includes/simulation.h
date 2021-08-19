/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:59:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/18 19:19:57 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include "philo.h"

#define FORK		"has taken a fork"
#define EAT			"is eating"
#define SLEEP		"is sleeping"
#define THINK		"is thinking"
#define DIED		"died"
#define LEFT		0
#define RIGHT		1

void	init_simulation(t_dinner *dinner);
void	start_simulation(t_dinner *dinner, int i);
bool	is_death(t_philo *philo);
/*
** time.c
*/
long long int	get_current_time(void);
long long int	get_elapsed_time(long long int start_time);
void			do_action(long long int time_in_ms, t_philo *philo);
void			delay(int delay_time);
/*
** actions.c
*/
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	think(t_philo *philo);
void	print_status(long long time, t_philo *philo, char *status, char *color);

# endif
