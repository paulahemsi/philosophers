/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:29:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/22 20:30:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philo.h"

# define ARGS_MIN	5
# define ARGS_MAX	6

# define USAGE			"Usage: ./philo n_philo ms_to_die ms_to_eat ms_to_sleep"
# define NOT_UNINT		"Args must be unsigned integers greater than 0"
# define THREAD_C_ERROR	"Error creating threads"
# define THREAD_J_ERROR	"Error joining threads"

bool	check_errors(int argc, char **argv);
bool	error_msg(char *message);

#endif
