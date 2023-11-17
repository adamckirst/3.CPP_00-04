# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:00:40 by achien-k          #+#    #+#              #
#    Updated: 2023/09/28 12:11:49 by achien-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	megaphone
OBJ_DIR		=	bin
OBJ			=	$(foreach src, $(SRCS), $(OBJ_DIR)/$(src).o)

all: 			$(NAME)

$(OBJ_DIR):		
				mkdir $(OBJ_DIR)

$(NAME):		$(OBJ_DIR) $(OBJ) 
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	%.cpp
				$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
				find . -type f -name "*.o" -delete
				[ -d bin ] && rmdir $(OBJ_DIR) || true

fclean:			clean
				rm -rf $(NAME) 

re:				fclean all

.PHONY:			clean fclean re
