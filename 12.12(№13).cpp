#include <iostream>
#include "ArrayExtension.h"

using namespace std;

void inputSize(int&, int&);
int sumMaxEven(int matrix[100][100], int&, int&);

int main()
{
	int matrix[100][100] = { { 0 } };
	int n, m;
	inputSize(n, m);
	initMatrix(matrix, n, m);
	displayMatrix(matrix, n, m);
	cout << sumMaxEven(matrix, n, m);

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

int sumMaxEven(int matrix[100][100], int& n, int& m)
{
	int maxSum = -1; 
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] % 2 != 0)
			{
				sum = 0;
				break;
			}
			sum += abs(matrix[i][j]);
		}
		if (maxSum < sum)
		{
			maxSum = sum;
		}
	}
	return maxSum;

		
}


