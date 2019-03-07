#include "searchAlgs.h"

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
	int *middle = first + ((last-1 - first)/2);
	while(*first != *last){
		
		if(*searchVal < *middle)
		{
			last = middle;
			middle = first + ((last-1 - first)/2);
		}
		else if(*searchVal > *middle)
		{
			first = middle+1;
			middle = first + ((last-1 - first)/2);
		}
		if(*searchVal == *middle)
		{
			return middle;
		}
	}
	return searchVal;
}