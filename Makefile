# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:12:09 by anloubie          #+#    #+#              #
#    Updated: 2019/12/04 16:32:51 by anloubie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		Cub3D

# Sources

SRCS_NAME	=	main.c					\
				ft_parse.c				\
				ft_set.c				\
				ft_exit.c				\
				ft_map.c				\
				ft_lst.c				\
				ft_display.c			\
				ft_display_2.c			\
				ft_move.c				\
				ft_textures.c			\
				sprite.c				\

INCS_NAME	=	Cub3D.h

LIB_NAME	=	libft.a

# Directories

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR	=	./includes/
LIB_DIR		=	./libft/

# Files

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
INCS		=	$(addprefix $(INCS_DIR), $(INCS_NAME))
LIB			=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# Compilation

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -I $(INCS_DIR)
LIBH		=	-I $(LIB_DIR)includes/
MLX_FLAGS	=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIB):
	@make -j -sC $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(MLX_FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[32;01m[Cub3D OK]\033[00m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(LIBH) -o $@ -c $<

librm:
	@make -sC libft fclean

clean:
	@rm -rf $(OBJS_DIR)
	@make -C libft clean

fclean: librm clean
	@rm -f $(NAME)
	@echo "\033[32;01m[Cub3D fclean OK]\033[00m"

re: fclean all

.PHONY: all librm clean fclean re
