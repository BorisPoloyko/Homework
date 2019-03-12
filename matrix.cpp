#include <iostream>
#include <cmath>

using namespace std;

typedef double(*matrixType)(int, int);
typedef double(*operation)(double**,int);
typedef bool(*condition)(double**, double**, int, operation);

int inputSize();
double taylor(int, int);
double** defineSquareMatrix(int);
void displaySquareMatrix(double**, int);
double** buildSquareMatrix(double**,int, matrixType);
double** buildRandomMatrix(double**, int);
double maxSumColumn(double**, int n);
void compareSquareMatrix(double**, double**, int n, operation, condition);
bool ifFirstMatrixGreater(double**, double**, int, operation);


int main()
{
	int n = inputSize();

	double** matrixA = defineSquareMatrix(n);

	matrixA = buildSquareMatrix(matrixA, n, taylor);

	displaySquareMatrix(matrixA, n);

	double** matrixB = defineSquareMatrix(n);

	matrixB = buildRandomMatrix(matrixB, n);

	cout << endl;

	displaySquareMatrix(matrixB, n);

	compareSquareMatrix(matrixA, matrixB, n, maxSumColumn, ifFirstMatrixGreater);

	system("pause");

	return 0;
}

bool ifFirstMatrixGreater(double** matrixA, double** matrixB, int n, operation operation)
{
	return operation(matrixA, n) > operation(matrixB, n);
}

int inputSize()
{
	int n;
	while (true)
	{
		cout << "Please enter the size of the matrix, n = ";
		cin >> n;
		if (n > 0)
		{
			return n;
		}
		cout << "Invalid data! Try again, n =  ";
	}
}

double** defineSquareMatrix(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[n];
	}
	return matrix;
}

void displaySquareMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(15);
			cout << *(*(matrix + i) + j);
		}
		cout << endl;
	}
}

double** buildSquareMatrix(double** matrix,int n, matrixType type)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(matrix + i) + j) = type(i, j);
		}
	}
	return matrix;

}

double** buildRandomMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(matrix + i) + j) = ((rand() % 15) - 5) / (double)(rand() % 10);
		}
	}
	return matrix;
}

double taylor(int i, int j)
{
	return (i == j) ? i : (sin(2 * i*j) + sin(i)) / ((i - j - 4) ^ 3 + (i + j) ^ 2);
}

double maxSumColumn(double** matrix, int n)
{
	
	double maxSum = 0;
	for (int j = 0; j < n; j++)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += *(*(matrix + i) + j);
		}
		if (sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}

void compareSquareMatrix(double** matrixA, double** matrixB,int n,operation operation, condition condition)
{
	if (condition(matrixA, matrixB, n, operation))
	{
		cout << "The first matrix is greater! " << endl;
	}
	else
	{
		cout << "The second matrix is greater! " << endl;
	}
}
