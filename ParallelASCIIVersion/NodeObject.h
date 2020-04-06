#pragma once
#include <string>
using namespace std;
class NodeObject
{
public:
	string getWord();
	vector<int> getIntWord();
	NodeObject(vector<int> wordToStore);
	NodeObject() = default;
	void setWord(vector<int> wordToStore);

private:
	vector<int> word;
};

string NodeObject::getWord() {
	string toReturn;
	for (int i = 0; i < word.size(); i++) {
		toReturn += word[i];
	}
	cout << "Got word" << toReturn << "\n";
	return toReturn;
}

vector<int> NodeObject::getIntWord() {
	return word;
}

NodeObject::NodeObject(vector<int> wordToStore) {
	this->word = wordToStore;
}

void NodeObject::setWord(vector<int> wordToStore) {
	this->word = wordToStore;
}