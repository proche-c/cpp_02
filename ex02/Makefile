
SRCS = Fixed.cpp \
	main.cpp

HEADERS	= Fxed.hpp

NAME = fixed02

CC = c++

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.cpp Makefile ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS.cpp=.d}

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

-include ${DEPS}

.PHONY: clean fclean re

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all