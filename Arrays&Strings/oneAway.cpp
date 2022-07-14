#include <iostream>
#include <unordered_set>
#include <vector>
using std::string;
using std::vector;

inline int min(int a, int b) {
	return a < b ? a : b;
}

int oneAway(string& one, string& two, int i, int j) {

	if (i < 0)
		return j < 0 ? 0 : j + 1;
	if (j < 0)
		return i < 0 ? 0 : i + 1;

	if (one[i] == two[j]) {
		return oneAway(one, two, i - 1, j - 1);
	} else {
		int ins = oneAway(one, two, i - 1, j);
		int del = oneAway(one, two, i, j - 1);
		int rep = oneAway(one ,two, i - 1, j - 1);
		return 1 + min(ins, min(del, rep));
	}


	return 0;
}

int main(int argc, char* argv[]) {
	string one(argv[1]);
	string two(argv[2]);
	int ans = oneAway(one, two, one.size()-1, two.size() - 1);
	std::cout << "ans: " << ans << std::endl;
	if (ans <= 1) {
		std::cout << one << " and " << two << " are one edit away.";
	} else {
		std::cout << one << " and " << two << " are more than one edit away";
	}

	return 0;
}