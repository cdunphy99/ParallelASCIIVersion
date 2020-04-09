#include <iostream>
#include <vector>
#include "permutations.h"

using namespace std;


int main()
{
	cout << "Enter password: ";
	string wordCheck;
	cin >> wordCheck;
	permutations permObject;
	vector<string> permutations;
	permutations = permObject.getPermutations(wordCheck, wordCheck.length());
	for (auto i : permutations) {
		cout << i << "  ";
	}
	return 0;
}