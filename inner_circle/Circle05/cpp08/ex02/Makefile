# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 14:54:41 by minsepar          #+#    #+#              #
#    Updated: 2024/06/16 05:14:30 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

CXX 		=	c++

NAME		=	exec.out

all:	$(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I. $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

phony: all clean fclean re