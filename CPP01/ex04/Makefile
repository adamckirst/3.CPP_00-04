# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 12:00:40 by achien-k          #+#    #+#              #
#    Updated: 2024/08/26 17:12:54y achien-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	SedForLosers
TEST_NAME   =   test_SedForLosers

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INC_DIR		=	include
SRC_DIR		=	src
TEST_DIR	=	tests

SRCS		=	main 
TEST_SRCS   =   test_main test_basic test_empty_file test_empty_s1 test_equal test_non_existent_file test_nos1

OBJ_DIR		=	bin
OBJ			=	$(foreach src, $(SRCS), $(OBJ_DIR)/$(src).o)
TEST_OBJ    =   $(foreach test_src, $(TEST_SRCS), $(OBJ_DIR)/$(test_src).o)

VPATH		=	$(SRC_DIR):$(TEST_DIR)

all: 			$(NAME)

$(OBJ_DIR):		
				@echo "\033[36mCreating file objects...\033[0m"
				@mkdir -p $(OBJ_DIR)

$(NAME):		$(OBJ_DIR) $(OBJ) test_files
				@echo "\033[36mCompiling...\033[0m"
				@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -I$(INC_DIR)
				@echo "\033[1;32m\033[1m$(NAME) is ready to use!\033[0m"

$(OBJ_DIR)/%.o:	%.cpp
				@$(CXX) $(CXXFLAGS) -o $@ -c $< -g

test_files:		
				@echo "\033[36mCreating test files...\033[0m"
				@mkdir -p tests
				@touch tests/test.txt
				@echo -n "aloaloalo alo alDalPaloalololo \nFicheiro teste alocado\n\n\n\nFim" > tests/test.txt
				@touch tests/test_empty.txt 
 

leaks:			$(NAME)
				@echo "\033[36mCompiling with fsanitize...\033[0m"
				@$(CXX) $(CXXFLAGS) -fsanitize=address -o $(NAME) $(OBJ) -I$(INC_DIR)
				@echo "\033[1;32m\033[1m$(NAME) is ready to use!\033[0m"

clean:
				@echo "\033[33mCleaning file objects...\033[0m"
				@find . -type f -name "*.o" -delete
				@[ -d $(OBJ_DIR) ] && rmdir $(OBJ_DIR) || true

fclean:			clean
				@echo "\033[33mCleaning $(NAME) and tests...\033[0m"
				@rm -rf $(NAME) tests

re:				fclean all

.PHONY:			clean fclean re
