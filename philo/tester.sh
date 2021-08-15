# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 22:20:02 by lfrasson          #+#    #+#              #
#    Updated: 2021/08/15 18:59:18 by vscabell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME=philo
PATH=./
EXEC=${PATH}${NAME}

GREEN="\033[32m"
YELLOW="\033[0;33m"
RED="\033[0;31m"
BLUE="\033[0;34m"
MUTED="\033[1;30m"
RESET="\033[0m"
BOLD="\033[1m"

FLAG=all
while getopts f:n: flag
do
	case "${flag}" in
		f) FLAG=${OPTARG};;
		n) NUM_TESTS=${OPTARG};;
	esac
done

if [ "$(/bin/uname)" == "Linux" ]; then
	GREP=/bin/grep
else
	GREP=/usr/bin/grep
fi

check_program()
{
	if ! command -v $EXEC &> /dev/null
	then
		echo -en "${RED}${BOLD}\n./checker is not working.\nSo this script will only check the number of operations\n${RESET}"
	fi
}

error()
{
	echo -e "${YELLOW}\n${EXEC} $1$RESET "
	ARG="$1"
	RET=`$EXEC $ARG 2>&1`
	echo -e "$RET"
}

display_loading()
{
	TIME=$1
	echo -e -n "${BLUE}> RUNNING"
	/bin/sleep $TIME &
	PID=$!
	while [[ $? == 0 ]]; do
		echo -e -n "${BLUE}."
		/bin/sleep 0.25
		/bin/ps -p $PID >/dev/null 2>&1
	done
	echo -e "${RESET}"
}

run_philo()
{
	TIME_SLEEP=${@:$#}
	ARG="${@:1:4}"
	echo -e "${YELLOW}\n${EXEC} $ARG$RESET "
	$EXEC $ARG >/dev/null 2>&1&
	PHILO_PID=$!
	display_loading $TIME_SLEEP
	kill -INT $PHILO_PID >/dev/null 2>&1
}

philo_dont_eat()
{
	ARG="${@:1:4}"
	run_philo $@
	if [ "$?" == "0" ]; then
		echo -e "Why are your philosophers still alive? ${RED}✘${RESET}"
	else
		$EXEC $ARG | $GREP "eat" >/dev/null 2>&1
		if [ "$?" == "0" ]; then
			echo -e "With which forks is your philosopher eating? Wrong ${RED}✘${RESET}"
		else
			echo -e "Philosophers didn't eat and died, good job! ${GREEN}✔${RESET}"
		fi
	fi
}

philo_die()
{
	run_philo $@
	if [ "$?" == "0" ]; then
		echo -e "Philosophers are still alive, they shoudn't ${RED}✘${RESET}"
	else
		echo -e "A philosopher died, as it should ${GREEN}✔${RESET}"
	fi
}

philo_dont_die()
{
	TIME=${@:$#}
	run_philo $@
	if [ "$?" == "0" ]; then
		echo -e "Philosophers still alive after $TIME seconds ${GREEN}✔${RESET}"
	else
		echo -e "Oh no, a philosopher died ${RED}✘${RESET}"
	fi
}

press_enter()
{
	echo -e "$RED"
	read -p "Press ENTER to continue"
	echo -e "$RESET"
}

if [ "$FLAG" = "all" ] || [ "$FLAG" = "error" ]; then
	echo -e "\n${BOLD}-------------------- ERROR HANDLING -------------------- ${RESET}"
	echo -e "${GREEN}Check if the program print a error message${RESET}\n"
	echo -e "${BOLD}Incorrect number of arguments${RESET}"
	error ""
	error "2"
	error "2 300"
	error "2 300 200"
	error "2 300 200 100 10 40"
	press_enter

	echo -e "\n${BOLD}Non-numeric parameters${RESET}"
	error "a 800 200 200 7"
	error "5 aaa 200 200 7"
	error "5 800 * 200 7"
	error "5 800 200 -- 7"
	error "5 800 200 200 x"
	press_enter
	echo -e "\n${BOLD}Invalide numbers${RESET}"
	error "-5 800 200 200 7"
	error "5 -800 200 200 7"
	error "5 800 -200 200 7"
	error "5 800 200 -200 7"
	error "5 800 200 200 -7"
	error "0 800 200 200 7"
fi

if [ "$FLAG" = "all" ] || [ "$FLAG" = "run" ]; then
	echo -e "\n${BOLD}-------------------- RUN PHILO -------------------- ${RESET}"

	TIME_DONT_EAT=1
	TIME_DIE=3
	TIME_ALIVE=10

	echo -e "\n${BOLD}Philo should not eat and die${RESET}"
	philo_dont_eat "1 800 200 200 $TIME_DONT_EAT"
	philo_dont_eat "0 100 300 100 $TIME_DONT_EAT"
	press_enter

	echo -e "\n${BOLD}Philo should die${RESET}"
	philo_die "4 310 200 100 $TIME_DIE"
	philo_die "6 200 300 100 $TIME_DIE"
	philo_die "2 100 200 200 $TIME_DIE"
	press_enter

	echo -e "\n${BOLD}Philo should not die${RESET}"
	philo_dont_die "8 300 100 100 $TIME_ALIVE"
	philo_dont_die "5 800 200 200 $TIME_ALIVE"
	philo_dont_die "4 410 200 200 $TIME_ALIVE"
	philo_dont_die "20 510 200 300 $TIME_ALIVE"
fi
