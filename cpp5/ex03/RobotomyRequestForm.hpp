#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <random> 

class RobotomyRequestForm : public Form{
	private:
		string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string target_);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		string getTarget()const;
		void execute(const Bureaucrat& execute) const;
};

#endif
