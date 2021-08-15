# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 12:32:23 by cmalt             #+#    #+#              #
#    Updated: 2020/05/04 12:32:40 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PART1_1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c

SRC_PART1_2 = ft_strnstr.c ft_strncmp.c ft_atoi.c ft_is.c ft_touporlow.c ft_calloc.c ft_strdup.c

SRC_PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_STANDART = $(SRC_PART1_1) $(SRC_PART1_2) $(SRC_PART2)

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

STANDART_OUT = $(SRC_PART1_1:.c=.o) $(SRC_PART1_2:.c=.o) $(SRC_PART2:.c=.o)

BONUS_OUT = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(BONUS_OUT):
	@gcc $(FLAGS) -c $(SRC_BONUS)

$(STANDART_OUT):
	@gcc $(FLAGS) -c $(SRC_STANDART)

$(NAME): $(STANDART_OUT)
	@ar rcs $(NAME) $(STANDART_OUT)

bonus: $(BONUS_OUT)
	@ar rcs $(NAME) $(BONUS_OUT)

clean:
	@rm -f $(BONUS_OUT) $(STANDART_OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
