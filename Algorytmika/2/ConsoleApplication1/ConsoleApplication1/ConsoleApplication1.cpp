
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;
int main()
{
	srand(time(NULL));// seeed for functions
	char decision;
	try {
		//-------------------------a--------------------------------------------------
		ofstream time;
		time.open("time.txt");
		if (!time.is_open())
		{
			string g = "Unable to open file";
			throw g;
		}//file handling 
		//-------------														----------
		int n;//table size
		float* a;//table creation
		float yourNumber = 0;
		int iterations;
		int yourPosition;//choosen position
		int average=500;
		for (n = 2; n < 500; n=n+4)
		{
			iterations = 0;
			float it = 0;//number for help with average
			int l = 0;//start of table
			int r = n - 1;//end of table
			for (int j = 0; j < average; j++)
			{
				iterations = 0;
				yourPosition = rand() % (n - 1);
				a = new float[n]; //memory alocation
				a = Randomise_Table(a, n);//random table
				almostQuickSort(a, l, r, yourPosition, yourNumber, iterations);//returning Your number
				it = it + iterations;
				delete[] a;
			}
			time << n << "\t" <<  (it / (float(average))) << "\t" << endl;
		}
		time.close();
		//for the test
		cout << "Would You like a small test?(Y-yes, else- no)" << endl;
		cin >> decision;
		if (toupper(decision) == 'Y')
		{
			haro();
		}
	}
	catch (string)
	{
		return -1;
	}
	return 0;
}

