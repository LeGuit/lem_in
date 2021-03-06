# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:51:30 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/23 10:25:11 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For mem : @ before a commande hide the echo of the command

CC =		clang
FLAGS =		-Wall -Werror -Wextra -O2
NAME =		lem-in
INCLS =		-I./includes -I./libft/includes 
LIBFT = 	-L./libft -lft

SRCS_DIR =	srcs
OBJS_DIR =	objs

LIBS =	libft/libft.a

LIST =	main \
		parse/check_line \
		parse/coments \
		parse/parse_file \
		parse/save_lines \
		error/error_input \
		error/error_path \
		find_path/path_finding \
		find_path/bfs \
		find_path/ffa \
		find_path/init_bfs \
		find_path/save_path \
		misc/debug_print \
		misc/print \
		ants_management/ant_start

SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(LIST)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIST)))

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
