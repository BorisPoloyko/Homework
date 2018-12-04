#pragma once

#ifndef string_h
#define string_h

const int N = 256;

using namespace std;

int getLength(char*);
int compare(char*, char*, bool = true);
bool isEqual(char*, char*, bool = true);
char toUpper(char);
int substringPosition(char*, char*);

int getLength(char* source)
{
	int length = 0;
	while (source[length]) //равносильно  while(source[length]!= '\0')
	{
		length++;
	}

	return length;
}

int compare(char*  lhs, char* rhs, bool caseSensitivity)
{
	int i = 0;
	int lhsLength = getLength(lhs),
		rhsLength = getLength(rhs);
	int minLength = (lhsLength >= rhsLength) ? lhsLength : rhsLength;
	while (i < minLength)
	{
		char chl = !caseSensitivity ? lhs[i] : toUpper(lhs[i]),
			chr = !caseSensitivity ? rhs[i] : toUpper(rhs[i]);
		if (chl != chr)
		{
			return (lhs[i] > rhs[i]) ? 1 : -1;
		}
		i++;
	}
	return 0;
}

bool isEqual(char* lhs, char* rhs, bool caseSensitivity)
{
	int n = getLength(lhs),
		m = getLength(rhs);
	if (n != m)
	{
		return false;
	}
	int i = 0;
	while (i<n)
	{
		char chl = caseSensitivity ? lhs[i] : toUpper(lhs[i]),
			chr = caseSensitivity ? rhs[i] : toUpper(rhs[i]);
		if (chl != chr)
		{
			return false;
		}
		i++;
	}
	return true;

}

char toUpper(char symbol)
{
	const int difference = 'a' - 'A';

	if (symbol >= 'a' && symbol <= 'z')
	{
		symbol -= difference;
	}
	return symbol;
}

int substringPosotion(char* string, char* substring)
{
	int n = getLength(string),
		m = getLength(substring);
	if (m > n)
	{
		return -1;
	}
	int count = 0, index = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j<m; j++)
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
				count = 0;
				break;
			}
		}
	}
	return index;
}
#endif
