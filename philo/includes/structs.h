/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 16:00:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_time
{
	int				to_eat;
	int				to_sleep;
	int				to_die;
	int				has_eaten;
	long long int	start;
}	t_time;

typedef struct s_mutex
{
	pthread_mutex_t	text;
	pthread_mutex_t	end;
	pthread_mutex_t	eaten;
	pthread_mutex_t	death;
}	t_mutex;

typedef struct s_dinner
{
	int				total;
	int				must_eat;
	long long int	time_of_death;
	int				death;
	t_mutex			mutex;
	t_time			time;
	pthread_mutex_t	fork[201];
}	t_dinner;

typedef struct s_philo
{
	int				index;
	long long int	last_meal;
	int				hand[2];
	t_dinner		*dinner;
}	t_philo;
