#include "Array_int.h"

using namespace std;

int hex(int);
int inputSize();
void sortByHex(int*, int);
void swap(int&, int&);
void pushLeft(int*, int, int);
void deleteRepeats(int*, int, int&);
char inputSymbol();
int numberOfElements(int*, int, char);
bool hasElement(int,char);
void deleteAndInsert(int*, int*, int&, char);

int main()
{
	int n = inputSize();
	int* array = allocateMemory(n);
	inputArray(array, n);				//functions from header file
	displayArray(array, n);
	sortByHex(array, n);
	displayArray(array, n);
	int newLen = n;
	deleteRepeats(array, n, newLen);
	displayArray(array, newLen);
	char a = inputSymbol();
	int elements = numberOfElements(array, newLen, a);
	int* new_array = allocateMemory(elements);
	deleteAndInsert(array, new_array, newLen, a);
	
	displayArray(new_array, elements);
	displayArray(array, newLen);

	system("pause");
}

int hex(int a)
{
	while (a > 15)
	{
		a >>= 4;
	}
	return a;
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
		cout << "Invalid data! Try again";
	}
}

void sortByHex(int* array, int n)
{
	for (int*p = array; p < array + n; p++)
	{
		for (int*q = p + 1; q < array + n; q++)
		{
			if (hex(*p) > hex(*q))
			{
				swap(*p, *q);
			}

		}
	}
}

void swap(int& a, int&b)
{
	int c = a;
	a = b;
	b = c;
}

void pushLeft(int* array, int n, int start)
{
	for (int i = start; i < n - 1; i++)
	{
		swap(array[i], array[i + 1]);
	}
}

void deleteRepeats(int* array, int n, int& newL)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - k; j++)
		{
			if (array[i]==array[j])
			{
				pushLeft(array, n, j);
				newL--;
				k++;
				j--;
			}
		}
	}
}

char inputSymbol()
{
	char sym;
	while (true)
	{
		cout << "Please enter one of the followng A, B, C, D, E or F : ";
		cin >> sym;
		if (sym >= 'A' && sym <= 'F')
		{
			return sym;
		}
		cout << "Invalid data! Try again" << endl;
	}
}

int numberOfElements(int* array, int n, char a)
{
	int count = 0;
	for (int* p = array; p < array + n; p++)
	{
		if (hasElement(*p, a))
		{
			count++;
		}
	}
	return count;
}

bool hasElement(int x, char a)
{
	while (x)
	{
		if (x % 16 == (int(a)-55))
		{
			return true;
		}
		x /= 16;
	}
	return false;
}

void deleteAndInsert(int*array, int* new_array, int& n, char a)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (hasElement(array[i], a))
		{
			new_array[j] = array[i];
			j++;
			pushLeft(array, n, i);
			n--;
			i--;
		}
	}
}

