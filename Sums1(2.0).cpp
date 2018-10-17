#include "stdafx.h"
#include <iostream>

using namespace std;

double factorial(int n);
double sumSin(int n);
double switchSum(char choice, int n);
double sumA(int n);
double sumС(int n);
double sumD(int n);
double sumE(int n);
double sumF(int n);
double sumG(int n);
double sumH(int n);
double sumI(int n);
double sumJ(int n);
char toUpper(char symbol);
char inputChoice();
int inputParameter();
int inputParameter(int , int, int n );

int main(int argc, const char * argv[])
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		char choice = inputChoice();
		int n = inputParameter();
		if (choice == 'H')
		{
			n = inputParameter(1,15, n);
		}
		cout << "The result of the operation is " << switchSum(choice, n) << "\n";
		cout << "Press 'Y' to proceed ";
		cin >> cont;
	}
	return 0;
}

double factorial(int n) 
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

double sumA(int n)
{
	double sum = 0;
	for (double i = 1; i <= n; i++)
	{
		sum += (1.0 / i);
	}
	return sum;
}

double sumSin(int n)
{
	double sum = 0;
	for (double i = 1; i <= n; i++)
	{
		sum += (sin(i));
	}
	return sum;
}

double switchSum(char choice, int n)
{
	double result = 0;
	switch (toUpper(choice))
	{
	case 'A':
	{
		result = sumA(n);
		break;
	}
	case 'B':
	{
		result = pow(2, n);
		break;
	}
	case 'C':
	{
		result = sumС(n);
		break;
	}
	case 'D':
	{
		result = sumD(n);
		break;
	}

	case 'E':
	{
		result = sumE(n);
		break;
	}
	case 'F':
	{
		result = sumF(n);
		break;
	}
	case 'G':
	{
		result = sumG(n);
		break;

	}
	case 'H':
	{
		result = sumH(n);
		break;
	}
	case 'I':
	{
		result = sumI(n);
		break;
	}
	case 'J':
	{
		result = sumJ(n);

	}
	}
	return result;
}
char toUpper(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol - 32;
	}
	return symbol;
}

char inputChoice()
{
	char choice;
	cout << "Enter the symbol of the expression to be solved (From 'A' to 'J')\nExpression: ";
	cin >> choice;
	choice = toUpper(choice);
	while (choice <'A' || choice> 'K')
	{
		cout << "Please enter the vaild symbol\nExpression :";
		cin >> choice;
	}
	return choice;
}

int inputParameter()
{
	int n;
	cout << "Enter the parameter 'n' for the following expressions\nn= ";
	cin >> n;
	while (n != floor(n) || n <= 0)
	{
		cout << "Please enter a positive integer number\nn = ";
		cin >> n;
	}
	return n;
}

int inputParameter(int , int, int n )
{
	while (n != floor(n) || n < 1 || n>15)
	{
		cout << "Please enter a positive integer number not greater than 15\nn = ";
		cin >> n;
	}
	return n;
}

double sumС(int n)
{
	double res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= (1 + 1 / (pow(i, 2)));
	}
	return res;
}

double sumD(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += (pow(-1, (i + 1))) / (i*(i + 1));
	}
	return result;
}

double sumE(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += 1 / (pow(i, 5));
	}
	return result;
}

double sumF(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += (1 / (pow(2 * i + 1, 2)));
	}
	return result;
}

double sumG(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += (pow(-1, n) / (2 * i + 1));
	}
	return result;
}

double sumH(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += (factorial(i) / sumA(i));
	}
	return result;
}

double sumI(int n)
{
	double result = sqrt(2);
	for (int i = 1; i < n; i++)
	{
		result = sqrt(result + 2);
	}
	return result;
}

double sumJ(int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += 1 / (sumSin(i));
	}
	return result;
}
