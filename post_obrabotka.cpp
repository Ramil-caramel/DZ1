#include <string>
#include "Header.h"
std::string post_obrabotka(std::string &input) {
	std::string empty;
	while (input[0] == ' '){
		input.replace(0, 1, empty);
	}
	if (input[input.size()-1] == ' ') {
		input.replace(input.size() - 1, 1, empty);
	}
	for (int i = 0; i < input.size() - 1; ++i) {
		if (input[i] == ' ' and input[i + 1] == ' ') {
			input.replace(i, 1, empty);
		}
	}
	return input;

}