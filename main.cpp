#include<iostream>
#include"searchAlgs.h"

//./a.out (tamanho do array) (valor a buscar)

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

	int *searchRes = myTrnSearch(&value, &testVec[0], &testVec[n]);
	if(&value == searchRes){
		std::cout << "Value not found!" << std::endl;
	}
	else{
		std::cout << "Found " << value << " at array position " << *searchRes << std::endl; 
	}
	
	return 0;
}
