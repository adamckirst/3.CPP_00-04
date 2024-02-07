# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:00:40 by achien-k          #+#    #+#              #
#    Updated: 2024/02/07 13:27:02 by achien-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PhoneBook
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INC_DIR		=	include
SRC_DIR		=	src
SRCS		=	PhoneBook main
OBJ_DIR		=	bin
OBJ			=	$(foreach src, $(SRCS), $(OBJ_DIR)/$(src).o)
VPATH		=	$(SRC_DIR)

all: 			$(NAME)

$(OBJ_DIR):		
				@echo "\033[36mCreating file objects...\033[0m"
				@mkdir $(OBJ_DIR)

$(NAME):		$(OBJ_DIR) $(OBJ) 
				@echo "\033[36mCompiling...\033[0m"
				@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -I$(INC_DIR)
				@echo "\033[1;32m\033[1mPhoneBook is ready to use!\033[0m"

$(OBJ_DIR)/%.o:	%.cpp
				@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
				@echo "\033[33mCleaning file objects...\033[0m"
				@find . -type f -name "*.o" -delete
				@[ -d bin ] && rmdir $(OBJ_DIR) || true

fclean:			clean
				@echo "\033[33mCleaning PhoneBook...\033[0m"
				@rm -rf $(NAME) 

re:				fclean all

.PHONY:			clean fclean re