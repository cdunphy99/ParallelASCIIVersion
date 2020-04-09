#pragma once
#include <string>
#include <vector>
#include "NodeObject.h"

#define NUMVALUES 3
#define startPoint 97

using namespace std;

class RowTree
{
public:
	RowTree() = default;
	RowTree(char);
	RowTree(RowTree*);

	vector<string> getPermutations();
	int getLen();

	~RowTree() = default;

private:
	int len;
	NodeObject* RowList;
	int level;
};

RowTree::RowTree(char startingLetter) {
	this->level = 2;
	this->RowList = new NodeObject[NUMVALUES];
	this->len = sizeof(char);
	for (int i = 0; i < (NUMVALUES + 1); i++)
	{
		NodeObject* temp = new NodeObject;
		string temp2 = "";
		temp2 += startingLetter;
		temp2 += i + startPoint;
		temp->setWord(temp2);
		RowList[i] = *temp;
	}
}

RowTree::RowTree(RowTree* prevRow) {
	// length of previous * num of possible values
	this->len = prevRow->getLen() * NUMVALUES;
	this->level = prevRow->level + 1;
	this->RowList = new NodeObject[this->len];

	for (int i = 0; i < prevRow->len; i++) {
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			string temp2;
			string temp3 = prevRow->RowList[i].getWord();
			for (int k = 0; k < level - 1; k++)
			{
				temp2 += temp3[k];
			}
			temp2[level - 1] = startPoint + j;
			temp->setWord(temp2);

			this->RowList[(i * NUMVALUES) + j] = *temp;
		}
	}
}

inline vector<string> RowTree::getPermutations()
{
	vector<string> Permutations;
	for (int i = 0; i < this->len; i++)
	{
		Permutations.push_back(RowList[i].getWord());
	}
	return Permutations;
}

inline int RowTree::getLen()
{
	return this->len;
}