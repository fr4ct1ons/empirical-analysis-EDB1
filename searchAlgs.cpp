#include "searchAlgs.h"
#include <iostream>

int *myItrTrnSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *t1 = first + ((last - first)/3);
	int *t2 = first + (last - t1);
	while(*first != *last){
		//std::cout << " Start Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
		if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		
		// Verifies if searchVal is in the first third
		if(*searchVal >= *first && *searchVal < *t1)
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
		else if(*searchVal > *t2 && *searchVal <= *last)
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
		//std::cout << " End Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
	}

	//std::cout << " End Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
	if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
	return searchVal;
}

int *myItrLinSearch(int *searchVal, int *first, int *last){
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

int *myItrBinSearch(int *searchVal, int *first, int *last){
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



int *myRecTrnSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *t1 = first + ((last - first)/3);
	int *t2 = first + (last - t1);
	if(*first != *last){
		//std::cout << " Start Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
		if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		
		// Verifies if searchVal is in the first third
		if(*searchVal >= *first && *searchVal < *t1)
		{
			return myRecTrnSearch(searchVal, first, t1);
		}
		// Verifies if searchVal is in the middle third
		else if(*searchVal > *t1 && *searchVal < *t2)
		{
			return myRecTrnSearch(searchVal, t1 + 1, t2 );
		}
		// Verifies if searchVal is in the last third
		else if(*searchVal > *t2 && *searchVal <= *last)
		{
			return myRecTrnSearch(searchVal, t2 + 1, last + 1);
		}
		// If not in any of the thirds, then the value isn't in the array.
		else
		{
			return searchVal;
		}
		//std::cout << " End Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
	}

	//std::cout << " End Iteration - First: " << *first << " T1: " << *t1 << " T2: " << *t2 << " Last: " << *last << std::endl;
	if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
	return searchVal;
}

int *myRecLinSearch(int *searchVal, int *first, int *last){
	//last = last - 1;
	std::cout << *first << " " << *last << std::endl;
	if(first != last)
	{
		if(*first == *searchVal)
		{
			return first;
		}
		else
		{
			return myRecLinSearch(searchVal, first + 1, last);
		}
	}
	else
	{	
	return searchVal;
	}
}

int *myRecBinSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *middle = first + ((last - first)/2);
	//std::cout << *first << " " << *middle << " " << *last << std::endl;	

	if(*searchVal == *middle)
	{
		return middle;
	}

	if(*first != *last)
	{
		if(*searchVal < *middle)
		{
			//last = middle-1;
			return myRecBinSearch(searchVal, first, middle);
		}
		else if(*searchVal > *middle)
		{
			//first = middle+1;
			return myRecBinSearch(searchVal, middle+1, last+1);
		}

	}
	else
	{
		return searchVal;
	}
}



int *myFibSearch(int *searchVal, int *first, int *last){
	// Determine the first number that is greater than or equal to the array's size.
	int fib1 = 1, fib2 = 1, fib3 = 2;
	int vecSize = std::distance(first, last) - 1;
	int offset = 0, i;

	while(fib3 < vecSize){
		fib1 = fib2;
		fib2 = fib3;
		fib3 = fib3 + fib1;
	}
	
	while(fib3 > 1){
		//std::cout << fib3 << " " << fib2 << " " << fib1 << std::endl;

		if((offset + fib1) <= vecSize)
			i = (offset + fib1);
		else
			i = vecSize;
		
		if(*searchVal > *(first + i))
		{
			fib3 = fib2;
			fib2 = fib1;
			fib1 = fib3 - fib2;
			offset = i;
		}
		else if(*searchVal < *(first + i))
		{
			fib3 = fib1;
			fib2 = fib2 - fib1;
			fib1 = fib3 - fib2;
			
		}
		else
		{
			return first + i;
		}
	}

	if(*first == *searchVal){
		return first;
	}

	//std::cout << fib3 << " " << fib2 << " " << fib1 << std::endl;
	return searchVal;
}

int *myJmpSearch(int *searchVal, int *first, int *last, int jumpVal){
	last = last - 1;
	int step = jumpVal;
	while(std::distance(first, (first + jumpVal)) < std::distance(first, last)){
		//std::cout << jumpVal << std::endl;
		if(*(first + jumpVal) == *searchVal)
		{
			return first + jumpVal;
		}
		else if(*searchVal > *(first + jumpVal))
		{
			jumpVal += step;
		}
		else if(*searchVal < *(first + jumpVal))
		{
			jumpVal -= step;
			//std::cout << jumpVal << std::endl;
			return myItrLinSearch(searchVal, (first + jumpVal), (first + jumpVal + step));
		}
	}
	
	jumpVal -= step;
	int *buffer = myItrLinSearch(searchVal, (first + jumpVal), last + 1);
	if(searchVal != buffer && *searchVal == *buffer){
		return buffer;
	}
	return searchVal;
}