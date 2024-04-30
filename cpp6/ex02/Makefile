CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
NAME = Type
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp identify.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	@echo "Cleaning..."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re