/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:50:41 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/15 19:15:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*
** TEXT
*/

/*
** regular
*/
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define CYAN "\e[0;36m"
#define MAGENTA "\e[0;35m"
#define YELLOW "\e[0;33m"
#define BLACK "\e[0;30m"
#define WHITE "\e[0;37m"
/*
** bold
*/
#define BOLD_RED "\e[1;31m"
#define BOLD_GREEN "\e[1;32m"
#define BOLD_BLUE "\e[1;34m"
#define BOLD_CYAN "\e[1;36m"
#define BOLD_MAGENTA "\e[1;35m"
#define BOLD_YELLOW "\e[1;33m"
#define BOLD_BLACK "\e[1;30m"
#define BOLD_WHITE "\e[1;37m"
/*
** underline
*/
#define UNDER_RED "\e[4;31m"
#define UNDER_GREEN "\e[4;32m"
#define UNDER_BLUE "\e[4;34m"
#define UNDER_CYAN "\e[4;36m"
#define UNDER_MAGENTA "\e[4;35m"
#define UNDER_YELLOW "\e[4;33m"
#define UNDER_BLACK "\e[4;30m"
#define UNDER_WHITE "\e[4;37m"
/*
** High intensty
*/
#define H_RED "\e[0;91m"
#define H_GREEN "\e[0;92m"
#define H_BLUE "\e[0;94m"
#define H_CYAN "\e[0;96m"
#define H_MAGENTA "\e[0;95m"
#define H_YELLOW "\e[0;93m"
#define H_BLACK "\e[0;90m"
#define H_WHITE "\e[0;97m"
/*
** Bold high intensity
*/
#define BOLD_H_BLACK "\e[1;90m"
#define BOLD_H_RED "\e[1;91m"
#define BOLD_H_GREEN "\e[1;92m"
#define BOLD_H_YELLOW "\e[1;93m"
#define BOLD_H_BLUE "\e[1;94m"
#define BOLD_H_MAGENTA "\e[1;95m"
#define BOLD_H_CYAN "\e[1;96m"
#define BOLD_H_WHITE "\e[1;97m"

/*
** BACKGROUND
*/

/*
** Regular
*/
#define RED_BACK "\e[41m"
#define GREEN_BACK "\e[42m"
#define BLUE_BACK "\e[44m"
#define CYAN_BACK "\e[46m"
#define MAGENTA_BACK "\e[45m"
#define YELLOW_BACK "\e[43m"
#define BLACK_BACK "\e[40m"
#define WHITE_BACK "\e[47m"
/*
** High intensty
*/
#define H_RED_BACK "\e[0;101m"
#define H_GREEN_BACK "\e[0;102m"
#define H_BLUE_BACK "\e[0;104m"
#define H_CYAN_BACK "\e[0;106m"
#define H_MAGENTA_BACK "\e[0;105m"
#define H_YELLOW_BACK "\e[0;103m"
#define H_BLACK_BACK "\e[0;100m"
#define H_WHITE_BACK "\e[0;107m"

/*
** RESET
*/
#define RESET_COLOR "\e[0m"

#endif
