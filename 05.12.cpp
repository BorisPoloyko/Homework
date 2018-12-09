#include <iostream>

using namespace std;

bool isLetter(char);
void arrayOfWords(char*, char[100][100]);
int getLength(char*);
int substringPosition(char*, char*, int);
void stringReplacement(char*, char*, char*, char*);
void displayArray(char*);

int main()
{
	char string[25] = "Hello, hello, hetll";
	char toBeReplaced[3] = "ll";
	char replace[5] = "abc";
	char newString[30] = { '\0' };
	stringReplacement(string, toBeReplaced, replace, newString);
	displayArray(newString);

	system("pause");
}

bool isLetter(char symbol)
{
	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return true;
	}
	return false;
}

int getLength(char* source)
{
	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}

void arrayOfWords(char* string, char newString[100][100])
{

	int nextLetter = 0, nextWord = 0, flag = 0;
	for (int i = 0; i < getLength(string); i++)
	{
		if (isLetter(string[i]))
		{
			newString[nextLetter][nextWord] = string[i];
			nextLetter++;
		}
		else
		{
			if (isLetter(string[i + 1]))
			{
				nextWord++;
				nextLetter = 0;
			}
		}

	}

}

int substringPosition(char* string, char* substring, int start)
{
	int n = getLength(string),
		m = getLength(substring);
	if (m > n)
	{
		return -1;
	}
	int count = 0, index = -1;
	for (int i = start; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (substring[j] == string[i + count])
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
	return index;
}

void stringReplacement(char* string, char* toBeReplaced, char* replace, char* newString)
{

	int newLength = getLength(replace), oldLength = getLength(toBeReplaced), sLength = getLength(string), start = 0, oldStart = 0, count = 0, difference = newLength - oldLength;
	int index = substringPosition(string, toBeReplaced, start);
	for (int i = 0; i < index; i++)
	{
		newString[i] = string[i];
	}
	while (index != -1)
	{
		for (int j = index + count*(difference) , i = 0; j < index + newLength + count*(difference); j++, i++)
		{
			newString[j] = replace[i];
		}
		start = index + newLength;
		int newIndex = substringPosition(string, toBeReplaced, start);
		while (newIndex != -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < newIndex; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}
		while (newIndex == -1)
		{
			for (int i = index + newLength +count*(difference) , j = index + oldLength; j < sLength; i++, j++)
			{
				newString[i] = string[j];
			}
			break;
		}

		index = substringPosition(string, toBeReplaced, start);
		count++;
	}
}

void displayArray(char* string)
{
	for (int i = 0; i < getLength(string); i++)
	{
		cout << "string[" << i + 1 << "] = " << string[i] << endl;
	}
}
