# Консольная программа "Калькулятор"
   


## **Условие**

Программа принисает на вход математическое выражение состоящее из целых или вещеественных чисел, заков операций (+,-,*,/), скобок для задания приоритета операций, функций (sin, cos, tg, ctg, exp), а также может принимать переменную **х**. Если в строке будет **х** то программа должна попросиить ввести значение этой переменной.

## **Принцип работы программы**

Программа состоит из 9 файлов: файл [Header.h](/Header.h), содержащий объявление функций программы, файл [homework.cpp](/homework.cpp), содержащий функцию **main** и 7 файлоа в которых находятся функции программы.

Рассомтрим принцип работы функции main.
* Сначало мы проверяем не ввел ли пользователь недопустимые символы, причем только из тех, на которые мы заменим функции в будущем
* Если в входной строке есть **х**, то попросим пользователя ввести его значение
* Если ранее мы не нашли ошибку, то запустим функции [pre_obrabotka](pre_obrabotka.cpp) и [Error_Check](/Error_Check.cpp) (эта функция проверяет есть ли в веденной строке ошибки)
* Если [Error_Check](/Error_Check.cpp) не нашла ошибок, то запустим функцию [Polish_Notation](/Polish_Notation.cpp), преобразующую строку в форму обратной польской нотации. Затем [post_obrabotka](/post_obrabotka), она удалит лишние пробелы в строке. и функцию [Result](/Result.cpp), которая вичислит результат.
* Если [Error_Check](/Error_Check.cpp) найдет ошибку, то функции не будут запущены, а пользователь увидит соотвествующее сообщение.

Функции [in](/in.cpp) и [replace](/Replace.cpp), нужны для уменьшения объема кода.

## **Реализация функции преобработки входящей строки**

Функция **pre_obrabotka** заменяет все функции на соотвествующие спец сиволы(**это сделанно для того, чтобы все действия над числами имели однаковую длину и нам проще это было обрабатывать**), ставит в начало и в конец строки скобки, чтобы программа могла затем коректно реализовать обратную польскую нотацию, а также замену всех элементов "(-" на "(0-". это сделанно для тогго, чтобы прогрмма могла обрабатывать отрицательные числа, так как все отрицательные числа будут упираться в скобку слева, мы будет считать, что это не отрицательные числа а разность 0 и числа по модулю.

## **Реалиция алгоритма по преобразовании строки в форму обратной польской нотации**

Опишем алгоритм алгоритм преобразование строки в форму обратной польской нотации, причем все числа и знаки действий мы будем отделять пробелами.

Разобьем все операции на три группы в порядке приоритета, на третьем месте "+ -", на втором "* /", самая высокая степень прилритета у функций.

Функци циклом проходится по строке:
* Если мы нашли цифру или точку добавим её в строку ответ "**otv**"
* Если мы нашли знак действия то добавляем в строку все операции из стека, но только пока эта операция имеет не меньший проритет, чем та которую мы нашли. И кладем операцию (найденную операцию мы только добавляем в стек а не в итоговую строку) в стек. Пример:
```
if (in(input[i], znaki_v)) {    //мы нашли операцию * или /
   polish_notation += R;        // добавляем в итоговую строку разделитель, чтобы все операции и чмлса были отделены друг от друга
   while (in(st.top(), znaki_v) or in(st.top(), funk)) {// из стека берем и добавляем в строку все операции с не меньшим приоритетом, чем у найденной
      polish_notation += st.top();
      polish_notation += R;     // не забываем про разделители
      st.pop();                 // удаляем из стека взятую операцию
   }
   st.push(input[i]);           // кладем найденную операцию в стек
   flag = 0;                    // Вообще это была попытка в некоторую оптимизацию кода, однако проблемы с решением задачи заставили меня забыть о том что я тут в оптимизацию играю, так как это тут и осталось, лишь сверх  незначительно ускоряя программу
```
* Если нашли открывающую скобку добавляем в стек
* Если мы нашли закрывающую скобку, то пока в стеке не найдем открывающую скобку будем брать из стека знаки и добвлять в строку **otv**. В конце не забудем удалить открывающую скобку
Таким образом мы перепишем строку в форму обратной польской нотации

## **Реализация функции вычисления результата**
Кратко опишем алгоритм поиска результата, с помощью строки содержащий представление исходного математического выражения в образе обратной польской нотации.

Функци циклом проходится по строке:
* Так как числа и знаки действий разделены пробелами, то будем обрабатывать строку пока не встретим его или **х**.
* Если мы встретили цифру или точку мы будем добавлять их в промежуточную строчку prom_str, а также передадим флагу значение 1, оно озночает, что происходит создание строчки prom_str.
* Если мы встретим знак действия то применим его к двум числам лежащим в стеке, а результат вернем в стек.
* Если мы встретим пробел, то проверим значение флага. Если 1 это значит, что до этого мы нашли число и его необходимо положить в стек и обнулим флаг. Если 0, то ничего не произойдет и прогрмма перейдет к следующему элементу строки
* Если мы встретим **х**, то положим в стек ранне введенное его значение.

Таким образом к концу цикла в стеке останется только одно значение, которое и будет результатом вычисления.
