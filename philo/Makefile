# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 08:29:57 by phemsi-a          #+#    #+#              #
#    Updated: 2021/08/11 18:18:05 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADERS = -I includes

DIR_SRCS = sources

DIR_OBJS = objects

DIRS = system utils

SRC = $(wildcard $(DIR_SRCS)/*.c)

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))

SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))

OBJS = $(subst $(DIR_SRCS),$(DIR_OBJS),$(SOURCES:.c=.o))

CC	= clang

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g $(HEADERS)

PTHREAD = -pthread

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(NAME): $(OBJS)
		@-$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) $(HEADER) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p objects
		@mkdir -p objects/system
		@mkdir -p objects/utils
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
		@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
		$(RM) $(OBJS)
		$(RM) $(DIR_OBJS)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(DIR_OBJS)

re:		fclean all

PHONY:	all clean fclean re