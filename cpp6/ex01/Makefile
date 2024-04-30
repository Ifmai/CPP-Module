CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
NAME = Serializer
SRC = main.cpp Serialization.cpp

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