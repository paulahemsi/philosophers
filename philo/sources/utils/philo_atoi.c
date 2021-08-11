/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:08:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 18:31:10 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	philo_atoi(const char *nptr)
{
	double	number;

	number = 0;
	while (ft_isdigit(*nptr))
	{
		number *= 10;
		number += (*nptr - '0');
		nptr++;
	}
	return (number);
}
