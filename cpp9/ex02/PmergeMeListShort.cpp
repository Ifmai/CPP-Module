#include "PmergeMe.hpp"

void insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right) {
    if (left == right) // Eğer sıralanacak eleman yoksa işlem yapma
        return;
	for(std::list<int>::iterator i = std::next(left); i != right; ++i){
    	std::list<int>::iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

std::list<int> mergeList(std::list<int> &left, std::list<int> &right){
	std::list<int> mergeSorted;
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();

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

void mergeShortList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right){
	 if (std::distance(left, right) <= 1)
        return;

    if (std::distance(left, right) < 10) {
        insertionSortList(left, right);
        return;
    }

	std::list<int>::iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortList(list, left, mid);
	mergeShortList(list, mid, right);

	std::list<int> leftMerge(left,mid);
	std::list<int> rightMerge(mid, right);
	std::list<int> sorted = mergeList(leftMerge, rightMerge);

	std::copy(sorted.begin(), sorted.end(), left);
}