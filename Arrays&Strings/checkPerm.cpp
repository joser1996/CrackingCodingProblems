#include <iostream>
#include <unordered_set>
#include <vector>

bool testPerm(std::string f, std::string s) {
	if (f.size() != s.size()) return false;
	std::sort(f.begin(), f.end());
	std::sort(s.begin(), s.end());

	std::transform(f.begin(), f.end(), f.begin(),[](char c){return tolower(c);});
	std::transform(s.begin(), s.end(), s.begin(),[](char c){return tolower(c);});
	
	return f == s;
}

int main(int argc, char** argv) {
	std::string first = argv[1], second = argv[2];
	
	if (testPerm(first, second))
		std::cout << first << " and " << second << " are perms of each other!!" << std::endl;
	else
		std::cout << first << " and " << second << " are not perms :(" << std::endl;

	return 0;
}