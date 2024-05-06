NAME = so_long

MY_SOURCES = so_long.c read.c put_img.c move.c check_move.c check_utils.c parse.c free.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

CC = gcc -Wall -Wextra -Werror #-g3 -fsanitize=address
MLXFLAGS = -lX11 -lXext -lm
$(NAME): $(MY_OBJECTS)
	@${MAKE} -C ./libft
	@${MAKE} -C ./ft_printf
	@${MAKE} -C ./get_next_line
	@${CC} ${CFLAGS} ${MY_OBJECTS} -L./mlx_linux -lmlx -lXext -lX11 -lm ./libft/libft.a ./ft_printf/libftprintf.a ./get_next_line/libftgetnextline.a -o $(NAME)


all: ${NAME}

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./ft_printf fclean
	@${MAKE} -C ./get_next_line fclean
	@rm -f $(MY_OBJECTS) $(NAME)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
