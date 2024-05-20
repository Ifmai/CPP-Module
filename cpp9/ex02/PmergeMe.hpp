#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>

class InvalidArgument : public std::exception {
	public:
		virtual const char* what() const throw();
};

bool			listInValueList(std::list<int> &list, char **argList);
bool			listInValueDeque(std::deque<int> &list, char **argList);
void			printList(std::list<int>::iterator left, std::list<int>::iterator right);
void			printDeque(std::deque<int>::iterator left, std::deque<int>::iterator right);
void			startPmergeMe(std::list<int> &listShort, std::deque<int> &dequeShort);

//list
void			insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right);
std::list<int>	mergeList(std::list<int> &left, std::list<int> &right);
void 			mergeShortList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right);

void			insertionSortDeque(std::deque<int>::iterator left, std::deque<int>::iterator right);
std::deque<int>	mergeDeque(std::deque<int> &left, std::deque<int> &right);
void 			mergeShortDeque(std::deque<int> &list, std::deque<int>::iterator left, std::deque<int>::iterator right);

//deque



/* template<typename Iterator>
void insertionSortTemplate(Iterator left, Iterator right) {
    if (left == right) // Eğer sıralanacak eleman yoksa işlem yapma
        return;
	for(Iterator i = std::next(left); i != right; ++i){
    	Iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

template<typename T>
T mergeTemplate(T &left, T &right){
	T mergeSorted;
	typename T::iterator itLeft = left.begin();
	typename T::iterator itRight = right.begin();

	while(itLeft != left.end() && itRight != right.end()){
		if(*itLeft <= *itRight){
			mergeSorted.push_back(*itLeft);
			itLeft++;
		}
		else{
			mergeSorted.push_back(*itRight);
			itRight++;
		}
	}
	while (itLeft != left.end()) {
		mergeSorted.push_back(*itLeft);
		++itLeft;
	}

    while (itRight != right.end()) {
        mergeSorted.push_back(*itRight);
        ++itRight;
    }
	return mergeSorted;
}


template<typename T, typename Iterator>
void mergeShortTempalte(T &list, Iterator left, Iterator right){
	if (std::distance(left, right) <= 1)
		return;

    if (std::distance(left, right) < 10) {
        insertionSortTemplate(left, right);
        return;
    }

	Iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortTempalte(list, left, mid);
	mergeShortTempalte(list, mid, right);

	T leftMerge(left,mid);
	T rightMerge(mid, right);

	T sorted = mergeTemplate(leftMerge, rightMerge);
	std::copy(sorted.begin(), sorted.end(), left);
} */

#endif