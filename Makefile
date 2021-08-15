# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 09:40:14 by cmalt             #+#    #+#              #
#    Updated: 2021/01/29 23:50:36 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CLANG = gcc

INCLUDE = include/

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -lXext -lX11

DIR_MLX = minilibx/

MLX = $(DIR_MLX)libmlx.a

DIR_LIBFT = libft/

LIBFT = -lm $(DIR_LIBFT)libft.a

SRCS =	cub3d.c \
		valied_map/check_line_1.c \
		valied_map/get_line_map.c \
		valied_map/parse_line.c \
		valied_map/parse_map.c \
		valied_map/size_map.c \
		valied_map/utils_map_1.c \
		valied_map/utils_map_2.c \
		valied_map/valied_map.c \
		valied_map/val_map_1.c \
		engine/draw.c \
		engine/draw_utils.c \
		engine/free.c \
		engine/hook.c \
		engine/minimap.c \
		engine/move.c \
		engine/raycasting.c \
		engine/raycast_sprite.c \
		engine/raycast_utils.c \
		engine/screen.c \
		engine/utils1.c \
		engine/window.c \
		engine/zero.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	$(MAKE) -C $(DIR_MLX)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CLANG) -o $@ $^ $(MLX_FLAGS)

%.o: %.c 
	$(CLANG) $(FLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(DIR_LIBFT)
	$(MAKE) clean -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DIR_LIBFT)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re