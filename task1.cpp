#include <iostream>
#include <cmath>


using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();
void swap(int&, int&);

int main()
{
    nextSmallerThanTests();
}

int nextSmallerThan(int number)
{
    if (number < 0)
    {
        return -1;
    }
    
    int power = 0;
    int testNumber = number;
    int const length = 100;
    int digits[length];
    int digit;
    for (int i = 0; testNumber > 0; i++)
    {
        digit = number % 10;
        testNumber /= 10;
        power++;
        
    }
    for (int i = 0; number > 0; i++)
    {
        digit = number % 10;
        number /= 10;
        digits[power-i-1] = digit;
        
    }
    if (power ==1)
    {
        return -1;
    }
    
    bool count;
    for (int i = 0, diff = 1; power - diff - 1 >= 0; i++, diff++)
    {
        if (digits[power - diff] < digits[power - diff - i - 1]])
        {
            swap (digits[power - diff], digits[power - diff - 1]);
            count = false;
            break;
        }
        count = true;
    }
    for (int i = power; i < length; i++)
    {
        digits[i] = 0; //fill with zeroes because obtain trash information from previous runs
    }
    
    if (count == true)
    {
        return -1;
    }
    
    if (digits[0] == 0)
    {
        return -1;
    }
    int smallerNumber = 0;
    for (int i = 0; power >=0; i++, power--)
    {
        smallerNumber += digits[i]*pow(10,power-1);
    }
    return smallerNumber;
}

void nextSmallerThanTests()
{
    cout << (nextSmallerThan(21) == 12) << endl;
    cout << (nextSmallerThan(9) == -1) << endl;
    cout << (nextSmallerThan(111) == -1) << endl;
    cout << (nextSmallerThan(531) == 513) << endl;
    cout << (nextSmallerThan(2071) == 2017) << endl;
    cout << (nextSmallerThan(9) == -1) << endl;
    cout << (nextSmallerThan(111) == -1) << endl;
    cout << (nextSmallerThan(135) == -1) << endl;
    cout << (nextSmallerThan(1027) == -1) << endl;
    cout << (nextSmallerThan(-100) == -1) << endl;
    cout << (nextSmallerThan(4321) == 4312) << endl;
    cout << (nextSmallerThan(-4321) == -1) << endl;
    cout << (nextSmallerThan(222) == -1) << endl;
    cout << (nextSmallerThan(567654) == 567645) << endl;
    
}

void swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}
