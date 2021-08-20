/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/19 21:40:58 by phemsi-a         ###   ########.fr       */
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
	t_time			time;
	int				hand[2];
	long long int	*time_of_death;
	int				*death;
	pthread_mutex_t	*forks;
	t_mutex			*mutex;
}	t_philo;

typedef struct s_dinner
{
	int				total;
	int				must_eat;
	long long int	time_of_death;
	int				death;
	t_mutex			mutex;
	t_time			time;
	t_philo			philo[201];
	pthread_mutex_t	fork[201];
}	t_dinner;
