#include <iostream>
#include "ArrayExtension.h"

using namespace std;

int inputParameter();
void inputA_n(int*, int);
void matrixFilling(int matrix[100][100], int*, int);

int main()
{
	int n[100];
	int N = inputParameter();
	inputA_n(n, N);
	int matrix[100][100] = { { 0 } };
	initZeroMatrix(matrix, N, N);
	matrixFilling(matrix, n, N);
	displayMatrix(matrix, N, N);
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

void inputA_n(int* n, int N)
{
	cout << "Please enter a_n:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "a_" << i + 1 << " = ";
		cin >> n[i];

	}
}

void matrixFilling(int matrix[100][100], int* a_n, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0, count = 0; j < N; j++, count++)
		{
			matrix[i][j] = a_n[count + i];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = N - i, count = 0; j < N; j++, count++)
		{
			matrix[i][j] = a_n[count];
		}
	}
}


