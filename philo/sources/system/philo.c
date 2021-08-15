/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:14:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 17:26:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (error(argc, argv))
		return (EXIT_FAILURE);
	ft_memset(&dinner, 0, sizeof(t_dinner));
	parse_arguments(argc, argv, &dinner);
	init_simulation(&dinner);
	while (!dinner.death)
		continue ;
	return (0);
}
