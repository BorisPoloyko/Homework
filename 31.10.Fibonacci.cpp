#include <iostream>

using namespace std;


int NumberOfDigits(int);
int Fibbonacci(int);


int main()
{
	for (int i = 1; ; i++)
	{
		if (NumberOfDigits(Fibbonacci(i)) == 3)
		{
			cout << "The lowest 3-digit number is " << Fibbonacci(i)<<endl;
		break;
		}
	}
	system("pause");
	return 0;
}

int NumberOfDigits(int number)
{
	int digits = 1, remainder = 0;
	while (number /= 10)
	{
		++digits;
	}
	return digits;
}

int Fibbonacci(int index)
{
	int current = 1, previous = 0;
	for (int i = 1; i < index; i++)
	{
		current += previous;
		previous = current - previous;
	}
	return current;
}