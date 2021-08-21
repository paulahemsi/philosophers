/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 17:20:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	*define_variable(int id, t_dinner *dinner)
{
	if (id == 1)
		return (&dinner->total);
	if (id == 2)
		return (&dinner->time.to_die);
	if (id == 3)
		return (&dinner->time.to_eat);
	if (id == 4)
		return (&dinner->time.to_sleep);
	else
		return (&dinner->time.must_eat);
}

static void	assign_value(int id, int value, t_dinner *dinner)
{
	int	*variable;

	variable = define_variable(id, dinner);
	*variable = value;
}

void	parse_arguments(int argc, char **argv, t_dinner *dinner)
{
	int		i;

	i = 0;
	while (++i < argc)
		assign_value(i, (int)philo_atoi(argv[i]), dinner);
}
