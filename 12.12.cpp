#include <iostream>
#include "ArrayExtension.h"

using namespace std;
char inputNumber();
int inputParameter();
//Unfortunately didn't have enough time to finish up the whole HW
int main()
{

	int matrix[M][M] = { { 0 } };
	int n = inputParameter();
	char task = inputNumber();

	switch (task)
	{
	case 'a':
		initMatrix(matrix, n, n);     //matrix with all 0-elements 
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				matrix[i][j] = n - i + j;
			}
		}
		displayMatrix(matrix, n, n);
		break;
	case 'b':
		initMatrix(matrix, n, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0;
		}
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = i; j < n - i; j++)
			{
				matrix[i][j] = 1;
			}
		}
		for (int i = (n + 1) / 2; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = matrix[(n / 2 - 1) - (i - (n + 1) / 2)][j];
			}
		}
		displayMatrix(matrix, n, n);
		break;
	case 'c':
		initMatrix(matrix, n, n);
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				matrix[i][j] = 1;
				matrix[i][n - j - 1] = 1;
			}
		}
		for (int i = (n + 1) / 2; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = matrix[(n / 2 - 1) - (i - (n + 1) / 2)][j];
			}
		}
		displayMatrix(matrix, n, n);
		break;
	case 'd':
		initMatrix(matrix, n, n);
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			matrix[i][i] = i + 1;
			matrix[i][n - i - 1] = n - i;
		}
		for (int i = (n + 1) / 2; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = matrix[(n / 2 - 1) - (i - (n + 1) / 2)][j];
			}
		}

		displayMatrix(matrix, n, n);
		break;
		
		system("pause");
	}
	system("pause");
}
char inputNumber()
{
	cout << "Please enter the number of the task:";
	char task;
	cin >> task;
	while (task <'a' && task > 'd')
	{
		cout << "Enter a valid number:";
		cin >> task;
	}
	return task;
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
