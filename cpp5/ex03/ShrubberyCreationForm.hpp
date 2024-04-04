#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form{
	private:
		string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string target_);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		string getTarget()const;
		void execute(const Bureaucrat& execute) const;
};

#endif 
