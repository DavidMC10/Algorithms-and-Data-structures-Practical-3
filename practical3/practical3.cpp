//==============================================================================
// Name        : practical3.cpp
// Author      : David McElhinney
// Version     : 1.0
// Description : practical 3 test program to exercise the simple sort algorithms
//==============================================================================

#include <string>
#include <cstdlib>	// srand
#include <ctime>	// time
#include "Array.h"
#include "Sort.h"

using namespace std;

// PostCondition: array is filled with random numbers 1..range
void fillRandom(Array<int> & data, int range = 100) {
	for (int i = 0; i < data.length(); i++) {
		data[i] = rand() % 100 + 1;
	}
}


// test selection sort
void testSelect() {

	// Create an array of type integer that's 20 long.
	Array<int> a1(20);

	// Pass the array to the fill random function which will populate the array
	// from numbers 0 - 100.
	fillRandom(a1);

	// Prints the unsorted array contents
	std::cout << "Unsorted data: ";
	std::cout << a1 << std::endl;

	// Passes the array to the selection sort function to be sorted.
	selectionSort(a1);

	// Prints the sorted array contents
	std::cout << "Sorted data: ";
	std::cout << a1 << std::endl;


}

// test insertion sort
void testInsert() {

	// Create an array of type integer that's 20 long.
	Array<int> a1(20);

	// Pass the array to the fill random function which will populate the array
	// from numbers 0 - 100.
	fillRandom(a1);

	// Prints the unsorted array contents
	std::cout << "Unsorted data: ";
	std::cout << a1 << std::endl;

	// Passes the array to the selection sort function to be sorted.
	insertionSort(a1);

	// Prints the sorted array contents
	std::cout << "Sorted data: ";
	std::cout << a1 << std::endl;

	// Passes the sorted array to test comparisons and moves
	insertionSort(a1);

	// Prints the sorted array contents
	std::cout << "Sorted data 2: ";
	std::cout << a1 << std::endl;


}


// return difference in the largest and smallest elements in the array  
int maxDiff(const Array<int> & data) {
	
	Array<int> a1(data);
	int min, max;
	min = max = a1[0];
	for (int i{ 0 }; i < a1.length(); i++) {
		if (a1[i] < min) {
			min = a1[i];
		} 
		if (a1[i] > max) {
			max = a1[i];
		}

	}

	return max - min;
}

// Compare performance of selection/insertion sort.
void testBoth() {

	// Create an array of type integer that's 20 long.
	Array<int> a1(10);
	fillRandom(a1);
	Array<int> a2(a1);

	// Prints the unsorted array contents
	std::cout << "---------Selection Sort------------" << std::endl;
	std::cout << "Unsorted data: ";
	std::cout << a1 << std::endl;

	// Passes the array to the selection sort function to be sorted.
	selectionSort(a1);

	// Prints the sorted array contents
	std::cout << "Sorted data: ";
	std::cout << a1 << std::endl << std::endl;

	// Prints the unsorted array contents
	std::cout << "---------Insertion Sort------------" << std::endl;
	std::cout << "Unsorted data: ";
	std::cout << a2 << std::endl;

	// Passes the array to the selection sort function to be sorted.
	insertionSort(a2);

	// Prints the sorted array contents
	std::cout << "Sorted data: ";
	std::cout << a2 << std::endl;
}

// test string sorting
void testString() {

	//Declares a 10 element string array
	Array<std::string> a1(10);

	// Requires the user to enter 10 words
	for (int i{ 0 }; i < a1.length(); i++) {
		std::cout << "Please enter word " << i + 1 << ": " << std::endl;
		cin >> a1[i];
	}

	// Prints the unsorted array contents
	std::cout << "Unsorted strings: ";
	std::cout << a1 << std::endl;

	// Sort the data with insertion sort
	insertionSort(a1);

	// Prints the sorted array contents
	std::cout << "Sorted strings: ";
	std::cout << a1 << std::endl;



}

// Main method.
int main() {

	//initialise the random number generator (used in fillRandom())
	srand((unsigned)time(NULL));

	// call test methods here
	//testSelect();
	//testInsert();

	//for (int i{ 0 }; i < 10; i++) {
	//	testBoth();
	//	std::cout << endl;
	//}
	
	// Array<int> a1(20);

	// Pass the array to the fill random function which will populate the array
	// from numbers 0 - 100.
	//fillRandom(a1);
	//std::cout << a1 << std::endl;
	//std::cout << maxDiff(a1) << std::endl;

	testString();

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}
