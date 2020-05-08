# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 05:30:40 by rcourtoi          #+#    #+#              #
#    Updated: 2020/02/22 02:38:55 by rcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= libft.a
SRCS		= ft_memset.c	\
			  ft_bzero.c	\
			  ft_memcpy.c	\
			  ft_memccpy.c	\
			  ft_memmove.c	\
			  ft_memchr.c	\
			  ft_memcmp.c	\
			  ft_memalloc.c	\
			  ft_memdel.c	\
			  ft_strlen.c	\
			  ft_strdup.c	\
			  ft_strcpy.c	\
			  ft_strncpy.c	\
			  ft_strcat.c	\
			  ft_strncat.c	\
			  ft_strlcat.c	\
			  ft_strchr.c	\
			  ft_strrchr.c	\
			  ft_strstr.c	\
			  ft_strnstr.c	\
			  ft_strcmp.c	\
			  ft_strncmp.c	\
			  ft_strnew.c	\
			  ft_strdel.c	\
			  ft_strclr.c	\
			  ft_striter.c	\
			  ft_striteri.c	\
			  ft_strmap.c	\
			  ft_strmapi.c	\
			  ft_strequ.c	\
			  ft_strnequ.c	\
			  ft_strsub.c	\
			  ft_strjoin.c	\
			  ft_strjoin_f.c	\
			  ft_strtrim.c	\
			  ft_strsplit.c	\
			  ft_atoi.c		\
			  ft_itoa.c		\
			  ft_toupper.c	\
			  ft_tolower.c	\
			  ft_isalpha.c	\
			  ft_isdigit.c	\
			  ft_isalnum.c	\
			  ft_isascii.c	\
			  ft_isprint.c	\
			  ft_isspace.c	\
			  ft_putchar.c	\
			  ft_putstr.c	\
			  ft_putendl.c	\
			  ft_putnbr.c	\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_lstnew.c	\
			  ft_lstdelone.c\
			  ft_lstdel.c	\
			  ft_lstadd.c	\
			  ft_lstiter.c	\
			  ft_lstmap.c	\
			  ft_strswap.c	\
			  ft_strrev.c	\
			  ft_tabsort.c	\
			  ft_puttab.c	\
			  ft_strclen.c 	\
			  ft_strjoinfree.c \
			  ft_strjoin2.c	\
			  ft_strretri.c \
			  get_next_line.c
							
FLAGS		= -Wall -Wextra -Werror 
OBJS		= $(SRCS:.c=.o)
INCL		= includes/

all: $(NAME) 

$(NAME): $(OBJS) $(INCL)
		ar rc $(NAME) $(OBJS)
		ranlib	$(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCL) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm	-rf $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re
