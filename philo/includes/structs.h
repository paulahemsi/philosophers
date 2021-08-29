/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/29 08:41:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

typedef struct s_time
{
	long long int	start;
	int				to_eat;
	int				to_sleep;
	int				to_die;
	int				must_eat;
}	t_time;

typedef struct s_mutex
{
	pthread_mutex_t	text;
	pthread_mutex_t	death;
	pthread_mutex_t	eat;
	pthread_mutex_t	fork[202];
}	t_mutex;

typedef struct s_dinner
{
	int				total;
	int				end;
	int				satisfied_philos;
	long long int	time_of_death;
	t_mutex			mutex;
	t_time			time;
}	t_dinner;

typedef struct s_philo
{
	int				index;
	long long int	last_meal;
	int				eaten_times;
	int				hand[2];
	t_dinner		*dinner;
}	t_philo;

#endif
