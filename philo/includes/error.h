/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 12:34:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "philo.h"

# define ARGS_MIN	5
# define ARGS_MAX	6

# define USAGE			"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep"
# define NOT_UNINT		"Args must be unsigned integers > 0"
# define THREAD_ERROR	"Error creating threads"

bool	error(int argc, char **argv);
bool	error_msg(char *message);

#endif
