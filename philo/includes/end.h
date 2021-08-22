/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:59:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/21 23:50:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_H
# define END_H

#include "philo.h"

bool	anyone_dead(t_philo *philo);
void	*verify_end_conditions(void *philo_ptr);

# endif
