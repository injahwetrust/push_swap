# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:05:35 by bvaujour          #+#    #+#              #
#    Updated: 2023/02/07 16:05:43 by bvaujour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### INCLUDES ###

INCLUDES	= push_swap.h
INCLUDES_B	= push_swap_bonus.h get_next_line.h

### SOURCES ###

SRC = push_swap.c \
	init.c \
	moves.c \
	moves2.c \
	moves3.c \
	tri.c \
	tri2.c \
	tri3.c \
	tri4.c \
	
SRC_B = checker.c \
	checker_utils.c \
	get_next_line.c \
	get_next_line_utils.c \
	moves_bonus.c \
	moves2_bonus.c \
	moves3_bonus.c \
		
SOURCES		= $(addprefix $(SRCFLDR), $(SRC))
SOURCES_B	= $(addprefix $(SRCFLDR_B), $(SRC_B))

OBJECTS		= $(addprefix $(SRCFLDR), $(OBJS))
OBJECTS_B	= $(addprefix $(SRCFLDR_B), $(OBJS_B))

### FOLDER PATH ###

SRCFLDR = 	sources/
SRCFLDR_B =	sources_bonus/

### MACROS ###

NAME 	= push_swap
NAME_B	= checker

OBJS	= $(SOURCES:.c=.o)
OBJS_B	= $(SOURCES_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

### RULES ###

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(NAME_B): $(OBJS_B) $(INCLUDES_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

all : $(NAME) $(NAME_B)

bonus : $(NAME_B)

.objects/%.o: %.c 
	${CC} ${CFLAGS} -c $<

clean:
	rm $(OBJS) $(OBJS_B)

fclean:
	rm $(OBJS) $(OBJS_B) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
