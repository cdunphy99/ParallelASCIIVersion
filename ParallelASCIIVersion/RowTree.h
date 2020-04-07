#pragma once
#include <string>
#include "NodeObject.h"

#define NUMVALUES 3
#define startPoint 97

using namespace std;

class RowTree
{
public:
	RowTree() = default;
	RowTree(int);
	RowTree(RowTree*);

	string* getPermutations();
	int getLen();

	~RowTree() = default;

private:

	NodeObject* RowList;
	int level;
	int len;
};

RowTree::RowTree(int startingLetter) {
	cout << "---" << len << "====\n"; // does not run this

	this->level = 2;
	this->len = NUMVALUES;
	cout << "---" << len << "====\n";
	RowList = new NodeObject[NUMVALUES];
	for (int i = 0; i < (NUMVALUES); i++)
	{
		NodeObject* temp = new NodeObject;
		int* temp2 = new int[2];
		temp2[0] = startingLetter;
		temp2[1] = i + startPoint;
		temp->setWord(temp2);

		RowList[i] = *temp;
	}
}

RowTree::RowTree(RowTree* prevRow) {
	// length of previous * num of possible values
	this->len = prevRow->getLen() * NUMVALUES;
	cout << "RowTree prevRow constructor: updating len to " << prevRow->getLen() * NUMVALUES << "\n";
	this->level = prevRow->level + 1;
	this->RowList = new NodeObject[this->len];
	cout << "FUCK\n"; // does not get here

	for (int i = 0; i < prevRow->len; i++) {
		cout << "FUCK\n"; // does not get here
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			int* temp2 = new int[level];
			int* temp3 = prevRow->RowList[i].getIntWord();
			for (int k = 0; k < level - 1; k++)
			{
				temp2[k] = temp3[k];
			}
			temp2[level - 1] = startPoint + j;
			temp->setWord(temp2);

			this->RowList[(i * NUMVALUES) + j] = *temp;
		}
	}

}

inline string* RowTree::getPermutations()
{
	string* Permutations = new string[this->len];
	for (int i = 0; i < this->len; i++)
	{
		Permutations[i] = RowList[i].getWord();
		cout << "Added " << Permutations[i] << " to permutations list\n";
	}
	return Permutations;
}

inline int RowTree::getLen()
{
	return this->len;
}
