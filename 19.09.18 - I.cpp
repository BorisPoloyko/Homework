#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		double x, y;
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;

		//bool result = y>-x && (x*x)+(y*y)<= 1 или bool result = y>-x && pow(x,2)+pow(y,2)<= 1;					задача 11(а)

		//bool result = y>-0.5 && (x>y && x<1 || pow(x - 1, 2) + pow(y, 2) <= 1);									задача 11(б)

		//bool result = (x >= -1 && x <= 0 && y >= -1 && y <= 0) || ((x*x) + (y*y) <= 1 && x >= 0 && y>=0) ;		задача 11(в)
		
		//bool result = (x >= -1 && x <= 0 && y >= -1 && y <= 1) || ((x*x) + (y*y) <= 1);							задача 11 (г)

		//bool result = (y<=(x - 1) && y >= 0) || (y >= (-x - 1) && y <= 0) || ((x*x) + (y*y) <= 1 && x >= 0);		задача 11 (д)

		bool  result = y < x && x >= -0.5 && x <= 1 && y >= -0.5 && y <= 1;
		if (result)
		{
			cout << "Point (" << x << ";" << y << ") belongs to the area" << endl;
		}
		else
		{
			cout << "Point (" << x << ";" << y << ") doesn't belong to the area" << endl;

		}
		cout << "Press \"Y\" to proceed ";
		cin >> esc;
	}

}


