# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/07/02 11:57:30 by dberger          ###   ########.fr        #
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

LIB_DIR = ./sources/libft
FT_PRINTF_DIR = ./sources/ft_printf
MINILIBX_DIR = ./sources/minilibx_macos
GNL_DIR = ./sources/GNL

SOURCES = main.c\
		  tracer_segment.c\

SOURCESG = get_next_line.c\

OBJ = $(SOURCES:.c=.o)
OBJG = $(SOURCESG:.c=.o)

INCLUDE = fdf.h

.PHONY: all clean fclean re norme

$(NAME): 
	@(cd $(LIB_DIR) && $(MAKE))
	@cp $(LIB_DIR)/libft.a ./libft.a
	@(cd $(FT_PRINTF_DIR) && $(MAKE))
	@cp $(FT_PRINTF_DIR)/libftprintf.a ./libftprintf.a
	@(cd $(MINILIBX_DIR) && $(MAKE))
	@cp $(MINILIBX_DIR)/libmlx.a ./libmlx.a
	@$(CC) $(FLAGS) -c $(GNL_DIR)/$(SOURCESG)
	@ar rc $(GNL) $(OBJG)
	@$(CC) -o $(NAME) -I /usr/local/include $(SOURCES) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(MLX) $(GNL) $(PTF) $(LIBF)
	@echo "$(COMP_COLOR)   --- Compiled ! ---  $(NO_COLOR)"

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@(cd $(MINILIBX_DIR) && $(MAKE) $@)
	@rm -Rf $(MLX) $(LIBF) $(PTF) $(GNL) $(OBJG)
	@echo "$(BIN2_COLOR)   --- Binary   deleted ---        $(NO_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@(cd $(MINILIBX_DIR) && $(MAKE) clean)
	@echo "$(PROG_COLOR)   --- Program  deleted ---        $(NO_COLOR)"

re: fclean all
