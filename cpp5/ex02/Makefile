CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror 
Name = AForm
SRC = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp 

all: $(Name)

$(Name): $(SRC)
	@echo "Compiling..."
	@$(CC) $(FLAG) $(SRC) -o $(Name)

clean:
	@echo "Cleaning..."
	@rm -rf $(Name) ShrubberyCreationForm_shrubbery

fclean: clean

re: fclean all

.PHONY: all clean fclean re