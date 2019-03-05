#include "Array_double.h"

using namespace std;


typedef bool(*predicate)(double, double);
typedef void(*rule)(double&, double&);
typedef bool(*conditionToIncludeOrDelete)(double, int, int);

void sortArray(double*, int , predicate, rule);
double* deleteElements(double*, int&, conditionToIncludeOrDelete);
double* createArray(double*, int, int&, conditionToIncludeOrDelete);


bool ifNumberOfOnesGreater(double, double);
bool ifNumberFits(double,int, int);
int inputSize();
int numberOnes(double);
int numberZeroes(double);
void swap(double&, double&);
int inputNumberOfOnes();
int inputNumberOfZeroes();
int countNumber(double*,int,int, int);

int ones = inputNumberOfOnes(), zeroes = inputNumberOfZeroes();

int main()
{
	int n = inputSize(), lengthOfNewArray;

	double* array = allocateMemory(n);

	inputArray(array, n);
			
	displayArray(array, n);

	sortArray(array, n, ifNumberOfOnesGreater, swap);

	cout << "Sorted array: ";

	displayArray(array, n);
	
	double* new_array = createArray(array, n, lengthOfNewArray, ifNumberFits);

	cout << "Copied elements:";

	displayArray(new_array, lengthOfNewArray);

	cout << "Array without elements that were chosen: ";

	array = deleteElements(array, n, ifNumberFits);

	displayArray(array, n);
	
	system("pause");

	return 0;
}


void sortArray(double* array, int n, predicate condition, rule rule)
{
	for (double *p = array; p < array + n; p++)
	{
		for (double*q = p + 1; q < array + n; q++)
		{
			if (condition(*p, *q))
			{
				rule(*p, *q);
			}
		}
	}
}

double* deleteElements(double* array, int& n, conditionToIncludeOrDelete condition)
{
	int copy = n;
	int length = 0;
	for (double *p = array; p < array + n; p++)
	{
		if (condition(*p, ones, zeroes))
		{
			length++;
		}
	}

	double* new_array = allocateMemory(length);


	for (int i = 0, j = 0; i < copy; i++)
	{
		if (!(condition(array[i], ones, zeroes)))
		{
			new_array[j] = array[i];
			j++;
		}
		else n--;
	}
	return new_array;
}

double* createArray(double* array, int n, int &length, conditionToIncludeOrDelete condition)
{
	length = 0;
	for (int i = 0; i < n; i++)
	{
		if (condition(array[i], ones, zeroes))
		{
			length++;
		}
	}
	double* new_array = allocateMemory(length);

	for (int i = 0, j = 0; i < n; i++)
	{
		if (condition(array[i], ones, zeroes))
		{
			new_array[j] = array[i];
			j++;
		}
	}

	return new_array;
}

bool ifNumberFits(double n, int a, int b)
{
	return (numberOnes(n) == a && numberZeroes(n) == b);
}

bool ifNumberOfOnesGreater(double a, double b)
{
	return (numberOnes(a) > numberOnes(b));
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
	for (int i = 0; i < sizeof(b) * 8; i++, b >>= 1)
	{
		count += b & 1;
	}
	return count;
}

int numberZeroes(double a)
{
	int b = a;
	int count = 0;
	for (int i = 0; i < sizeof(b) * 8; i++, b >>= 1)
	{
		count += b ^ 1;
	}
	return count;
}


void swap(double& a, double&b)
{
	double c = a;
	a = b;
	b = c;
}

int inputNumberOfOnes()
{
	int a;
	while (true)
	{
		cout << "Please enter the number of 1 in the number to be copied, a = ";
		cin >> a;
		if (a >= 0)
		{
			return a;
		}
		cout << "Invalid data! Try again, a =  ";
	}
}

int inputNumberOfZeroes()
{
	int b;
	while (true)
	{
		cout << "Please enter the number of 0 in the number to be copied, b = ";
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



