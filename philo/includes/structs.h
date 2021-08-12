/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:27:09 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/12 08:27:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_time
{
	int	to_eat;
	int	to_sleep;
	int	to_die;
}	t_time;

typedef struct s_philo
{
	int		total;
	t_time	time;
	int		must_eat;
}	t_philo;
