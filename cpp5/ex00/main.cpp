#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("Me", 0);
	std::cout << b << std::endl;

	Bureaucrat a("Mike", 151);
	std::cout << a << std::endl;
	a.incrementGrade();

	Bureaucrat d("Sue", 10);
	std::cout << d << std::endl;
	d.incrementGrade();

	Bureaucrat c("Cindy", 149);
	std::cout << c << std::endl;
	c.decrementGrade();

	std::cout << "\nTesting copy assingnment" << std::endl;
	Bureaucrat e("They", 42);
	e = c;
	std::cout << e << std::endl;
	return 0;
}

