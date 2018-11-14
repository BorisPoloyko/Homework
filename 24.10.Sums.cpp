#include "stdafx.h"
#include "iostream"

using namespace std;

int factorial(int n);
int inputChoice();
void inputParameter(int &n, double &x);
double switchSum(char choice, int n, double x);
double sum1(int n, double x);
double sum2(int n, double x);
double sum3(int n, double x);
double sum4(int n, double x);
double sum5(int n, double x);
double sum6(int n, double x);
double sum7(int n, double x);
double sum8(int n, double x);
double sum9(int n, double x);
double sum10(int n, double x);

int main()
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		int choice = inputChoice();
		int n;
		double x;
		inputParameter(n,x);
		cout << "The result of the expression is " << switchSum(choice, n, x) << endl;
		cout << "Press 'Y' to proceed" << endl;
		cin >> cont;
	}
    return 0;
}

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int inputChoice()
{
	int choice;
	cout << "Enter the number of the expression to be solved (from 1 to 10)\nExpression: ";
	cin >> choice;
	while (choice <= 0 || choice >= 11)
	{
		cout << "Please enter a value number in the range from 1 to 10\nExpression: ";
		cin >> choice;
	}
	return choice;
}
void inputParameter(int &n, double &x)
{
	cout << "Please enter a natural parameter n\nn = ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Please enter a natural parameter n\n = ";
		cin >> n;
	}
	cout << "Please enter a real parameter x\nx = ";
	cin >> x;
}
double switchSum(char choice, int n, double x)
{
	double result = 0;
	switch (choice)
	{
	case 1:
	{
		result = sum1(n, x);
		break;
	}
	case 2:
	{
		result = sum2(n, x);
		break;
	}
	case 3:
	{
		result = sum3(n, x);
		break;
	}
	case 4:
	{
		result = sum4(n, x);
		break;
	}
	case 5:
	{
		result = sum5(n, x);
		break;
	}
	case 6:
	{
		result = sum6(n, x);
		break;
	}
	case 7:
	{
		result = sum7(n, x);
		break;
	}
	case 8:
	{
		result = sum8(n, x);
		break;
	}
	case 9:
	{
		result = sum9(n, x);
		break;
	}
	case 10:
	{
		result = sum10(n, x);
		break;
	}
	}
	return result;
}
double sum1(int n, double x)
{
	double result = 0;
	for (int i = 0; i <= n; i++)
	{
		result += pow(x,i) / (factorial(i));
	}
	return result;
}
double sum2(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += (1.0 / factorial(i)) + sqrt(abs(x));
	}
	return result;
}
double sum3(int n, double x)
{
	double result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= (1 + (sin(i*x)) / factorial(i));
	}
	return result;
}
double sum4(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i - 1)*pow(x, 2 * i - 1) / factorial(2 * i - 1);
	}
	return result;
}
double sum5(int n, double x)
{
	double result = 1;
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i)*pow(x, 2 * i) / factorial(2 * i);
	}
	return result;
}
double sum6(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(x, 2 * i - 1) / factorial(2 * i - 1);
	}
	return result;
}
double sum7(int n, double x)
{
	double result = 1;
	for (int i = 1; i <= n; i++)
	{
		result += pow(x, 2 * i) / factorial(2 * i);
	}
	return result;
}
double sum8(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i - 1)*pow(x, i) / i;
	}
	return result;
}
double sum9(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += pow(-1, i - 1)*pow(x, 2 * i - 1) / (2 * i - 1);
	}
	return result;
}
double sum10(int n, double x)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result -= pow(x, i) / i;
	}
	return result;
}
