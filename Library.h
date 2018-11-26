#pragma once
#ifndef numberlibrary_h
#define numberlibrary_h
#include <cmath>

bool IsPalindrome(long long);
long long makingReverse(long long);
bool IsPrimeNumber(int number);


long long makingReverse(long long number)
{
	int sign = number >= 0 ? 1 : -1;
	number = abs(number);
	long long reverse = 0;
	while (number)
	{
		int digit = number % 10;
		reverse = reverse * 10 + digit;
		number /= 10;
	}
	return sign * reverse;
}

bool IsPalindrome(long long number)
{
	return number == makingReverse(number);
}

bool IsPrimeNumber(int number)
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
#endif /* numberlibrary_h */
