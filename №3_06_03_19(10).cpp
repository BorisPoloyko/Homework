#include "Array_double.h"
#include "cmath"

using namespace std;


typedef bool(*predicate)(double, double);
typedef bool(*conditionToIncludeOrDelete)(double, int, int);


double* allocateMemory(int);     //functions from header file(just in case)
void inputArray(double*, int);
void displayArray(double*, int);
void randomArray(double*, int);




void sortArray(double*, int, predicate);							//bubble sort (just in case)
double* deleteElements(double*, int&, conditionToIncludeOrDelete);
double* createArray(double*, int, int&, conditionToIncludeOrDelete);
void mergeSort(double*, int, int, predicate);
void merge(double*, int, int, int, predicate);



bool ifNumberOfOnesGreater(double, double);
bool ifNumberFits(double, int, int);
int inputSize();
int numberOnes(double);
int numberZeroes(double);
void swap(double&, double&);
int inputNumberOfOnes();
int inputNumberOfZeroes();




int n = inputSize(), ones = inputNumberOfOnes(), zeroes = inputNumberOfZeroes();

int main()
{
	//Test cases: число 0 - 2, число 1 - 2 --> 7 5 -10 --> 5 -10 7 --> удалены -10--> массив 5 7
	//			  число 0 - 2, число 1 - 2 --> 7 5 9 10--> 5 9 10 7--> удалены 9 10--> массив 5 7
	//	          число 0 - 2, число 1 - 3 --> 25 1 7.4 -5.6 9 5 --> 1 5 9 -5.6 7.4 25 -->удалены 25 --> массив 1 -5.6 9 5 7.4


	int lengthOfNewArray;

	double* array = allocateMemory(n);

	inputArray(array, n);

	displayArray(array, n);

	mergeSort(array, 0, n-1, ifNumberOfOnesGreater);

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


void sortArray(double* array, int n, predicate condition)
{
	for (double *p = array; p < array + n; p++)
	{
		for (double*q = p + 1; q < array + n; q++)
		{
			if (condition(*p, *q))
			{
				swap(*p, *q);
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
	while (abs(b))
	{
		if (abs(b) % 2 == 1)
			count++;
		b /= 2;
	}
	return count;
}

int numberZeroes(double a)
{
	int b = a;
	int count = 0;
	while (abs(b))
	{
		if (abs(b) % 2 == 0)
			count++;
		b /= 2;
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

void merge(double* array, int left, int mid, int right, predicate condition)
{
	int pos1 = left, pos2 = mid + 1, pos3 = 0;

	double *temp = allocateMemory(right - left + 1);

	while (pos1 <= mid && pos2 <= right) 
	{
		if (condition(array[pos2], array[pos1]))
		{
			temp[pos3++] = array[pos1++];
		}
		else
		{
			temp[pos3++] = array[pos2++];
		}
	}

	while (pos2 <= right)
	{
		temp[pos3++] = array[pos2++];
	}
	while (pos1 <= mid)
	{
		temp[pos3++] = array[pos1++];
	}

	for (pos3 = 0; pos3 < right - left + 1; pos3++)
	{
		array[left + pos3] = temp[pos3];
	}

	delete[] temp;
}

void mergeSort(double* array, int left, int right, predicate condition)
{
	int mid;

	if (left < right)
	{
		mid = left + (right-left) / 2;
		mergeSort(array, left, mid, condition);
		mergeSort(array, mid + 1, right, condition);
		merge(array, left, mid, right, condition);
	}
	else
	{
		return;
	}
}

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
