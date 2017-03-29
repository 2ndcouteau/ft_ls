# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2016/01/22 01:12:30 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:=./srcs/main.c\
	./srcs/ft_parse_arguments.c\
	./srcs/ft_get_options.c\
	./srcs/opt_exist_long.c\
	./srcs/opt_exist_letter.c\
	./srcs/opt_is_valid.c\
	./srcs/opt_print_error.c\
	./srcs/opt_save_arg.c\
	./srcs/opt_init_env.c\
	./srcs/opt_free_end.c\
	./srcs/ls_main.c\
	./srcs/ls_check_options.c\
	./srcs/ls_print_error.c\
	./srcs/ls_create_tree.c\
	./srcs/ls_tree_sort_insertion.c\
	./srcs/ls_tree_insert_strcmp.c\
	./srcs/ls_tree_add_elem.c\
	./srcs/ls_recursive_tree.c\
	./srcs/ls_print_tree.c\
	./srcs/ls_print_node_opt.c\
	./srcs/ls_read_dir.c\
	./srcs/ls_print_node_no_opt.c\
	./srcs/ls_print_path.c\
	./srcs/ls_print_tree_sub.c\
	./srcs/ls_free.c\
	./srcs/ls_print_format.c\
	./srcs/ls_print_elem.c\
	./srcs/ls_s_option.c\
	./srcs/l_print.c\
	./srcs/l_print_total.c\
	./srcs/l_print_line.c\
	./srcs/l_init_form.c\
	./srcs/l_check_max.c\
	./srcs/l_typefile.c\
	./srcs/l_right.c\
	./srcs/l_acl_extend.c\
	./srcs/l_nb_links.c\
	./srcs/l_name.c\
	./srcs/l_owner_group.c\
	./srcs/l_size.c\
	./srcs/l_copy_number.c\
	./srcs/l_h_option.c\
	./srcs/l_min_maj.c\
	./srcs/l_time.c

## 	./srcs/ls_create_tree_sub.c

OBJ=$(SRC:.c=.o)

# Lib includes
INC=-I ./includes/
LIBFT=libft/libft.a
LIB=-L ./libft/ -lft

# Options can be changed
CFLAGS+:=-Wall -Wextra -Werror
CC:=gcc
NAME:=ft_ls

# Sweet colors just for swag :)

RED=\033[0;31m
BLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[1;32m
NC=\033[0m

all:$(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
	@echo "${BLUE}--Linking $(NAME)${NC}"
	@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LIB)

%.o: %.c
	@echo "${CYAN}Compiling $^ into $@ ${NC}";
	@$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

clean:
	@make clean -C libft
	@echo "${ORANGE}--Delete ft_ls/libft OBJS OK ${NC}";
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}--Remove $(LIBFT)${NC}"
	@rm -f $(LIBFT)
	@echo "${RED}--Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
