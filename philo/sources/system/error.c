/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:41:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 18:32:00 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	error_msg(char *message)
{
	printf("%s\n", message);
	return (true);
}

static bool	is_unsigned_integer(char **argv, int i)
{
	int		j;
	double	number;

	j = 0;
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
			return (false);
		j++;
	}
	number = philo_atoi(argv[i]);
	if (number > INT_MAX)
		return (false);
	return (true);
}

static bool	only_unsigned_integers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_unsigned_integer(argv, i))
			return (false);
		i++;
	}
	return (true);
}

bool	error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg(USAGE));
	if (!only_unsigned_integers(argc, argv))
		return (error_msg(NOT_INT));
	return (false);
}