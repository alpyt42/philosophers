NAME = philo

HEADERS = philo.h

SOURCES = philo.c ft_atoi.c main_init.c print.c get_time.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pthread -g -I .

all :    $(NAME)

$(NAME) : $(OBJECTS)
	${CC} ${CFLAG} -o $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re