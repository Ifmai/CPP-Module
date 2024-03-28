#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Bureaucrat{
	private:
		const string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(string name_, int grande_);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		string getName()const;
		int getGrade()const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		void incrementGrade();
		void decrementGrade();

		void setGrade(int value);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);