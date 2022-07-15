// we want basic compression using counts
// exa: aabcccccaaa is a2b1c5a3
// if original is shorter return shorter version
// contains only letters

#include <iostream>
#include <string>

std::string compressString(std::string test) {
	if (test.size() <= 1) return test;
	char currentLetter = test[0];
	int currentIndex = 0;
	std::string build = "";
	for (int i = 1; i < test.size(); i++) {
		if (test[i] == currentLetter) continue;
		build += currentLetter + std::to_string(i - currentIndex);
		currentLetter = test[i];
		currentIndex = i;
	}

	build += currentLetter + std::to_string(test.size() - currentIndex);

	return test.size() < build.size() ? test : build;
}



int main(int argc, char* argv[]) {
	std::string test(argv[1]);
	std::cout << "Input: " << test << std::endl;	

	std::string ans = compressString(test);
	std::cout << "Compressed String: " <<  ans << std::endl;
	return 0;
}
