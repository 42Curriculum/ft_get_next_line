# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 12:15:44 by jjosephi          #+#    #+#              #
#    Updated: 2019/09/26 13:50:07 by jjosephi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gud
SECOND = old

all :
	gcc -Wall -Wextra -Werror get_next_line.c next_line_test.c get_next_line.h libft/libft.a
