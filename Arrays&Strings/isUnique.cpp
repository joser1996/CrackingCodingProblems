#include <iostream>
#include <unordered_set>
#include <vector>

bool isUnique(std::string test) {
	// std::unordered_set<char> mySet;
	// for (auto c : test) {
	// 	if (!mySet.insert(c).second) return false;
	// }
	// return true;

	// sort
	// std::sort(test.begin(), test.end());
	// for (int i = 1; i < test.size(); i++) {
	// 	if (test[i] == test[i - 1]) return false;
	// }
	// return true;


	//table
	std::vector<bool> table(128, false);
	for (auto c: test) {
		if (table[c]) return false;
		else table[c] = true;
	}
	return true;
}

int main(int argv, char** args) {
	std::string test(args[1]);
	if (isUnique(test)) {
		std::cout << "String: " << test << " is unique!" << std::endl;
	} else {
		std::cout << "String: " << test << " is not unique." << std::endl;
	}
	return 0;
}