#include "Header.h"
#include <stack>
#include <string>

/*
Таблица замены и упращений
cos == o
sin == i
tg == a
ctg == c
exp == e
*/

std::string Polish_Notation(std::string& input)
{
	std::string chifri = "0123456789.x";
	std::string funk = "!@#$%", znaki_v = "*/", polish_notation, R = " ", znaki_n = "+-"; //У разных знаков , разный приоритет
	std::stack<char> st;
	int flag = 1, f = 0;

	st.push(input[0]);

	for (int i = 1; i < input.size(); ++i) {

		if (input[i] != ')') {

			if (flag) {
				if (in(input[i], chifri)) {
					polish_notation += input[i];
					flag = 0;
				}
			}

			if (flag) {

				if (in(input[i], funk)) {
					polish_notation += R;
					
					while (in(st.top(), funk)) {
						polish_notation += st.top();
						polish_notation += R;
						st.pop();
					}
					st.push(input[i]);
					flag = 0;
				}

				if (in(input[i], znaki_v)) {
					polish_notation += R;
					while (in(st.top(), znaki_v) or in(st.top(), funk)) {
						polish_notation += st.top();
						polish_notation += R;
						st.pop();
					}
					st.push(input[i]);
					flag = 0;
				}


				if (in(input[i], znaki_n)) {
					polish_notation += R;
					while (in(st.top(), znaki_v) or in(st.top(), funk) or in(st.top(), znaki_n)) {
						polish_notation += st.top();
						polish_notation += R;
						st.pop();
					}
					st.push(input[i]);
					flag = 0;
				}
			}

			if (flag) {
				if (input[i] == '(') {
					st.push('(');
				}
			}

			flag = 1;
		}

		else {
			while (st.top() != '(') {
				polish_notation += R;
				polish_notation += st.top();
				st.pop();
			}
			polish_notation += R;
			st.pop();
		}
	}
	return polish_notation;
}
