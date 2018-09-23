#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopukh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 12:37:05 by elopukh           #+#    #+#              #
#    Updated: 2018/06/13 12:37:07 by elopukh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
LIB_NAME = libft.a
SRC_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libft/

LFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

C_FILES =	main.c read.c texture.c texture_init.c casting.c game.c sprite_init.c floor.c sprite.c dealkey.c other.c initdata.c \
			read1.c read2.c texture_init1.c

HEADERS = $(INC_DIR)wolf3d.h $(LIB_DIR)libft.h

SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I $(INC_DIR) -I $(LIB_DIR)
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)


$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
				@make -C $(LIB_DIR)
				@$(CC) $(CFLAGS) $(OBJ) $(LFT) $(FRAMEWORKS)  -o $(NAME)
				@printf "$(C_MAGENTA)wolf3d:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR):
				@mkdir obj
				@@printf "$(C_MAGENTA)wolf3d:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
				@$(CC) $(CFLAGS) -c $(INC) $< -o $@
				@@printf "$(C_MAGENTA)wolf3d:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
clean:
				@rm -rf $(OBJ_DIR)*
				@make clean -C $(LIB_DIR)
				@@printf "$(C_MAGENTA)wolf3d:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
				@rm -rf $(NAME)
				@make fclean -C $(LIB_DIR)
				@@printf "$(C_MAGENTA)wolf3d:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all