# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 12:01:07 by rcourtoi          #+#    #+#              #
#    Updated: 2020/05/22 20:05:05 by rcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH)

INC_DIR = includes
INC_FLAG = -I $(INC_DIR) -lft

OBJ_DIR = obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
HEADER		=	./includes/lemin.h

SRC_DIR = src

SRC = 	main.c parsing.c get_rooms.c solve.c queue.c \
		first_pass_bfs.c \
		paths.c links.c \
		init_find_group.c find_group.c steps.c print_result.c \
		get_links2.c get_links.c free_memory.c depth_bfs.c\
		read_file.c 

all: $(NAME)

$(NAME): obj $(OBJS) $(LIB) $(HEADER)
	echo $(DBG)
	$(CC) $(OBJS) $(CFLAGS) $(INC_FLAG) $(LIB_LINK)  -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) makefile 
	$(CC) $(CFLAGS) -I $(LIB_PATH) -I $(INC_DIR) -c $< -o $@

$(LIB):
	make -C $(LIB_PATH)

obj:
	mkdir -p obj

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)
	rm -Rf obj

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

debug: obj $(OBJS) $(LIB) $(HEADER)
	$(CC) $(CFLAGS) -g $(INC_FLAG) $(LIB_LINK) -o $@ $(OBJS)


.PHONY: all clean fclean re debug
