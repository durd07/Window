// CLR_Sort.cpp: 主项目文件。

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;
using namespace System;

#define ARRAYNUM 100
#define MAXBIT 100

int Array[ARRAYNUM] = { 3, 5, 7, 1, 0, 2, 9, 3, 7, 6 };

template <typename DATATYPE>
int CreateRandomArray(DATATYPE Array[], size_t ArrCount) {
	if ((NULL == Array) || (0 == ArrCount))
		return -1;
	srand(time(NULL));
	for (size_t i = 0; i < ArrCount; i++)
	{
		Array[i] = rand() % MAXBIT;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// insertion sort
template <typename DATATYPE>
int Sort(DATATYPE Array[], size_t ArrCount) {
	if ((NULL == Array) || (0 == ArrCount)) 
		return -1;
	for (size_t i = 1; i < ArrCount; i++) {
		size_t j = 0;
		for (j = i; ((j > 0) && (Array[j - 1] > Array[i])); j--)
			Array[j] = Array[j - 1];
		if (j != i) 
			Array[j] = Array[i];
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// merge sort
template <typename DATATYPE>
int MergeArray(DATATYPE array_C[], size_t begin, size_t middle, size_t end) {
	const size_t count_A = middle - begin + 1;
	const size_t count_B = end - middle;
	DATATYPE *array_A = new(DATATYPE[count_A]);
	DATATYPE *array_B = new(DATATYPE[count_B]);
	memcpy(array_A, &array_C[begin], sizeof(DATATYPE)* count_A);
	memcpy(array_B, &array_C[middle + 1], sizeof(DATATYPE)* count_B);

	size_t i = 0, j = 0, k = begin;

	while ((i < count_A) && (j < count_B)) {
		if ((array_A[i] < array_B[j]) || (array_A[i] == array_B[j])) {
			array_C[k] = array_A[i];
			i++;
		}
		else {
			array_C[k] = array_B[j];
			j++;
		}
		k++;
	}
	if (i < count_A) 
		memcpy(&array_C[k], &array_A[i], sizeof(DATATYPE)* (count_A - i));
	else if (j < count_B) 
		memcpy(&array_C[k], &array_B[j], sizeof(DATATYPE)* (count_B - j));
	return 0;
}
//
template <typename DATATYPE>
int Sort(DATATYPE Array[], size_t begin, size_t end)
{
	if (begin < end) {
		int middle = (begin + end) / 2;
		Sort(Array, begin, middle);
		Sort(Array, middle + 1, end);
		MergeArray(Array, begin, middle, end);
	}
	return 0;
}

template <typename DATATYPE>
int TestSort(DATATYPE Array[], size_t ArrCount) {
	if ((NULL == Array) || (0 == ArrCount))
		return -1;
	for (size_t i = 0; i < ArrCount - 1; i++) {
		if (Array[i] > Array[i + 1]) {
			PrintArray(Array, ARRAYNUM);
			return -1;
		}
	}
	//	cout << "OK" << endl;
	return 0;
}

template <typename DATATYPE>
int PrintArray(DATATYPE Array[], size_t ArrCount) {
	if ((NULL == Array) || (0 == ArrCount))
		return -1;
	for (size_t i = 0; i < ArrCount; i++)
		cout << Array[i] << " ";
	cout << endl;
	return 0;
}

int main(array<System::String ^> ^args) {
    Console::WriteLine(L"Hello World");
	
//	for (size_t i = 0; i < 10000; i++) {
		CreateRandomArray(::Array, ARRAYNUM);
		Sort(::Array, 0, ARRAYNUM - 1);
		if (-1 == PrintArray(::Array, ARRAYNUM))
			return -1;
//	}
    return 0;
}


