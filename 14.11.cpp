#include <iostream>

using namespace std;

int inputNumber();
char inputSymbol();
int inputDimension();
void numberOfZeroes(int);
void numberOfOnes(int );
void numberOfZeroesInArray(int, int* );
void numberOfOnesInArray(int, int*);
void numberOfSymbols(int, char);
void numberOfSymbolsInArray(int, int*, char);
void inputArray(int* , int );


int main()
{
	int number = inputNumber();
	numberOfZeroes(number);
	numberOfOnes(number);
	int array[32];
	int dimention = inputDimension();
	inputArray(array, dimention);
	numberOfZeroesInArray(dimention, array);
	numberOfOnesInArray(dimention, array);
	char symbol = inputSymbol();
	numberOfSymbols(number, symbol);
	numberOfSymbolsInArray(dimention, array, symbol);
	system("pause");
	return 0;
}

void numberOfZeroes(int n)
{
	int numberOfZeroes = 0;
	int remainder;
	while (n)
	{
		remainder = n % 2;
		if (remainder == 0)
		{
			numberOfZeroes++;
		}
		n /= 2;
	}
	cout << "Number of 0s in the binary system = " << numberOfZeroes << endl;
}

void numberOfOnes(int n)
{

	int numberOfOnes = 0;
	int remainder;
	while (n)
	{
		remainder = n % 2;
		if (remainder == 1)
		{
			numberOfOnes++;
		}
		n /= 2;
	}
	cout << "Number of 1s in the binary system = " << numberOfOnes << endl;
}

int inputNumber()
{
	int n;
	cout << "Please enter an integer number:\nNumber = ";
	cin >> n;
	return n;
}

int inputDimension()
{
	int dimension;
	cout << "Please enter the dimension of the array <=32: ";
	cin >> dimension;
	while (dimension <= 0 || dimension > 32)
	{
		cout << "Invalid data!" << endl;
		cout << "Please enter the dimension of the array <=32: ";
		cin >> dimension;
	}
	return dimension;
}

void inputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void  numberOfZeroesInArray(int dimention, int *array)
{
	for (int i = 0; i < dimention; i++)
	{
		cout << "Number of 0s in the [" << i + 1 << "] element in the binary system:";
		numberOfZeroes(array[i]);
	}
}

void numberOfOnesInArray(int dimention, int*array)
{
	{
		for (int i = 0; i < dimention; i++)
		{
			cout << "Number of 1s in the [" << i + 1 << "] element in the binary system:";
			numberOfOnes(array[i]);
		}
	}
}

char inputSymbol() 
{
	char symbol;
	cout << "Please enter an symbol(from 0 to f) :\nSymbol = ";
	cin >> symbol;
	while (symbol < 0 || symbol < 48 && symbol > 57 || symbol < 65 && symbol > 70 || symbol < 97 && symbol > 102)
	{
		cout << "Invalid symbol!\nSymbol = ";
		cin >> symbol;
	}
	if (symbol >= 97 || symbol <= 102)
	{
		return symbol - 87;
	}
	if (symbol >= 65 || symbol <= 70)
	{
		return symbol - 55;
	}
	if (symbol >= 48 || symbol <= 57)
	{
		return symbol - 48;
		
	}
}

void numberOfSymbols(int n, char symbol)
{
	int remainder;
	int numberOfSymbol = 0;
	while (n)
	{
		remainder = n % 16;
		if (remainder == symbol)
		{
			numberOfSymbol++;
		}
		n /= 16;
	}
	cout << "The symbol " << symbol << " is encounterd " << numberOfSymbol << " times in the 16-digit notation of the number" ;
}

void numberOfSymbolsInArray(int dimention, int*array, char symbol)
{
	{
		for (int i = 0; i < dimention; i++)
		{
			cout << "\n";
			numberOfSymbols(array[i], symbol);
			cout << " of [" << i + 1 << "] element" << endl;
		}
	}
}