
#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <cstdio>
#include <fstream>
using namespace std::chrono;
using namespace std;


float* Insertsort_up(float *table, int size)//name for user friendly name
{
	ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 20, "ISU%d.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}

	//auto start = high_resolution_clock::now();
	float temp;
	float *a = new float[2];
	a[1] = 0;//for real time showing(optional)
	a[0] = 0;//number of steps
	for (int j = 1; j < size; j++)//algorithm 
	{
		temp = table[j];
		int i = j - 1;
		while (i >= 0 && table[i] > temp)
		{
			table[i + 1] = table[i];
			i--;
			a[0]++;
		}
		table[i + 1] = temp;
		if (i != j - 1)//check if table is modified
		{
			for (int j = 0; j < size; j++)//writing tables
			{
				tables << table[j]<<"\t";
			}
			tables << "\n";
		}
	}
	//auto stop = high_resolution_clock::now();
	//duration<double, std::milli> fp_ms = (stop - start);
	//a[1] = fp_ms.count();//execution time
	tables.close();
	return a;
}
float* Insertsort_down(float *table, int size)
{
	ofstream tables;
	char *h = new char[30];//for different file names
	snprintf(h, 15, "ISD%d.txt", size);
	tables.open(h);
	delete[] h;
	if (!tables.is_open())
	{
		string g = "Unable to open file";
		throw g;
	}

	//auto start = high_resolution_clock::now();
	float temp;
	float *a = new float[2];
	a[1] = 0;//for real time showing(optional)
	a[0] = 0;//number of steps
	for (int j = 1; j < size; j++)
	{
		temp = table[j];
		int i = j - 1;
		while (i >= 0 && table[i] < temp)
		{
			table[i + 1] = table[i];
			i--;
			a[0]++;
		}
		table[i + 1] = temp;
		if (i != j - 1)//check if table is modified
		{
			for (int j = 0; j < size; j++)//writing tables
			{
				tables << table[j]<<"\t";
			}
			tables << "\n";
		}
	}
	//auto stop = high_resolution_clock::now();
	//duration<double, std::milli> fp_ms = (stop - start);
	//a[1] = fp_ms.count();//execution time
	tables.close();
	return a;
}
float* Randomise_Table(float *table,int size)
{
	for (int i = 0; i < size; i++)
	{
		double x = (static_cast <float> (RAND_MAX / 123));
		if (x != 0)
		{
			table[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 123)) - (rand()) /x ;
		}
		//so they become negative as well
	}
	return table;
}