#include <iostream>
#include <unordered_set>
#include <vector>
using std::string;
using std::vector;

bool permPalindrome(string& test) {
	if (test.size() == 0) return false;
	if (test.size() == 1) return true;

	

	//even palindrome; perfect mirror b/w middle chars x**x (even number of each char)
	//odd palindrome: mirror at middle char: **x** (even number + one differrence)
	vector<int> table(128, 0);

	for (auto c: test) {
		table[c]++;
	}

	bool foundOdd = false;
	for (auto el: table) {
		if (el & 1) {
			if (foundOdd) return false;
			foundOdd = true;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Use: ./permPalindrome.out <string> ";
		return 1;
	}

	string test(argv[1]);

	if (permPalindrome(test)) {
		std::cout << test << " is a permutation of a palindrome";
	} else {
		std::cout << test << " not a perm of palindorme";
	}
	return 0;
}