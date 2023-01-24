NAME	=	philo

HEADERS	=	includes/philo.h

SOURCES	=	srcs/philo.c srcs/ft_atoi.c srcs/main_init.c srcs/print.c srcs/get_time.c srcs/check_situation.c srcs/print.c srcs/routine.c

OBJECTS	=	$(SOURCES:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -pthread -g -I .

all	:	$(NAME)

$(NAME)	:	$(OBJECTS)
	${CC}	${CFLAG} -o $@ $^

%.o : %.c	$(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean
	$(MAKE) all

.PHONY: all clean fclean re