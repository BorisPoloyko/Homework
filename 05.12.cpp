#include <iostream>

using namespace std;

bool isLetter(char);
void newStringOfWords(char*);
int getLength(char*);


int main()
{
	

	
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
	while (source[length]) //равносильно  while(source[length]!= '\0')
	{
		length++;
	}

	return length;
}

void newStringOfWords(char* string) 
{
	char newString[100][100];
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