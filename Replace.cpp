#include"Header.h"
#include <string>

std::string Replace(std::string input, std::string ubrat, std::string zamen) {
	std::string otv;
	int ch = 0;
	for (int i = 0; i < ubrat.size() - 1; ++i) {
		input += "!";//это костыль так как иногда прогрмама не выводит последние ubrat.size() - 1 элементы, но так ка мы точно знаем что их там не будет то Ок
	}
	for (int i = 0; i < input.size() - ubrat.size() + 1; ++i) {
		for (int j = 0; j < ubrat.size(); ++j) {
			if (input[i] == ubrat[j]) {
				++ch;
				++i;
			}
		}
		if (ch == ubrat.size()) {
			otv += zamen;
			i -= 1;
		}
		else {
			i -= ch;
			otv += input[i];
		}
		ch = 0;
	}
	return otv;
}
