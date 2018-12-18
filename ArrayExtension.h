#pragma once
#include<iostream>
using namespace std;
const int M = 100;
void inputArray(int* , int);
void displayArray(int*, int;
void swap(int&, int&);
void initMatrix(int[][M], int, int);
void initZeroMatrix(int[][M], int, int);
void displayMatrix(int[][M], int, int);
void transpose(int[][M], int);
void pushRightArray(int*, int, int);

void inputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void displayArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void initZeroMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{


			a[i][j] = 0;
		}
	}
}
void initMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i + 1 << "," << j + 1 << "] = ";
			cin >> a[i][j];
			a[i][j] = i + 1;
		}
	}
}

void displayMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void transpose(int a[][M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void swap(int[], int[], int);
void bubbleSort(int[][M], int*, int, int);
void createKeys(int[][M], int, int, int*);
int findMax(int*, int);
void createKeys(int a[][M], int n, int m, int* keys)
{
	for (int i = 0; i < n; i++)
	{
		/*int k = 0;
		for (int j = 0; j < m; j++)
		{
		if (a[i][j] > a[i][k])
		{
		k = j;
		}
		}
		keys[i] = a[i][k];
		*/
		keys[i] = findMax(a[i], m);
	}
}
int findMax(int* matrixay, int n)
{
	int k = 0;
	for (int j = 1; j < n; j++)
	{
		if (matrixay[j] > matrixay[k])
		{
			k = j;
		}
	}
	return matrixay[k];
}
void bubbleSort(int matrix[][M], int* keys, int n, int m)
{
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				/*for (int k = 0; k < m; k++)
				{
				swap(matrix[j][k], matrix[j - 1][k]);
				}*/
				swap(matrix[j], matrix[j - 1], m);
				swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}
		i++;
	}
}
void swap(int left[], int right[], int n)
{
	for (int i = 0; i < n; i++)
	{
		swap(left[i], right[i]);
	}
}
void pushRightArray(int* a,int pos, int length)
{
	int end[100];
	int temp[100];
	while (pos > length)
	{
		pos -= length;
	}

	for (int i = length - pos, j = 0; i < length; i++, j++)
	{
		end[j] = a[i];
	
	}

	
	for (int j = 0; j < length - pos; j++)
	{
		temp[j] = a[j];
	}
	for (int i = pos, j = 0; i < length ; i++, j++)
	{
	
		a[i] = temp[j];
	}
	for (int i = 0, j = 0; i < pos; i++, j++)
	{
		a[i] = end[j];
	}

}
