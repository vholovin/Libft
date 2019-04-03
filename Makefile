# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:49:22 by vholovin          #+#    #+#              #
#    Updated: 2017/08/08 16:22:10 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

COM			=	gcc
S_LIB		=	ar rc
FLAGS		=	-Wall -Wextra -Werror
OPTIMA		=	-O3

SRC_DIR		=	./srcs/
INC_DIR		=	./includes/
OBJ_DIR		=	./objs/

SRC_FILES	= 	ft_putchar.c	\
				ft_putchar_fd.c	\
				ft_putstr.c 	\
				ft_putstr_fd.c	\
				ft_putendl.c	\
				ft_putendl_fd.c	\
				ft_putnbr.c		\
				ft_putnbr_fd.c	\
				ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strndup.c	\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c		\
				ft_strlcat.c	\
				ft_strncat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_lerpi.c		\
				ft_atoi.c		\
				ft_atof.c 		\
				ft_atoi_base.c	\
				ft_itoa.c		\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_strsplitlen.c\
				ft_lstnew.c		\
				ft_lstdelone.c	\
				ft_lstdel.c		\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstiter.c	\
				ft_lstmap.c		\
				ft_is_prime.c	\
				ft_swap.c		\
				ft_sqrt.c		\
				ft_power.c		\
				ft_factorial.c	\
				ft_clamp.c		\
				get_next_line.c

INC_FILES 	= 	libft.h 		\
				get_next_line.h


OBJ_FILES 	=	$(SRC_FILES:.c=.o)

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
HDRS 		=	$(addprefix $(INC_DIR), $(INC_FILES))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

GREEN		=	\033[32m
RESET		=	\033[39m
YELLOW		=	\033[33m
RED 		=	\033[31m

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(COM) $(FLAGS) $(OPTIMA) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJS) $(HDRS)
	@$(S_LIB) $(NAME) $(OBJS)
	@ echo "$(GREEN)Attention: $(YELLOW)$(NAME)$(RESET) installed"

clean:
	@rm -rf $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)
	@ echo "$(RED)Attention: $(YELLOW)$(NAME)$(RESET) object removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Attention: $(YELLOW)$(NAME)$(RESET) removed"

re:	fclean all

.PHONY: all clean fclean re
