/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 21:42:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	*define_variable(int id, t_philo *philo)
{
	if (id == 1)
		return (&philo->total);
	if (id == 2)
		return (&philo->time.to_die);
	if (id == 3)
		return (&philo->time.to_eat);
	if (id == 4)
		return (&philo->time.to_sleep);
	else
		return (&philo->must_eat);
}

static void	assign_value(int id, int value, t_philo *philo)
{
	int	*variable;

	variable = define_variable(id, philo);
	*variable = value;
}

void	parse_arguments(int argc, char **argv, t_philo *philo)
{
	int		i;

	i = 0;
	while (++i < argc)
		assign_value(i, (int)philo_atoi(argv[i]), philo);
}
