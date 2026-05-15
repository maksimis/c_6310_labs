# Предупреждения -Wall

## 1. Отсутствие скобок в сложных выражениях
    - Строка: 15
    - Код: int c = a & b == 0;
    - Текст предупреждения: warning: suggest parentheses around comparison in operand of '&' [-Wparentheses]
    - Объяснение: Оператор == имеет приоритет выше, чем &, поэтому компилятор предлагает скобки, чтобы выражение было понятным
## 2. Деление на ноль
    - Строка: 18
    - Код: int div = 10 / 0;
    - Текст предупреждения: warning: division by zero [-Wdiv-by-zero]
    - Объяснение: Деление на 0 недопустимо и вызовет ошибку
## 3. Несоответствие указателей по знаковости
    - Строка: 22
    - Код: int *p = &u;
    - Текст предупреждения: warning: pointer targets in initialization of 'int *' from 'unsigned int *' differ in signedness [-Wpointer-sign]
    - Объяснение: Присваивание указателя на unsigned int в int * может привести к неправильной интерпретации данных
## 4. использование char как индекса массива
    - Строка: 27
    - Код: arr[index];
    - Текст предупреждения: warning: array subscript has type 'char' [-Wchar-subscripts]
    - Объяснение: Тип char может быть знаковым, и использование его в качестве индекса массива небезопасно
## 5. Вычисление результата, который не используется
    - Строка: 27
    - Код: arr[index];
    - Текст предупреждения: warning: statement with no effect [-Wunused-value]
    - Объяснение: Выражение ничего не делает, результат не используется
## 6. Вводящий в заблуждение отступ
    - Строка: 29
    - Код: if (a)
    - Текст предупреждения: warning: this 'if' clause does not guard... [-Wmisleading-indentation]
    - Объяснение: Вторая строка printf("") выглядит как часть if, но ею не является, поэтому отступ не нужен
## 7. Использование формата нулевой длины
    - Строка: 31
    - Код: printf("");
    - Текст предупреждения: warning: zero-length gnu_printf format string [-Wformat-zero-length]
    - Объяснение: Пустой формат printf не имеет смысла
## 8. Неиспользуемая переменная
    - Строка: 12
    - Код: int unUsed_var;
    - Текст предупреждения: warning: unused variable 'unUsed_var' [-Wunused-variable]
    - Объяснение: Переменная объявлена, но ни разу не используется в коде функции
## 9. Неиспользуемая статическая функция
    - Строка: 9
    - Код: static void unused_function(void) {}
    - Текст предупреждения: warning: 'unused_function' defined but not used [-Wunused-function]
    - Объяснение: Статическая функция определена, но не вызывается
## 10. Использование неинициализированной переменной 
    - Строка: 34
    - Код: printf("%d\n", uninit);
    - Текст предупреждения: warning: 'uninit' is used uninitialized [-Wuninitialized]
    - Объяснение: Переменная uninit объявлена, но перед использованием не присвоена