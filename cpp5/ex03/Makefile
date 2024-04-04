CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
Name = Intern
SRC = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp 

all: $(Name)

$(Name): $(SRC)
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."

fclean: clean
	@rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re