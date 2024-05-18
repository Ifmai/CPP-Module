#ifndef ITSTACK_HPP
# define ITSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <vector>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class ITStack : public std::stack<T>
{
	public:
		ITStack() : std::stack<T>(){}
		ITStack(const ITStack &other) : std::stack<T>(other){}
		ITStack &operator=(const ITStack &other){
			std::stack<T>::operator=(other);
			return *this;
		}
		~ITStack(){}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return std::stack<T>::c.begin(); 
		}

		iterator end(){ 
			return std::stack<T>::c.end(); 
		}
};

#endif
