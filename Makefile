NAME = so_long

GCC = gcc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
MLX = libmlx.a
SRC = $(addprefix sources/, main.c so_long.c player_movement.c ft_itoa.c utils.c error_handler.c) \
		$(addprefix sources/get_next_line/, get_next_line.c get_next_line_utils.c)
#SRC = $(main.c so_long.c)


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	@$(GCC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@$(GCC) $(FLAGS) -c $< -o $@

clean:
	@make -C mlx clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
