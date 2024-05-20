#include "PmergeMe.hpp"

void insertionSortDeque(std::deque<int>::iterator left, std::deque<int>::iterator right) {
    if (left == right) // Eğer sıralanacak eleman yoksa işlem yapma
        return;
	for(std::deque<int>::iterator i = std::next(left); i != right; ++i){
    	std::deque<int>::iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

std::deque<int> mergeDeque(std::deque<int> &left, std::deque<int> &right){
	std::deque<int> mergeSorted;
	std::deque<int>::iterator itLeft = left.begin();
	std::deque<int>::iterator itRight = right.begin();

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

void mergeShortDeque(std::deque<int> &list, std::deque<int>::iterator left, std::deque<int>::iterator right){
	 if (std::distance(left, right) <= 1)
        return;

    if (std::distance(left, right) < 10) {
        insertionSortDeque(left, right);
        return;
    }

	std::deque<int>::iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortDeque(list, left, mid);
	mergeShortDeque(list, mid, right);

	std::deque<int> leftMerge(left,mid);
	std::deque<int> rightMerge(mid, right);
	std::deque<int> sorted = mergeDeque(leftMerge, rightMerge);

	std::copy(sorted.begin(), sorted.end(), left);
}