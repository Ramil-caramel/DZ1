#include <string>
#include "Header.h"
//!!!!!!!!!����� �������, ����� ��� ���� ���� ����������� ������� � �� ����� ���������� ������
/*
������� ������ � ���������
cos == o �
sin == i �
tg == a �
ctg == c �
exp == e �
*/

std::string pre_obrabotka(std::string &input){

	input = Replace(input, "cos", "�");
	input = Replace(input, "sin", "�");
	input = Replace(input, "exp", "�");
	input = Replace(input, "ctg", "�");
	input = Replace(input, "tg", "�");
	input = "(" + input + ")";
	input = Replace(input, "(-", "(0-");
	

	return input;
}