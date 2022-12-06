# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by krochefo          #+#    #+#              #
#    Updated: 2022/12/01 12:05:34 by krochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


SRCS_FILES= philosopher.c philosopher_utils.c philosopher_parse.c \
				philosopher_assignments.c philosopher_init.c

SRCS_PATH = ./
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

AR = ar rcs
CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
	@echo "\033[32m          (.)~(.)         \033[0m" 
	@echo "\033[32m         (-------)        \033[0m"                         
	@echo "\033[31m -------\033[32mooO\033[31m-----\033[32mOoo\033[31m-------\033[0m"
	@echo "\033[0m     ▌               ▌    \033[0m" 
	@echo "\033[0m     ▌  Philosopher  ▌      \033[0m"   
	@echo "\033[0m   ▗▗▙▖            ▗▗▙▖      \033[0m"  
	@echo "\033[0m   ▌ ▌ ▌           ▌ ▌ ▌    \033[0m"            
	@echo "\033[31m -------------------------\033[0m"                                

$(NAME):
	@$(CC) -pthread $(SRCS) $(CFLAGS) -o philo

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

