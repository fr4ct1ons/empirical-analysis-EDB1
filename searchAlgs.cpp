#include "searchAlgs.h"

//! Search Algorithms

/*!
 * This .cpp file includes the implementation of various search algorithms.
 * Written by fr4ct1ons. Contact: https://twitter.com/fr4ct1ons
 * 
 * Every method here will require three variables, with the jump search algorithm being an exception.
 * searchVal is the pointer of the value to be searched.
 * first is the pointer of the first value in the search range.
 * last is the pointer of the last value in the search range.
 * The return value will be either the pointer of the value equal to searchVal or the pointer of a searchVal itself, indicating the search didn't find the requested value.
*/

//! Iterative Ternary Search
int *myItrTrnSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *t1 = first + ((last - first)/3);
	int *t2 = first + (last - t1);
	while(*first != *last){
		
		if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		
		if(*searchVal >= *first && *searchVal < *t1)
		{
			last = t1 - 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		else if(*searchVal > *t1 && *searchVal < *t2)
		{
			first = t1 + 1;
			last = t2 - 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		else if(*searchVal > *t2 && *searchVal <= *last)
		{
			first = t2 + 1;
			t1 = first + ((last - first)/3);
			t2 = first + ((last - first)/3) * 2;
		}
		else
		{
			return searchVal;
		}
	}

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

//! Iterative Linear Search
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

//! Iterative Binary Search
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


//! Recursive Ternary Search
int *myRecTrnSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *t1 = first + ((last - first)/3);
	int *t2 = first + (last - t1);
	if(*first != *last){
		if(*searchVal == *t1)
		{
			return t1;
		}
		if(*searchVal == *t2)
		{
			return t2;
		}
		
		if(*searchVal >= *first && *searchVal < *t1)
		{
			return myRecTrnSearch(searchVal, first, t1);
		}
		else if(*searchVal > *t1 && *searchVal < *t2)
		{
			return myRecTrnSearch(searchVal, t1 + 1, t2 );
		}
		else if(*searchVal > *t2 && *searchVal <= *last)
		{
			return myRecTrnSearch(searchVal, t2 + 1, last + 1);
		}
		else
		{
			return searchVal;
		}
	}

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

//! Recursive Linear Search
/*!
 * WARNING! This method WILL NOT work with arrays that are too big. It is prone to segfault.
 * Only implemented for testing purposes.
 */
int *myRecLinSearch(int *searchVal, int *first, int *last){
	//std::cout << *first << " " << *last << std::endl;
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

//! Recursive Binary Search
int *myRecBinSearch(int *searchVal, int *first, int *last){
	last = last - 1;
	int *middle = first + ((last - first)/2);	

	if(*searchVal == *middle)
	{
		return middle;
	}

	if(*first != *last)
	{
		if(*searchVal < *middle)
		{
			return myRecBinSearch(searchVal, first, middle);
		}
		else if(*searchVal > *middle)
		{
			return myRecBinSearch(searchVal, middle+1, last+1);
		}

	}
	else
	{
		return searchVal;
	}
}


//! Fibonacci Search
int *myFibSearch(int *searchVal, int *first, int *last){
	int fib1 = 1, fib2 = 1, fib3 = 2;
	int vecSize = std::distance(first, last) - 1;
	int offset = 0, i;

	while(fib3 < vecSize){
		fib1 = fib2;
		fib2 = fib3;
		fib3 = fib3 + fib1;
	}
	
	while(fib3 > 1){

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

	return searchVal;
}

//! Jump Search
/*!
 * Note that unlike other methods, this one takes an extra parameter, which is jumpVal.
 * jumpVal is the size of the steps that the algorithm will make.
 */
int *myJmpSearch(int *searchVal, int *first, int *last, int jumpVal=10){
	last = last - 1;
	int step = jumpVal;
	while(std::distance(first, (first + jumpVal)) < std::distance(first, last)){
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
