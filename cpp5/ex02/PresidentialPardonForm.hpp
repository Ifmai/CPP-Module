#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form{
	private:
		string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string target_);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		string getTarget()const;
		void execute(const Bureaucrat& execute) const;
};

#endif