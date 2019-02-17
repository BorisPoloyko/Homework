#include "Array_double.h"

using namespace std;

int inputSize();
int numberOnes(double);
int numberZeroes(double);
void sortByOnes(double*, int);
void swap(double&, double&);
int inputA();
int inputB();
void newArray(double*,double*, int, int, int);
int countNumber(double*,int,int, int);


int main()
{
	int n = inputSize();
	double* array = allocateMemory(n);
	inputArray(array, n);				//functions from header file
	displayArray(array, n);
	sortByOnes(array, n);
	displayArray(array, n);
	int a = inputA(), b = inputB();
	double* new_array = allocateMemory(countNumber(array, n, a, b));
	newArray(array, new_array, n, a, b);
	displayArray(new_array, (countNumber(array, n, a, b)));
	displayArray(array, n);
	system("pause");
	return 0;
}

int inputSize()
{
	int n;
	while (true)
	{
		cout << "Please enter the size of the array, n = ";
		cin >> n;
		if (n > 0)
		{
			return n;
		}
		cout << "Invalid data! Try again, n =  ";
	}
}

int numberOnes(double a)
{
	int b = a;
	int count = 0;
	for (int i = 0; i < sizeof(a) * 8; i++, b >>= 1)
	{
		count += b & 1;
	}
	return count;
}

int numberZeroes(double a)
{
	int b = a;
	int count = 0;
	for (int i = 0; i < sizeof(a) * 8; i++, b >>= 1)
	{
		count += b ^ 1;
	}
	return count;
}

void sortByOnes(double* array, int n)
{
	for (double*p = array; p < array + n; p++)
	{
		for (double*q = p + 1; q < array + n; q++)
		{
			if (numberOnes(*p) > numberOnes(*q))
			{
				swap(*p, *q);
			}
		}
	}
}

void swap(double& a, double&b)
{
	double c = a;
	a = b;
	b = c;
}

int inputA()
{
	int a;
	while (true)
	{
		cout << "Please enter the number of 1 in the number to be deleted, a = ";
		cin >> a;
		if (a >= 0)
		{
			return a;
		}
		cout << "Invalid data! Try again, a =  ";
	}
}

int inputB()
{
	int b;
	while (true)
	{
		cout << "Please enter the number of 0 in the number to be deleted, b = ";
		cin >> b;
		if (b >= 0)
		{
			return b;
		}
		cout << "Invalid data! Try again, a =  ";
	}
}

int countNumber(double* array, int n, int a, int b)
{
	int count = 0;
	for (double *p = array; p < array + n; p++)
	{
		if ((numberOnes(*p) == a) && (numberZeroes(*p) == b))
		{
			count++;
		}
	}
	return count;
}

void newArray(double* array,double* new_array,int n,int a, int b)
{
	double *q = new_array;
	for (double *p = array; p < array + n; p++)
	{
		if ((numberOnes(*p) == a) && (numberZeroes(*p) == b))
		{
			*q = *p;
			q++;
		}
	}
}