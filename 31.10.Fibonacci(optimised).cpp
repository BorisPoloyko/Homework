#include <iostream>

using namespace std;

int main()
{
	int f1 = 1, f2 = 1;
	while (f2 < 100)
	{
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	cout <<"The lowest 3-digit number ist "<< f2 << endl;
	system("pause");
	return 0;
}
