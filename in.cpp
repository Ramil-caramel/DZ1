#include <string>
#include "Header.h"
#include <string>

bool in(char a, std::string b) {
	bool otv = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (a == b[i]) {
			otv = 1;
			return otv;
			break;
		}
	}
	return otv;
}
