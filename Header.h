#pragma once
#include <string>

std::string Error_Check(std::string&);//��������� �� ������ �����

std::string pre_obrabotka(std::string&);// ��������� ( ) � ������ � �����, � ����� ������������ ������������� ����� � ����� +(0-1)modx ��� ��� ��� ������ - ���������

std::string Polish_Notation(std::string&);// ������� �������� �������

std::string post_obrabotka(std::string&);// ���������� �������� ������� ��� ��� ��� ������������ �������������� ������ ������� ��� �� �� ��������� ����������, � � �� ���� ��������� ��������

double Result(std::string&,std::string);// �� ������ �������� ������� ������ ���������

bool in(char, std::string);//����� ������� ����� ����� �� ������
std::string Replace(std::string, std::string, std::string);//!!!!!!!!!!!!!!!!!!!!!������
