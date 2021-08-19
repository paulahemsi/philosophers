/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/18 19:14:10 by phemsi-a         ###   ########.fr       */
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

typedef struct s_philo
{
	int				index;
	long long int	last_meal;
	long long int	time_of_death;
	t_time			time[1];
	int				hand[2];
	int				*death;
	pthread_mutex_t	*forks;
	t_mutex			*mutex;
}	t_philo;

typedef struct s_dinner
{
	int				total;
	int				must_eat;
	int				death;
	long long int	time_of_death;
	t_mutex			mutex;
	t_time			time[1];
	t_philo			philo[201];
	pthread_mutex_t	fork[201];
}	t_dinner;
