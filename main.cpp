#include<iostream>
#include"searchAlgs.h"
#include<chrono>

//./a.out (tamanho do array) (valor a buscar) (tipo de busca {"bin", "lin", "jmp", trn"})

int main(int argc, char const *argv[])
{

	int n; // Array size
	int value; // Value to search for
	std::string searchToUse; // Search algorithm to be used
	int *testVec = NULL; // Array index 0

	if(argc >= 4)
	{
		n = atoi(argv[1]);
		value = atoi(argv[2]);
		searchToUse = argv[3];
		testVec = new int[n];
	}
	else
	{
		std::cout << "Welcome to the implementation of multiple search algorithms." << std::endl
				  << "Please, insert the size of the array you want to use." << std::endl
				  << "The array will have each value equal to its index. i[0] = 0; i[1] = 1 and so on." << std::endl;
		std::cin >> n;
		testVec = new int[n];

		std::cout << "Now, insert the value you want to search for." << std::endl;
		std::cin >> value;
		
		std::cout << "At last, insert the search algorithm you want to use." << std::endl;
		std::cout << "bin = binary search; lin = linear search; jmp = jump search; trn = ternary search." << std::endl;
		std::cin >> searchToUse;

		std::cout << "Thank you for inserting the values as requested." << std::endl;
	}


	std::cout << "Generating array with size " << n << "..." << std::endl;
	for(int i = 0; i < n; i++){
		testVec[i] = i;
		//std::cout << testVec[i] << std::endl;
	}

	int *searchRes;
	std::chrono::nanoseconds methodExecDuration;

	if(searchToUse == "bin")
	{
		std::cout << "Starting binary search. Looking for value " << value << " in an array with size " << n << "." << std::endl;
		auto startTime = std::chrono::high_resolution_clock::now();
		searchRes = myBinSearch(&value, &testVec[0], &testVec[n]);
		auto stopTime = std::chrono::high_resolution_clock::now();
		methodExecDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
	}
	else if(searchToUse == "lin")
	{
		std::cout << "Starting linear search. Looking for value " << value << " in an array with size " << n << "." << std::endl;
		auto startTime = std::chrono::high_resolution_clock::now();
		searchRes = myLinSearch(&value, &testVec[0], &testVec[n]);
		auto stopTime = std::chrono::high_resolution_clock::now();
		methodExecDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
	}
	else if(searchToUse == "trn")
	{
		std::cout << "Starting ternary search. Looking for value " << value << " in an array with size " << n << "." << std::endl;
		auto startTime = std::chrono::high_resolution_clock::now();
		searchRes = myTrnSearch(&value, &testVec[0], &testVec[n]);
		auto stopTime = std::chrono::high_resolution_clock::now();
		methodExecDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
	}
	else if(searchToUse == "jmp")
	{
		std::cout << "Starting jump search. Looking for value " << value << " in an array with size " << n << "." << std::endl;
		auto startTime = std::chrono::high_resolution_clock::now();
		searchRes = myJmpSearch(&value, &testVec[0], &testVec[n]);
		auto stopTime = std::chrono::high_resolution_clock::now();
		methodExecDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime);
	}
	
	if(&value == searchRes){
		std::cout << "Value not found!" << std::endl;
	}
	else{
		std::cout << "Found " << value << " at array position " << *searchRes << std::endl; 
	}

	std::cout << "Method exection time: " << methodExecDuration.count() << " nanoseconds" << std::endl;
	
	return 0;
}
