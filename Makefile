NAME 		= so_long
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=42
INCLUDES	= -I $(LIBFT) -I $(GNL) -I $(MLX)/include
LIBFT		= libft
LIBFT_A		= $(LIBFT)/libft.a
GNL			= get_next_line
MLX			= MLX42
MLX_A		= $(MLX)/libmlx42.a
EXTRA_FLAGS	= -ldl -lglfw -pthread -lm
SRCS		= src/checker.c src/controller.c src/error.c src/path.c  \
	  		src/so_long.c src/sprites.c $(SRCS_GNL)
SRCS_GNL 	= $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

all: libft mlx $(NAME)

libft:
	make -C $(LIBFT)

mlx:
	make -C $(MLX)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT_A) $(MLX_A) $(INCLUDES) $(EXTRA_FLAGS)-o $(NAME)

clean: 
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT_A)
	$(RM) $(MLX_A)
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re libft mlx