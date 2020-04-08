#include <iostream>
#include "RowTree.h"
#include <vector>

using namespace std;

#define NUMVALUES 3
#define startPoint 97

int main()
{
	int wordLen;
	string wordCheck;

	cout << "Enter the Password: ";
	cin >> wordCheck;
	wordLen = wordCheck.length();



	for (int i = 0; i < NUMVALUES; i++)
	{
		RowTree* currRow = nullptr;
		RowTree start(i + startPoint);
		for (int j = 0; j < wordLen; j++)
		{
			if (j == 0) {
				currRow = &RowTree(&start);
				cout << "FUCK";
			}
			else
			{
				currRow = &RowTree(*currRow);
			}
		}
		vector<string> permutations = currRow->getPermutations();
		for (int i = 0; i < currRow->getLen(); i++)
		{
			cout << permutations[i];
		}
	}
	

	return 0;
}