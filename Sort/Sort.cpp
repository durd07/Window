// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;

#define ARRAYNUM 100
#define MAXBIT 1000

int Array[ARRAYNUM] = { 3, 5, 7, 1, 0, 2, 9, 3, 7, 6 };

template <typename DATATYPE>
int CreateRandomArray(DATATYPE Array[], size_t ArrCount)
{	
	if ((NULL == Array) || (0 == ArrCount))
	{
		return -1;
	}

	srand(time(NULL));

	for (size_t i = 0; i < ArrCount; i++)
	{
		Array[i] = rand() % MAXBIT;
	}
	return 0;
}

// insertion sort
template <typename DATATYPE>
int Sort(DATATYPE Array[], size_t ArrCount)
{
	for (size_t i = 1; i < ArrCount; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (Array[j] > Array[j - 1])
			{
				DATATYPE temp = Array[j];
				Array[j] = Array[j - 1];
				Array[j - 1] = temp;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

template <typename DATATYPE>
int TestSort(DATATYPE Array[], size_t ArrCount)
{
	if ((NULL == Array) || (0 == ArrCount))
	{
		return -1;
	}

	for (size_t i = 0; i < ArrCount - 1; i++)
	{
		if (Array[i] < Array[i + 1])
		{
			PrintArray(Array, ARRAYNUM);
			return -1;
		}
	}
//	cout << "OK" << endl;
	return 0;
}

template <typename DATATYPE>
int PrintArray(DATATYPE Array[], size_t ArrCount)
{
	if ((NULL == Array) || (0 == ArrCount))
	{
		return -1;
	}

	for (size_t i = 0; i < ArrCount; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int Array[ARRAYNUM] = { 0 };
	
	for (size_t i = 0; i < 100000; i++)
	{
		CreateRandomArray(Array, ARRAYNUM);
		Sort(Array, ARRAYNUM);
		TestSort(Array, ARRAYNUM);
	}

	return 0;
}

