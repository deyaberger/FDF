# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2020/06/12 21:49:28 by deyaberge        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

NAME = fdf
MLX = libmlx.a
GNL = gnl.a
PTF = libftprintf.a
LIBF= libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libraries/libft
FT_PRINTF_DIR = ./libraries/ft_printf
MINILIBX_DIR = ./libraries/minilibx_macos
GNL_DIR = ./libraries/GNL

SOURCES = ./sources/main.c\
		  ./sources/ft_trace_line.c\
		  ./sources/ft_check_fdf.c\
		  ./sources/ft_check_fdf2.c\
		  ./sources/ft_print_map.c\
		  ./sources/ft_store.c\
		  ./sources/ft_menu.c\
		  ./sources/ft_key_press.c\
		  ./sources/ft_events.c

OBJ = $(SOURCES:.c=.o)

INCLUDE = ./includes/fdf.h

.PHONY: all clean fclean re norme

all: $(NAME)

LIB = $(FT_PRINTF_DIR)/$(PTF) \
	$(LIB_DIR)/$(LIBF) \
	$(MINILIBX_DIR)/$(MLX)

$(LIB) :
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(LIB) Makefile $(OBJ) $(INCLUDE)
	$(CC) -o $(NAME) -I /usr/local/include $(SOURCES) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB)
	echo "$(COMP_COLOR)   --- FDF Compiled ! ---  $(NO_COLOR)"

clean:
	rm -rf $(OBJ)
	$(MAKE) $@ -C $(LIB_DIR)
	$(MAKE) $@ -C $(FT_PRINTF_DIR)
	$(MAKE) $@ -C $(MINILIBX_DIR)
	echo "$(BIN2_COLOR)   --- Binary deleted ---        $(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	$(MAKE) $@ -C $(LIB_DIR)
	$(MAKE) $@ -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	echo "$(PROG_COLOR)   --- Program FDF deleted ---        $(NO_COLOR)"

re: fclean all
.SILENT: 
