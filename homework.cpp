#include <iostream>
#include <stack>
#include "Header.h"
#include <string>


int main() {
    std::string input, a, er = "0", x, alf = "!@#$%", z;
    std::getline(std::cin, input);//так как сin работает с буфером до пробела , а пробел мы будем обрабатывать но как ошибку 
    setlocale(LC_ALL, "RU");

    //чтобы пользователь не мог ввести спец символы которыми мы замением функции обработаем это как ошибку заранее
    for (int i = 0; i < input.size() - 1; ++i) {
        if (in(input[i], alf)) {
            std::cout << "недопустимый знак, ошибка в названии функции";
            er = "1";
        }
    }

    //попросим пользователя ввести х если он вообще есть
    if (in('x', input)) {
        std::cout << "Введите х ";
        std::cin >> x;
    }
    //если программа не выдала начальную ошибку запускаем основной блок функций
    if (er == "0") {

        a = pre_obrabotka(input);

        z = Error_Check(a);
        //если ошибок нет то можно вычислить результат
        if (z == "0") {
            a = Polish_Notation(a);

            a = post_obrabotka(a);

            std::cout << a << std::endl;
            std::cout << Result(a, x);
        }
        else {
            std::cout << z;
        }
    }
    
}
