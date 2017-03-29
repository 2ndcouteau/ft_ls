# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 17:26:56 by qrosa             #+#    #+#              #
#    Updated: 2016/01/10 18:47:23 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ft_realloc.c ft_atoi.c ft_bzero.c\
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl_clair.c\
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strnequ.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
ft_file_exists.c ft_nbrlen.c\
get_next_line.c


OBJ=$(SRC:.c=.o)

# Lib - Includes
INCL=includes

# Option - Compilation
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

# Color of Skills
RED=\033[0;31m
BLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[1;32m
NC=\033[0m


all: $(NAME)

$(NAME): $(OBJ)
	@echo "${CYAN}--Compilation LIBFT-SRCS to OBJS = OK ${NC}"
	@echo "${BLUE}--Linking $(NAME)${NC}"
	@echo "${BLUE}--ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${BLUE}--ranlib $(NAME)${NC}"
	@ranlib $(NAME)

%.o : %.c
	@$(CC) -c $^ -o $@ $(CFLAGS) -I $(INCL)

clean:
	@echo "${ORANGE}--Delete Libft Object ${NC}";
	@rm -rf $(OBJ)

fclean: clean
	@echo "${RED}--Delete $(NAME)${NC}"
	@rm -rf $(NAME)

re: fclean all clean
