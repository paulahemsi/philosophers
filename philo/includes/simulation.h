/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:59:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 21:19:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include "philo.h"

#define FORK		"has taken a fork"
#define EATING		"is eating"
#define SLEEPING	"is sleeping"
#define THINKING	"is thinking"
#define DIED		"died"
#define LEFT		0
#define RIGHT		1

void	init_simulation(t_dinner *dinner);
void	start_simulation(t_dinner *dinner, int i);
/*
** time.c
*/
long long int	get_current_time(void);
long long int	get_elapsed_time(long long int start_time);
int				do_action(long long int time_in_ms);
void			delay(int delay_time);
/*
** actions.c
*/
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
void	think(t_philo *philo);
void	print_status(long long int time, int philo_number, pthread_mutex_t *text, char *status, char *color);

# endif
