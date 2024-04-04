#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("Default"){
	cout << "ShrubberyCreationForm Default Constructor Called." << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target_):Form("ShrubberyCreationForm", 145, 137), target(target_){
	cout << "ShrubberyCreationForm Constructor Called." << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):Form("ShrubberyCreationForm", 145, 137), target(copy.target){
	cout << "ShrubberyCreationForm Copy Constructor Called" << endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
	cout << "Form Copy assignment operator called" << endl;
    if(this == &copy)
        return *this;
	this->target = copy.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    cout << "ShrubberyCreationForm Destructor called" << endl;
}

string ShrubberyCreationForm::getTarget()const{
	return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& execute) const{
    if(this->getSignedForm() == true)
        throw Form::SignedFormExeption();
    if(this->getExecGrade() < execute.getGrade())
        throw Form::GradeTooLowException();

    std::ofstream file( this->getName() + "_shrubbery" );
    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;
    file.close();
}