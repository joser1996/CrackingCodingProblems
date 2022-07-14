#include <iostream>
#include <unordered_set>
#include <vector>
using std::string;

void padding(string& test) {
	int spaces = 0;
	for (auto c: test) {
		if (c == ' ') spaces++;
	}
	
	test.resize(test.size() + (spaces * 3) - spaces, ' ');
}

void urilify(string& test, const int trueSize) {
	// std::cout << "True: " << trueSize;
	// std::cout <<"\tTest: " << test << std::endl;
	int i = trueSize - 1;
	int j = test.size() - 1;

	while (i >= 0) {
		if (test[i] == ' ') {
			test[j--] = '0';
			test[j--] = '2';
			test[j--] = '%';
			i--;
		} else {
			test[j--] = test[i--];
		}
		//std::cout << "i: " << i  << "\tj: " << j << "\t test: " << test << std::endl;
	}
}

int main(int argc, char* argv[]) {
	string test = argv[1];
	const int trueSize = test.size();
	padding(test);
	//std::cout << "Padded: " << test.size() << std::endl;

	urilify(test, trueSize);
	std::cout << "result: " << test << std::endl;
	return 0;
}