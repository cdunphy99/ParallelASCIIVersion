#include <iostream>
#include <vector>
#include "RowTree.h"

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
		for (int j = 0; j < wordLen; j++) // 2 have already been generated
		{
			if (j == 0) {
				currRow = &RowTree(start);
				cout << "FUCK\n";
			}
			else
			{
				currRow = &RowTree(*currRow); // this is not working properly, preventing the permutations from being printed.
			}
		}



<<<<<<< Updated upstream
		vector<string> permutations = currRow->getPermutations();
		/*for (int i = 0; i < (wordLen - 1 * NUMVALUES); i++)
		{
			cout << permutations[i];
		}*/
		for (int i = 0; i < permutations.size(); i++)
=======
		string* permutations = currRow->getPermutations();
		for (int i = 0; i < NUMVALUES; i++)
>>>>>>> Stashed changes
		{
			cout << permutations[i];
		}


	}

	return 0;
}