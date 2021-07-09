NAME = so_long
SRCS = ${shell find "." -name "*.c"}
OBJS = ${SRCS:.c=.o}
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MLX_FALGS = -Llibs/mlx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = libs/mlx

all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${FL} ${SRCS} -o ${NAME}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re