#include"Header.h"
#include <string>

std::string Replace(std::string input, std::string ubrat, std::string zamen) {
	std::string otv;
	int ch = 0;
	for (int i = 0; i < ubrat.size() - 1; ++i) {
		input += "!";//��� ������� ��� ��� ������ ��������� �� ������� ��������� ubrat.size() - 1 ��������, �� ��� �� �� ����� ����� ��� �� ��� �� ����� �� ��
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