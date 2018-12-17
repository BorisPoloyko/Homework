#include <iostream>
#include "ArrayExtension.h"

using namespace std;

void inputSize(int&, int&);
void columnsSwap(int matrix[100][100], int, int);
void rowsSwap (int matrix[100][100], int, int);

int main()
{
	int matrix[100][100] = { { 0 } };
	int n, m;
	inputSize(n, m);
	initMatrix(matrix, n, m);
	displayMatrix(matrix, n, m);
	rowsSwap(matrix, n, m);
	displayMatrix(matrix, n, m);
	system("pause");
}

void inputSize(int& n, int& m)
{
	cout << "Please enter number of rows. n = ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Please enter a valid value. n = ";
		cin >> n;
	}
	cout << "Please enter number of columns. m = ";
	cin >> m;
	while (m <= 0)
	{
		cout << "Please enter a valid value. m = ";
		cin >> m;
	}
}

void columnsSwap(int matrix[100][100], int n, int m)
{
	int temp[100][100] = { { 0 } };
	int count = 0;
	while (count < m/2) 
	{
		for (int i = 0, j = count, k = 0; i < n; i++, k++)
		{
			temp[k][0] = matrix[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			matrix[i][count] = matrix[i][m - 1 - count];
		}
		for (int i = 0, k = 0; i < n; i++, k++)
		{
			matrix[i][m - 1 - count] = temp[k][0];
		}
		count++;
	}
}

void rowsSwap(int matrix[100][100], int n, int m)
{
	int temp[100][100] = { { 0 } };
	int count = 0;
	while (count < n / 2)
	{
		for (int j = 0, i = count, k = 0; j < m; j++, k++)
		{
			temp[0][k] = matrix[i][j];
		}
		for (int j = 0; j < m; j++)
		{
			matrix[count][j] = matrix[n - 1 - count][j];
		}
		for (int j = 0, k = 0; j < m; j++, k++)
		{
			matrix[n - 1 - count][j] = temp[0][k];
		}
		count++;
	}
}
