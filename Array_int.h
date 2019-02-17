#pragma once
#ifndef _30219_h
#define _30219_h

#include <iostream>

int* allocateMemory(int);
void inputArray(int*, int);
void displayArray(int*, int);
void randomArray(int*, int);

using namespace std;

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}
	int* array = new int[n];
	return array;
}

void inputArray(int* array, int n)
{
	for (int * p = array, i = 1; p < array + n; p++, i++)
	{
		cout << "a [" << i << "] = ";
		cin >> *p;
	}
}

void displayArray(int* array, int n)
{
	for (int * p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}

void randomArray(int* array, int n)
{
	for (int * p = array; p < array + n; p++)
	{
		*p = rand() % 20;
	}
}


#endif /* _30219_h */
