#include <iostream>
#include "ArrayExtension.h"

using namespace std;

int inputParameter();
void symmetricSquares(int matrix[100][100],int n);
void circledSquares(int matrix[100][100], int n);


int main()
{
	int n = inputParameter();
	int matrix[100][100] = { { 0 } };
	initMatrix(matrix, n, n);
	displayMatrix(matrix, n, n);
	circledSquares(matrix, n);
	displayMatrix(matrix, n, n);

	system("pause");
}






int inputParameter()
{
	cout << "Please enter the n-parameter:";
	int n;
	cin >> n;
	while (n <= 0)
	{
		cout << "Please enter a valid parameter:";
		cin >> n;
	}
	return n;
}

void symmetricSquares(int matrix[100][100], int n)
{
	int square1[100][100] = { { 0 } };
	int square2[100][100] = { { 0 } };
	int square3[100][100] = { { 0 } };
	int square4[100][100] = { { 0 } };
	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			square1[k][l] = matrix[i][j];
		}
	}
	

	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			square2[k][l] = matrix[i][j];
		}
	}
	

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			square3[k][l] = matrix[i][j];
		}
	}

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			square4[k][l] = matrix[i][j];
		}
	}
	
	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			matrix[i][j] = square4[k][l];
		}
	}
	
	for (int i = (n + 1) / 2 , k = 0; i < n ; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			matrix[i][j] = square1[k][l];
		}
	}

	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			matrix[i][j] = square3[k][l];
		}
	}

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			matrix[i][j] = square2[k][l];
		}
	}

}

void circledSquares(int matrix[100][100], int n)
{
	int square1[100][100] = { { 0 } };
	int square2[100][100] = { { 0 } };
	int square3[100][100] = { { 0 } };
	int square4[100][100] = { { 0 } };
	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			square1[k][l] = matrix[i][j];
		}
	}


	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			square2[k][l] = matrix[i][j];
		}
	}


	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			square3[k][l] = matrix[i][j];
		}
	}

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			square4[k][l] = matrix[i][j];
		}
	}

	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			matrix[i][j] = square3[k][l];
		}
	}

	for (int i = 0, k = 0; i < (n + 1) / 2; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			matrix[i][j] = square1[k][l];
		}
	}

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = (n + 1) / 2, l = 0; j < n; j++, l++)
		{
			matrix[i][j] = square2[k][l];
		}
	}

	for (int i = (n + 1) / 2, k = 0; i < n; i++, k++)
	{
		for (int j = 0, l = 0; j < (n + 1) / 2; j++, l++)
		{
			matrix[i][j] = square4[k][l];
		}
	}

}