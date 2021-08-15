/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 09:52:39 by phemsi-a         ###   ########.fr       */
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
}	t_mutex;

typedef struct s_philo
{
	int				index;
	t_time			time[1];
	pthread_mutex_t	fork[2];
}	t_philo;

typedef struct s_dinner
{
	int				total;
	int				must_eat;
	t_mutex			mutex;
	t_time			time[1];
	t_philo			philo[200];
	pthread_mutex_t	fork[200];
}	t_dinner;
