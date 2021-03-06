// FINAL PROJECT PROBLEM #6
// JAMES POTRATZ

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int inputArray[10] = { 13579, 26791, 26792,	33445, 55555, 62483, 77777, 79422, 85647, 93121 };
int numSearch = 0;

void bubbleSort(int list[], int length)
{
	int temp;
	for (int iteration = 1; iteration < length; iteration++)
	{
		for (int index = 0; index < length - iteration; index++)
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
	}
	for (int i = 0; i < 10; i++)
		cout << inputArray[i] << " ";
}

int binarySearch(const int list[], int listLength, int searchItem)
{
	int first = 0;
	int last = listLength - 1;
	int mid;
	bool found = false;
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (list[mid] == searchItem)
			found = true;
		else if (list[mid] > searchItem)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}

int main()
{
	cout << "Your selected numbers are ... ";
	bubbleSort(inputArray, 10);
	cout << endl << "Please type the winning lottery number. Good Luck!" << endl;
	cin >> numSearch;
	cout << "Searching..." << endl;
	if (binarySearch(inputArray, 10, numSearch) == -1)
	{
		cout << "Unfortunately you did not win this week, try again next time!" << endl;
	}
	else
		cout << "CONGRATULATIONS!!!! YOU WON!!!!" << endl;
	system("pause");

}

