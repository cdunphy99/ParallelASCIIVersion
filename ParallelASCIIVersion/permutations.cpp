#include "permutations.h"

using namespace std;
vector<string> permutations::getPermutations(string s, int n)
{
	// sort the string in natural order
	sort(s.begin(), s.end());

	while (1)
	{
		// Print current permutation
		this->permutationList.push_back(s);

		/* below code will rearrange the string to next lexicographically
		 ordered permutation (if any) or return if we are already at
		 highest possible permutation */

		 // Find largest index i such that s[i-1] is less than s[i]
		int i = n - 1;
		while (s[i - 1] >= s[i])
		{
			// if i is first index of the string, we are already at last
			// possible permutation (string is sorted in reverse order)
			if (--i == 0)
				return permutationList;
		}

		// find highest index j to the right of index i such that 
		// s[j] > s[i�1] (s[i..n-1] is sorted in reverse order)

		int j = n - 1;
		while (j > i && s[j] <= s[i - 1])
			j--;

		// Swap characters at index i-1 with index j
		swap(s[i - 1], s[j]);

		// reverse the substring s[i..n-1] and return true
		reverse(s.begin() + i, s.end());
	}
}