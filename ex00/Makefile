SRCS		=		main.cpp \
						utils.cpp

OBJS		= ${SRCS:.cpp=.o}
CC			= c++
CFLAGS	= -Wall -Wextra -Werror
NAME		= $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))
RM			= rm -f

all:		${NAME}

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

run:		
			./${NAME}

.PHONY:		all clean fclean re run