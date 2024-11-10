#pragma once
#include <string>

std::string Error_Check(std::string);//проверяет на ошибки ввода

std::string pre_obrabotka(std::string&);// добавляет ( ) в начало и конец, а также переписывает отрицательные числа в форме +(0-1)modx так как там лишний - всплывает

std::string Polish_Notation(std::string&);// создает польскую нотацию

std::string post_obrabotka(std::string&);// доделывает польскую нотацию так как там встреччаются дополнительные лишние пробелы или их не кретичное отсутствие, а я не хочу усложнять алгоритм

double Result(std::string&,std::string);// по данной польской нотации выдает результат

bool in(char, std::string);//чтобы двойные циклы везде не писать

std::string Replace(std::string, std::string, std::string);
