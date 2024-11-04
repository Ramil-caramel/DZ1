#include <iostream>
#include <stack>
#include "Header.h"
#include <string>


int main() {
    std::string input, a, eroor_numb, x = "!!";
    std::getline(std::cin, input);//так как сin работает с буфером до пробела , а пробел мы будем обрабатывать но как ошибку 
    setlocale(LC_ALL, "RU");
    
    if (in('x', input)) {
        std::cout << "Введите х ";
        std::cin >> x;
    }

    a = pre_obrabotka(input);
    eroor_numb = Error_Check(a);

    if (eroor_numb == "0") {
        a = Polish_Notation(a);
        a = post_obrabotka(a);

        std::cout << a << std::endl;
        std::cout << Result(a, x);
    }
    else {
        std::cout << eroor_numb;
    }
}