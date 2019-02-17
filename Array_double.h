#pragma once
#ifndef _30219_h
#define _30219_h

#include <iostream>

double* allocateMemory(int);
void inputArray(double*, int);
void displayArray(double*, int);
void randomArray(double*, int);

using namespace std;

double* allocateMemory(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}
	double* array = new double[n];
	return array;
}

void inputArray(double* array, int n)
{
	for (double * p = array, i = 1; p < array + n; p++, i++)
	{
		cout << "a [" << i << "] = ";
		cin >> *p;
	}
}

void displayArray(double* array, int n)
{
	for (double * p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}

void randomArray(double* array, int n)
{
	for (double * p = array; p < array + n; p++)
	{
		*p = rand() % 20;
	}
}


#endif /* _30219_h */
