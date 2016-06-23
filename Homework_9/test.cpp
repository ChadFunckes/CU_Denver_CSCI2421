
#include <iostream>
#include<stdio.h>
using namespace std;

int coins(int a){
	if (a == 0)
		return 25;
	if (a == 1)
		return 10;
	if (a == 2)
		return 5;
	if (a == 3)
		return 1;
}


int count(int denom, int amount)
{

	if (amount == 0)
		return 1;

	if (amount < 0)
		return 0;

	if (denom <= 0 && amount >= 1)
		return 0;

	return count(denom - 1, amount) + count(denom, amount - coins(denom - 1));
}


int main()
{

	cout << count(4, 42);

	system ("pause");
	return 0;
}
