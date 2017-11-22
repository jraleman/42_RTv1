# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:46:05 by jaleman           #+#    #+#              #
#    Updated: 2017/11/21 20:12:11 by ivelutin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libft.a

INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := objs

INCLS   := $(INC_DIR)
SRCS    := ft_putendl.c ft_puterror.c ft_putstr.c ft_memdel.c ft_strcmp.c \
			ft_file_extension.c ft_strequ.c ft_strlen.c ft_strrchr.c get_next_line.c \
			ft_bzero.c ft_strchr.c ft_strclr.c ft_strcpy.c ft_strdup.c ft_strncat.c \
			ft_strnew.c
OBJS    := $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC      := gcc
CFLAGS  += -Wall -Wextra -Werror
LFLAGS  += -I.
AR      := ar rc
RLIB    := ranlib

all:	obj $(NAME)

obj:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] $(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INCLS)

clean:
		@rm -rf $(OBJS) $(OBJ_DIR)
		@echo "[INFO] Objects removed!"

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR)
		@echo "[INFO] Library [$(NAME)] removed!"

re:		fclean all

.PHONY:	all clean fclean re
