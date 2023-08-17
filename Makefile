# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:43:12 by samusanc          #+#    #+#              #
#    Updated: 2023/06/14 16:06:25 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
F_D = d_formats/ft_format_
FORMATS = $(F_D)char.c \
		  $(F_D)string.c \
		  $(F_D)hex.c \
		  $(F_D)numbers.c \
		  ft_printf.c \

O_FORMATS = $(FORMATS:.c=.o)
all: $(NAME)

$(NAME):$(O_FORMATS)
	ar rcs $(NAME) $(O_FORMATS)
clean:
	rm -f $(O_FORMATS)
fclean:
	rm -f $(O_FORMATS) $(NAME)
re: fclean all

