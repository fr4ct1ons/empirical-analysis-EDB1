#include "searchAlgs.h"
#include <iostream>

int *myTrnSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *t1 = first + ((last - first)/3);
	int *t2 = first + ((last - first)/3) * 2;
	while(*first != *last){
		std::cout << " Start Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
		if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		if(*searchVal == *last)
		{
			return last;
		}
		if(*searchVal == *first)
		{
			return first;
		}
		
		// Verifies if searchVal is in the first third
		if(*searchVal > *first && *searchVal < *t1)
		{
			last = t1 - 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		// Verifies if searchVal is in the middle third
		else if(*searchVal > *t1 && *searchVal < *t2)
		{
			first = t1 + 1;
			last = t2 - 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		// Verifies if searchVal is in the last third
		else if(*searchVal > *t2 && *searchVal < *last)
		{
			first = t2 + 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		// If not in any of the thirds, then the value isn't in the array.
		else
		{
			return searchVal;
		}
		std::cout << " End Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
	}
	if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		if(*searchVal == *last)
		{
			return last;
		}
		if(*searchVal == *first)
		{
			return first;
		}
	return searchVal;
}

int *myLinSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	while(first <= last){
		if(*first == *searchVal)
		{
			return first;
		}
		else
		{
			first = first+1;
		}
	}
	return searchVal;
}

int *myBinSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *middle = first + ((last - first)/2);
	while(*first != *last){
		
		if(*searchVal < *middle)
		{
			last = middle-1;
			middle = first + ((last - first)/2);
		}
		else if(*searchVal > *middle)
		{
			first = middle+1;
			middle = first + ((last - first)/2);
		}
		if(*searchVal == *middle)
		{
			return middle;
		}
	}
	return searchVal;
}