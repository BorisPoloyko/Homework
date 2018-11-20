#include <iostream>

using namespace std;

int inputDimension();
void inputArray(int*, int);
void displayArray(int*, int);
void countingSigns(int*, int, int&, int&, int&);
void typeOfSequence(int, int, int, int);
void insertionSort(int*, int);
void binarySearch(int *,int, int);


int main()
{
	int array[32];
	int dimension = inputDimension();
	inputArray(array, dimension);
	int lessThan = 0, greaterThan = 0, equal = 0;
	countingSigns(array, dimension, lessThan, greaterThan, equal);
	typeOfSequence(lessThan, greaterThan, equal, dimension);
	cout << "Enter a number to search: ";
	int element;
	cin >> element;
	binarySearch(array, dimension,element);
	system("pause");
}

int inputDimension()
{
	int dimension;
	cout << "Please enter the dimension of the array <=32: ";
	cin >> dimension;
	while (dimension <= 0 || dimension > 32)
	{
		cout << "Invalid data!" << endl;
		cout << "Please enter the dimension of the array <=32: ";
		cin >> dimension;
	}
	return dimension;
}

void inputArray(int* array, int dimention)
{
	for (int i = 0; i < dimention; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void displayArray(int* array, int dimension)
{
	for (int i = 0; i < dimension; i++)
	{
		cout << "[" << i + 1 << "] = " << array[i] << endl;
	}
}

void countingSigns(int*array, int dimention, int& lessThan, int& greaterThan, int& equal)
{
	for (int i = 0; i < dimention-1; i++)
	{
		if (array[i] < array[i + 1])
		{
			++lessThan;
		}
		else if (array[i] > array[i + 1])
		{
			++greaterThan;
		}
		else if (array[i] == array[i + 1])
		{
			++equal;
		}
		
	}

}

void typeOfSequence(int lessThan, int greaterThan, int equal, int dimension)
{
	if (equal == dimension - 1)
	{
		cout << "All terms of the sequence are equal" << endl;
	}
	else if (lessThan == dimension - 1)
	{
		cout << "The sequence is strictly increasing" << endl;
	}
	else if (greaterThan == dimension - 1)
	{
		cout << "The sequence is strictly decreasing" << endl;
	}
	else if (lessThan + equal == dimension - 1 && equal != dimension - 1 && lessThan != dimension - 1)
	{
		cout << "The sequence is increasing instrictly" << endl;
	}
	else if (greaterThan + equal == dimension - 1 && equal != dimension - 1 && greaterThan != dimension - 1)
	{
		cout << "The sequence is decreasing instrictly" << endl;
	}
	else cout << "The sequence is not ordered" << endl;
}

void insertionSort(int* array,int dimension)
{
	int current, j;
	for (int i = 1; i < dimension; i++)
	{
		current = array[i];
		for (j = i - 1 ; array [j] > current; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = current;
	}
}

void binarySearch(int* array, int dimension,int element)
{
	insertionSort(array, dimension);
	displayArray(array, dimension);
	int i = 0;
	int leftBorder = 0, rightBorder = dimension - 1;
	for (i = 0; ; )
	{
		int middle = (leftBorder + rightBorder) / 2;
		if (array[middle] == element)
		{
			cout << "The element has [" <<middle + 1 << "] position in the array" << endl;
			break;
		}
		else if (element > array[middle])
		{
			leftBorder = middle + 1;
		}
		else if (element < array[middle])
		{
			rightBorder = middle - 1;
		}
		if (leftBorder > rightBorder)
		{
			cout << "No entered number in the array" << endl;
			break;
		}
	}	
}