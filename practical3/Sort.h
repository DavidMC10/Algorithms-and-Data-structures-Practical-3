/**
* Sort.h
*
* Template based Sort functions
*
* @author  David McElhinney
* @version 2.0
*/
#ifndef SORT_H_
#define SORT_H_

#include "Array.h"

// ------------------------ Sort Algorithm Templates ------------------------

// PostCondition: Array elements are sorted
template <class T>
void selectionSort(Array<T> & elements) {
	int min;
	int numComparisons{ 0 };
	int numMoves{ 0 };

	for (int marker = 0; marker < elements.length() - 1; marker++) {
		min = marker;
		for (int i = marker + 1; i < elements.length(); i++) {
			numComparisons++;
			if (elements[i] < elements[min]) {
				min = i;
			}
		}

		// swap elements at position min and out
		aswap(elements[min], elements[marker]);
		numMoves += 3;
	}

	std::cout << "Selection Sort : Comps: " << numComparisons << " Moves : " << numMoves << std::endl;

}

// PostCondition: collection elements are sorted
template <class T>
void insertionSort(Array<T> & elements) {
	int in, out;
	int numComparisons{ 0 };
	int numMoves{ 0 };

	for (out = 1; out < elements.length(); out++) {

		T temp = elements[out]; numMoves++;

		// find position for temp
		numComparisons++;
		for (in = out; in > 0 && elements[in - 1] >= temp; in--) {
			numComparisons++;  numMoves++;
			elements[in] = elements[in - 1];
		}
		// place temp in new position
		elements[in] = temp;  numMoves++;
	}

	std::cout << "Insertion Sort : Comps: " << numComparisons << " Moves : " << numMoves << std::endl;
}

template <class T>
void aswap(T & a, T & b) {

	// swap elements a and b
	T temp = a;
	a = b;
	b = temp;
}

#endif
