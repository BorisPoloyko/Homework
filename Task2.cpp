#include <iostream>

using namespace std;

void encoding(char[], int[], char[]);
void decoding(int[], char[], char[], int);
void codingTests();
bool equals(char[], char[]);
int length (char[]);
int index(char[], char);

int main()
{
    codingTests();
}

int length(char source[])
{
    int length = 0;
    while (source[length])
    {
        length++;
    }
    return length;
}

int index (char a[], char symb)
{
    int index = 0;
    for (int i = 0; i < length(a); i++)
    {
        if (a[i] != symb)
        {
            index++;
        }
        if (a[i] == symb)
        {
            return index;
        }
    }
    return index;
}

void encoding(char source[], int encoding[], char rule[])
{
    
    for (int i = 0; i < length(source); i++)
    {
        encoding[i] = index(rule, source[i]) + 1;
    }
}

void decoding(int source[], char decoding[], char rule[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        decoding[i] = rule[source[i]-1];
    }
}

bool equals(char lhs[], char rhs[])
{
    
    for (int i = 0; i < length(lhs); i++)
    {
        if (lhs[i]!=rhs[i])
        {
            return false;
        }
    }
    return true;
}

void codingTests()
{
    const int length = 11;
    
    char source[length] = "learn c++!";
    
    int numbers[length - 1] = { 0 };
    
    char rule[29] = {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a','!','+',' '};
    encoding(source, numbers, rule);
    
    char expected[length];
    
    decoding(numbers, expected, rule, 11);
    
    cout << equals(source, expected) << endl;
    
    char mySource[17] = "do learn nothing";
    
    int myNumbers[17] = { 0 };
    
    encoding(mySource, myNumbers, rule);
    
    char myExpected[17];
    
    decoding(myNumbers, myExpected, rule, 17);
    
    cout << equals(mySource, myExpected) << endl;
}

