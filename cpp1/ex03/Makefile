CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
Name = Weapon
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

all: $(Name)

$(Name):
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."
	@rm -rf $(Name)

fclean: clean

re: fclean all

.PHONY: all clean fclean re