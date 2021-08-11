/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:36:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 20:42:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	*define_variable(int i, t_philo *philo)
{
	if (i == 1)
		return (&philo->total);
	if (i == 2)
		return (&philo->time.to_die);
	if (i == 3)
		return (&philo->time.to_eat);
	if (i == 4)
		return (&philo->time.to_sleep);
	else
		return (&philo->must_eat);
}

static void	assign_value(int i, int value, t_philo *philo)
{
	int	*variable;

	variable = define_variable(i, philo);
	*variable = value;
}

void	parse_arguments(int argc, char **argv)
{
	int		i;
	t_philo	philo;

	i = 0;
	ft_memset(&philo, 0, sizeof(t_philo));
	while (++i < argc)
		assign_value(i, (int)philo_atoi(argv[i]), &philo);
}
