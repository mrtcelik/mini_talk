# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 11:18:07 by mucelik           #+#    #+#              #
#    Updated: 2023/07/09 12:24:57 by mucelik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server
NAMECLIENT = client
NAME = utils.c
SRCSERVER = server.c
SRCCLIENT = client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJNAME = $(NAME:.c=.o)

all:  $(NAMESERVER) $(NAMECLIENT)

$(NAME) : all

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(NAME)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(NAME)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT)

norm:
	norminette *.[ch]

re: fclean all 
	

.PHONY : re fclean clean all  norm