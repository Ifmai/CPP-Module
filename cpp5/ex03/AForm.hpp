#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;

class Bureaucrat;

class Form {
	private:
		const string	name;
		bool		 	signedForm;
		int				signedGrade;
		const int		execGrade;

	public:
		Form();
		Form(string name_, int signedGrade_, const int execGrade_);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		virtual ~Form();

		string getName()const;
		bool getSignedForm()const;
		int getSignedGrade()const;
		int getExecGrade()const;
		int setExecGrade(int execGrade);
		int setSignedGrade(int signedGrade);

		void beSigned(Bureaucrat & bureaucrat);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class SignedFormExeption : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		virtual void execute(const Bureaucrat& execute) const =0;
};

std::ostream& operator<<(std::ostream& os, const Form& object);

#endif