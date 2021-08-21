/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:02:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 20:11:31 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

#include "philo.h"

#define FORK		"has taken a fork"
#define EAT			"is eating"
#define SLEEP		"is sleeping"
#define THINK		"is thinking"
#define DIED		"died"
#define END_1		"yey, all the philos eaten"
#define END_2		"times :p nhamy!"
#define LEFT		0
#define RIGHT		1

bool	eat(t_philo *philo);
bool	sleeping(t_philo *philo);
bool	think(t_philo *philo);
bool	print_status(long long time, t_philo *philo, char *status, char *color);
/*
** time.c
*/
long long int	get_current_time(void);
long long int	get_elapsed_time(long long int start_time);
void			do_action(long long int time_in_ms, t_philo *philo);
void			delay(int delay_time);

#endif