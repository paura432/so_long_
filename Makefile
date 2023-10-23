NAME = so_long

MY_SOURCES = so_long.c read.c put_img.c move.c check_move.c check_utils.c parse.c free.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

CC = gcc -Wall -Wextra -Werror #-g3 -fsanitize=address
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(MY_OBJECTS)
	@${MAKE} -C ./Libft
	@${MAKE} -C ./ft_printf
	@${MAKE} -C ./get_next_line
	@${CC} ${MLXFLAGS} ${MY_OBJECTS} ./Libft/libft.a ./ft_printf/libftprintf.a ./get_next_line/libftgetnextline.a -o ${NAME}

all: ${NAME}

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@${MAKE} -C ./Libft fclean
	@${MAKE} -C ./ft_printf fclean
	@${MAKE} -C ./get_next_line fclean
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
