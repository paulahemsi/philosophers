/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/11 18:18:57 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "philo.h"

# define USAGE		"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep"
# define NOT_INT	"Args must be unsigned integers"

bool	error(int argc, char **argv);

#endif
