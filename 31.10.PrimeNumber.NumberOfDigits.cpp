#include <iostream>

using namespace std;


int NumberOfDigits(long long);
int MinDigit(long long);
int MaxDigit(long long);
bool IsPrimeNumber(long long);


int main()
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		cout << "Enter a number: ";
		int number;
		cin >> number;
		cout << "Number " << number << " has " << NumberOfDigits(number) << " digit(s)\nThe greatest digit is " << MaxDigit(number) << "\n" << "The lowest digit is " << MinDigit(number) << endl;
		if (IsPrimeNumber(number))
		{
			cout << "It's a prime number\n";
		}
		else
		{
			cout << "It's not a prime number\n";
		}
		cout << "Press 'y' to proceed ";
		cin >> cont;
		system("cls");
	}
	system("pause");
	return 0;
}


int NumberOfDigits(long long number)
{
	int digits = 1, remainder = 0;
	while (number /= 10)
	{
		++digits;
	}
	return digits;
}
int MinDigit(long long number)
{
	int digitMin = 9, remainder = 0;
	number = abs(number);
	while (number > 0)
	{
		remainder = number % 10;
		if (digitMin >= remainder)
		{
			digitMin = remainder;
		}
		number /= 10;
	}
	return digitMin;
}
int MaxDigit(long long number)
{
	int remainder = 0, digitMax = 0;
	number = abs(number);
	while (number > 0)
	{
		remainder = number % 10;
		if (digitMax <= remainder)
		{
			digitMax = remainder;
		}
		number /= 10;
	}
	return digitMax;
}
bool IsPrimeNumber(long long number)
{
	if (number <= 1)
	{
		return false;
	}
	bool result = true;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (!(number % i))
		{
			result = false;
			break;
		}
	}
	return result;
}
