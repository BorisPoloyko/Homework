

#include <iostream>
#include <cmath>

using namespace std;

double cos(double, double);

int main(int argc, const char * argv[])
{
	char cont = 'y';
	while (cont = 'y' || cont == 'Y')
	{
		double from, to;
		cout << "Enter the values of the segment\nLeft border: ";
		cin >> from;
		cout << "Right border: ";
		cin >> to;
		cout << "The segment has the following apereance: [" << from << ", " << to << "]" << endl;
		cout << "Enter the value of accuracy (greater than 0)\ne = ";
		double accuracy;
		cin >> accuracy;
		cout << "x\tvalue\tstandart function\t\tdifference" << endl;
		for (; from <= to; from += 0.1)
		{
			cout << from << "\t" << cos(from, accuracy) << "\t\t" << cos(from) << "\t\t" << cos(from, accuracy) - cos(from) << endl;
		}
		cout << "Press 'y' to proceed" << endl;
		cin >> cont;
		system("cls");
	}
	system("pause");
	return 0;
}

double cos(double from, double accuracy)
{
	double cos = 0, term = 1;
	int i = 1;
	while (fabs(term)>accuracy)
	{
		cos += term;
		term *= -1.0*(from*from) / (2 * i) / (2 * i - 1);
		i++;
	}

	return cos;
}

