// recursion_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int const SIZE = 100;
int fib(int);
int fastFib(int);
void printStarsTopDown(int);
void printStarsDownTop(int);
void printStarsZigZag(int, int);
int cache[SIZE];


int main()
{
	for (int i = 0; i < SIZE; ++i)
	{
		cache[i] = -1;
	}
	cache[0] = 1;
	cache[1] = 1;

	cout << fib(0) << endl;

	cout << fib(5) << endl;

	cout << fib(10) << endl;

	cout << fib(20) << endl;

	//40 is slow
	cout << fastFib(41) << endl;
	cout << fastFib(42) << endl;
	cout << fastFib(43) << endl;
	cout << fastFib(44) << endl;

	cout << endl << endl;

	printStarsTopDown(5);
	cout << endl << endl;

	printStarsDownTop(5);
	cout << endl << endl;

	printStarsZigZag(10, 10);
	cout << endl << endl;

	//things after this respond with incorrect values
	//cout << fastFib(45) << endl;
	//cout << fastFib(46) << endl;
	//cout << fastFib(47) << endl;
	//cout << fastFib(48) << endl;
	//cout << fastFib(49) << endl;
	//cout << fastFib(50) << endl;
	
	//cout << fib(50) << endl;
	//50 doesn't really run

	return 0;
}

void printStarsZigZag(int n, int m)
{
	if (m < 1) return;
	printStarsTopDown(n);
	printStarsDownTop(n);

	return printStarsZigZag(n, m - 1);
}

void printStarsDownTop(int n)
{
	if (n < 1) return;

	printStarsDownTop(n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << '*';
	}
	cout << endl;

	return;
}

void printStarsTopDown(int n)
{
	if (n < 1) return;
	
	for (int i = 0; i < n; ++i)
	{
		cout << '*';
	}
	cout << endl;

	return printStarsTopDown(n - 1);
}

int fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int fastFib(int n)
{
	if (cache[n] != -1)
		return cache[n];
	cache[n] = fastFib(n - 1) + fastFib(n - 2);
	return fastFib(n - 1) + fastFib(n - 2);
}
