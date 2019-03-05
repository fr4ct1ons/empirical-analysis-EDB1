#include<iostream>
#include<cstdlib>

int *myBsearch(int *searchVal, int *first, int *last){
	int *middle = first + ((last - first)/2);
	while(first != last){
		if(*searchVal < *middle)
		{
			last = middle;
			middle = first + ((last - first)/2);
		}
		else if(*searchVal > *middle)
		{
			first = middle;
			middle = first + ((last - first)/2);
		}
		else
		{
			return middle;
		}
	}
	return searchVal;
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int value = atoi(argv[2]);

	int *testVec = NULL;
	testVec = new int[n];

	//std::cout << n;

	for(int i = 0; i < n; i++){
		testVec[i] = i;
		//std::cout << testVec[i] << std::endl;
	}

	int *searchRes = myBsearch(&value, &testVec[0], &testVec[n]);
	if(&value == searchRes){
		std::cout << "Code does not work!" << std::endl;
	}
	else{
		std::cout << "Found " << value << " at array position " << *searchRes << std::endl; 
	}
	
	return 0;
}