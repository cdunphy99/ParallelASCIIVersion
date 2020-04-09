#pragma once
#include <string>
using namespace std;
class NodeObject
{
public:
	string getWord();
	//int* getIntWord();
	NodeObject(string wordToStore);
	NodeObject() = default;
	void setWord(string wordToStore);

private:
	string word;

};

string NodeObject::getWord() {
	return this->word;
}

//int NodeObject::getIntWord() {
//	return word;
//}

NodeObject::NodeObject(string wordToStore) {
	this->word = wordToStore;
}

void NodeObject::setWord(string wordToStore) {
	this->word = wordToStore;
}