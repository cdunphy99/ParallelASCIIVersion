#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class permutations
{
public:
	vector<string> getPermutations(string s, int n);

private:
	vector<string> permutationList;
};

