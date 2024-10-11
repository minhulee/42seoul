# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 08:20:59 by minhulee          #+#    #+#              #
#    Updated: 2024/10/11 17:03:26 by minhulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME 			= 		ScavTrap
CC 				= 		c++
FLAGS 			= 		-Wall -Werror -Wextra -std=c++98

INCLUDES 		=

SRCS			=		main.cpp		\
						ClapTrap.cpp	\
						ScavTrap.cpp

OBJ				=		$(SRCS:.cpp=.o)

### COLOR CODE ###
NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;
###################

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(CURSIVE)$(YELLOW) "		- Making $(NAME) -" $(NONE)
	@$(CC) $(FLAGS) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) "		- Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "		- Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "		- Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo $(CURSIVE)$(BLUE) "		- clean OBJ files -" $(NONE)

fclean : clean
	@rm -rf $(NAME)
	@echo $(CURSIVE)$(PURPLE)"		- clean $(NAME) file -"$(NONE)

re  :
	@make fclean
	@make all

.PHONY: all make clean fclean re