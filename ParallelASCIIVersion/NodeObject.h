#pragma once
#include <string>
using namespace std;
class NodeObject
{
public:
	string getWord();
	int* getIntWord();
	NodeObject(int* wordToStore, int size);
	NodeObject() = default;
	void setWord(int* wordToStore, int size);

private:
	int* word;
	int len;

};

string NodeObject::getWord() {
	string toReturn;
	for (int i = 0; i < this->len; i++) {
		toReturn += word[i];
	}
	return toReturn;
}

int* NodeObject::getIntWord() {
	return word;
}

NodeObject::NodeObject(int* wordToStore, int size) {
	this->word = wordToStore;
	cout << "NodeObject constructor: updating len to " << size << "\n";
	this->len = size;
}

void NodeObject::setWord(int* wordToStore, int size) {
	this->word = wordToStore;
	cout << "NodeObject setWord(): updating len to " << size << "\n";
	this->len = size;
}