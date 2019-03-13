#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string.h>

using namespace std;

char** obtainWords(const char*, int&);
char* replaceWords(char*, char*, char*);

int main()
{
	int n = 0;
	


	system("pause");
	return 0;
}

char** obtainWords(char* source, int& n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	const char* symbols = "	 1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);
	n++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}

char* replaceWords(char* source, char* word, char* newWord)
{
	int nwords = 0;
	char** words = obtainWords(source, nwords);

	int nWordsReplace = 0;


	for (int i = 0; i < nwords; i++)
	{
		if (strstr(words[i], word) != nullptr && strlen(words[i])==strlen(word))
		{
			nWordsReplace++;
		}

	}
	
	int dif = strlen(word) - strlen(newWord);
	char* replaced = new char[strlen(source) + (nWordsReplace*dif) + 1];

	strcpy(replaced, source);
	
	while ()
	

}