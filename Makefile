# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:17:58 by wangthea          #+#    #+#              #
#    Updated: 2023/03/21 20:13:09 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--variables-------------------------------------------------------------------#

NAME		=	philo
DEBUG		=	no

#--includes & libraries--------------------------------------------------------#

INC_DIR		=	includes/
HEADERS		= 	includes/philo.h

#--sources & objects-----------------------------------------------------------#

SRC_DIR		=	srcs/
OBJ_DIR		=	.objects

#--flags-----------------------------------------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror -I $(INC_DIR)
DFLAGS		=	-g3 #-fsanitize=address
THREADS_F 	=	-pthread

#--Sources-----------------------------------------------------------------------#

SOURCES =	srcs/main.c \
			srcs/parse.c \
			srcs/utils.c \

#--debug & define flags--------------------------------------------------------#

ifeq ($(DEBUG), yes)
CFLAGS 		+=	$(DFLAGS)
endif

#--objects---------------------------------------------------------------------#

OBJECTS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#--global rules----------------------------------------------------------------#

.DEFAULT_GOAL = all

#--compilation rules-----------------------------------------------------------#

all: 
	$(MAKE) $(NAME)

$(NAME): $(OBJECTS)
	@echo "\n\033[0;32mCompiling philo...\033[0m"
	$(CC) $^ $(CFLAGS) $(THREADS_F) -o $@
	@echo "\n\033[0;32mPhilo is up to date !\033[0m"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(THREADS_F) -c $< -o $@

#--libs, debugs & bonus--------------------------------------------------------#

debug:
	$(MAKE) re DEBUG=yes

#--re, clean & fclean----------------------------------------------------------#

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	@echo "\033[0;31mCleaning libft..."
	@echo "\nRemoving binaries..."
	@$(RM) -rf $(OBJECTS)
	@echo "\033[0m"

fclean:
	@echo "\nDeleting objects..."
	@$(MAKE) clean
	@echo "\033[0;31mCleaning libft..."
	@$(MAKE) -C fclean
	@echo "\nDeleting executable..."
	@$(RM) $(NAME)
	@echo "\033[0m"

#--PHONY-----------------------------------------------------------------------#

.PHONY: all debug re clean fclean