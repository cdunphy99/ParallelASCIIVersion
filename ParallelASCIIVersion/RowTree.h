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
		RowTree(int);
		RowTree(RowTree*);

		vector<string> getPermutations();

		~RowTree() = default;

	private:
		
		vector<NodeObject> RowList;
		int level;
		int len;
};

RowTree::RowTree(int startingLetter) {

	this->level = 2;
	this->len = NUMVALUES;

	for (int i = 0; i < this->len; i++)
	{
		NodeObject* temp = new NodeObject;
		vector<int> temp2;
		temp2.push_back(startingLetter);
		temp2.push_back(i + startPoint);
		temp->setWord(temp2);

		this->RowList.push_back(*temp);
	}
}

RowTree::RowTree(RowTree* prevRow) {
	// length of previous * num of possible values
	this->len = prevRow->len * NUMVALUES;
	this->level = prevRow->level + 1;
//	this->RowList = new NodeObject[this->len];

	
	for (int i = 0; i < prevRow->RowList.size(); i++) {
		for (int j = 0; j < NUMVALUES; j++) {

			NodeObject* temp = new NodeObject;
			vector<int> temp2;
			vector<int> temp3 = prevRow->RowList[i].getIntWord();
			for (int k = 0; k < level-1; k++)
			{
				temp2.push_back(temp3[k]);
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
	for (int i = 0; i < this->RowList.size(); i++)
	{
		Permutations.push_back(this->RowList[i].getWord());
	}
	return Permutations;
}
