#include <iostream>
#include <cmath>

using namespace std;

double sqrt(double, double);

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
		cout << "x\tvalue\tstandart function\tdifference" << endl;
		for (; from <= to; from++)
		{
			cout << from << "\t" << sqrt(from, accuracy) << "\t\t" << sqrt(from) << "\t\t" << sqrt(from, accuracy) - sqrt(from) << endl;
		}
		cout << "Press 'y' to proceed" << endl;
		cin >> cont;
		system("cls");
	}
	system("pause");
	return 0;
}

double sqrt(double from, double accuracy)
{
	double prev = 1, next = (0.5)*(prev + from / prev), sqrt;
	while (abs(next - prev)>accuracy)
	{
		prev = next;
		next = 0.5*(prev + from / prev);
	}
	sqrt = next;
	return sqrt;
}


