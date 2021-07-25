NAME = so_long
SRCS = main.c ${shell find "./sources" -name "*.c" && find "./gnl" -name "*.c"}
OBJS = ${SRCS:.c=.o}
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MLX_FALGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = libs/minilibx_mms/

all : ${NAME}

${NAME} : ${OBJS}
		${CC} libmlx.dylib ${SRCS} ${MLX_FALGS} -o ${NAME}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re