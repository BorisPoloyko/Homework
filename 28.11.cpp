#include <iostream>

using namespace std;

int inputDimension();
void inputString(char*, int);
bool equivalenceOfStrings(char*, int, char*, int);
void outputEquivalenceOfStrings(int);
char orderOfStrings(int, int);
void outputOrderOfStrings(char);
int indexOfSubstring(char*,int , char*, int);
int inputLength();

int main()
{
	char cont = 'y';
	while (cont == 'y' || cont == 'Y')
	{
		
		char string1[100];
		char string2[100];
		int n = inputDimension();
		int m = inputDimension();
		outputEquivalenceOfStrings(equivalenceOfStrings(string1,n,string2,m));
		outputOrderOfStrings(orderOfStrings(n, m));
		char string[100];
		char substring[100];
		int k = inputDimension();
		int f = inputDimension();
		inputString(string, k);
		inputString(substring, f);
		cout << indexOfSubstring(string, k, substring, f);

		
		cout << "Press 'y' to proceed ";
		cin >> cont;
	}
	system("pause");
	return 0;
}

int inputDimension()
{
	int dimension;
	cout << "Please enter the dimension of the array <=100: ";
	cin >> dimension;
	while (dimension <= 0 || dimension > 100)
	{
		cout << "Invalid data!" << endl;
		cout << "Please enter the dimension of the array <=100: ";
		cin >> dimension;
	}
	return dimension;
}

void inputString(char* string, int n)
{
	cout << "Please enter the string:";
	
	for (int i = 0; i < n; i++)
	{
		cin >> string[i];	
	}
}

bool equivalenceOfStrings(char* string1, int n, char* string2, int m)
{
	int count = 0;
	if (n != m)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (string1[i] != string2[i])
			{
				return 0;
			}
			else if (string1[i] == string2[i])
			{
				count++;
			}
		}
		if (count == n)
		{
			return 1;
		}
	}
}

char orderOfStrings(int n, int m)
{
	if (n == m)
	{
		return '=';
	}
	else if (n < m)
	{
		return '<';
	}
	else if (n > m)
	{
		return '>';
	}
	return -1;
}

void outputEquivalenceOfStrings(int result)
{
	if (result == 0)
	{
		cout << "The strings are not equal!\n";
	}
	else if (result == 1)
	{
		cout << "The strings are equal!\n";
	}
}

void outputOrderOfStrings(char order)
{
	if (order == '=')
	{
		cout << "The strings have the same amount of characters!\n";
	}
	else if (order == '>')
	{
		cout << "The firts string has more characters!\n";
	}
	else if (order == '<')
	{
		cout << "The second string has less characters!\n";
	}
	else
	{
		cout << "Error!\n";
	}
}

int indexOfSubstring(char* string, int n, char* substring, int m)
{
	if (m > n)
	{
		return -1;
	}
	int count = 0, index = -1;
	for(int i = 0;i<n;i++)
	{
		for (int j = 0;j<m; j++)
		{	
			if (substring[j] == string[i+count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
				else
				{
					continue;
				}
			}
			else
			{
				index = -1;
				count = 0;
				break;
			}
		}
	}
	return -1;
}

int inputLength()
{
	int length;
	cout << "Enter the length of the word to pe replaced: ";
	cin >> length;
	return length;
}

