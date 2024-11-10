#include <string>
#include "Header.h"
#include <stack>
#include <cmath> 

const double e = 2.71828;

double Result(std::string &input,std::string x) {
	std::stack<double> st;
	std::string chifri = "0123456789.",prom_str;
	double res, a, b, c;
	int flag_d = 0;
	

	for (int i = 0; i < input.size(); ++i) {
		if (input[i] != ' ' and input[i] != 'x') {
			if (in(input[i], chifri)) {
				prom_str += input[i];
				flag_d = 1;
			}
			else {
				switch (input[i]){
					case '*':
						b = st.top();
						st.pop();
						a = st.top();
						st.pop();
						st.push(a * b);
						break;
					case '+':
						b = st.top();
						st.pop();
						a = st.top();
						st.pop();
						st.push(a + b);
						break;
					case '-':
						b = st.top();
						st.pop();
						a = st.top();
						st.pop();
						st.push(a - b);
						break;
					case '/':
						b = st.top();
						st.pop();
						a = st.top();
						st.pop();
						st.push(a / b);
						break;
					case '!':
						b = st.top();
						st.pop();
						st.push(cos(b));
						break;
					case '@':
						b = st.top();
						st.pop();
						st.push(sin(b));
						break;
					case '#':
						b = st.top();
						st.pop();
						st.push(tan(b));
						break;
					case '$':
						b = st.top();
						st.pop();
						st.push(1/tan(b));
						break;
					case '%':
						b = st.top();
						st.pop();
						st.push(std::pow(e, b));
						break;
				}
			}
		}

		else {
			if (flag_d == 1) {
				st.push(std::stod(prom_str));
				prom_str = "";
				flag_d = 0;
			}
			if (input[i] == 'x') {
				st.push(std::stod(x));
			}
		}
	}
	res = st.top();
	return res;
}
