#include <string>
#include "Header.h"
//!!!!!!!!!Ѕуквы русским, чтобы они типо были уникальными знаками и мы могли обработать ошибки
/*
“аблица замены и упращений
cos == o о
sin == i и
tg == a а
ctg == c с
exp == e е
*/

std::string pre_obrabotka(std::string &input){

	input = Replace(input, "cos", "о");
	input = Replace(input, "sin", "и");
	input = Replace(input, "exp", "е");
	input = Replace(input, "ctg", "с");
	input = Replace(input, "tg", "а");
	input = "(" + input + ")";
	input = Replace(input, "(-", "(0-");
	

	return input;
}