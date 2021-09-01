/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:41:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/01 19:23:12 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_digits(char **argv, int i, int j)
{
	while (argv[i][++j])
		if (!(ft_isdigit(argv[i][j])))
			return (false);
	return (true);
}

static bool	is_out_of_range(int number)
{
	if (number > INT_MAX || number == 0)
		return (true);
	return (false);
}

static bool	is_unsigned_integer(char **argv, int i)
{
	if (!only_digits(argv, i, -1))
		return (false);
	if (is_out_of_range(philo_atoi(argv[i])))
		return (false);
	return (true);
}

static bool	only_unsigned_integers(int argc, char **argv, int i)
{
	while (++i < argc)
		if (!is_unsigned_integer(argv, i))
			return (false);
	return (true);
}

bool	check_errors(int argc, char **argv)
{
	if (argc < ARGS_MIN || argc > ARGS_MAX)
		return (error_msg(USAGE));
	if (!only_unsigned_integers(argc, argv, 0))
		return (error_msg(NOT_UNINT));
	if (philo_atoi(argv[1]) > 200)
		return (error_msg(PHILO_MAX));
	return (true);
}
