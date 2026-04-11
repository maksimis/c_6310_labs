Предупреждения -Wall(10 разных типов)

1. -Wunused-parameter
Строка: 13
Код: double sumArray(double arr[], int size, int extra) {
Текст предупреждения: warning: unused parameter 'extra' [-Wunused-parameter]
Объяснение: Параметр extra функции sumArray объявлен, но не используется в теле функции.

2. -Wsign-compare
Строка: 56
Код: if (signedVal < unsignedVal) {
Текст предупреждения: warning: comparison of integer expressions of different signedness: 'int' and 'unsigned int' [-Wsign-compare]
Объяснение: Сравниваются знаковая переменная signedVal и беззнаковая unsignedVal.

3. -Wparentheses
Строка: 62
Код: if (a > b > c) {
Текст предупреждения: warning: comparisons like 'X<=Y<=Z' do not have their mathematical meaning [-Wparentheses]
Объяснение: Выражение a > b > c вычисляется как (a > b) > c, что не соответствует математическому смыслу.

4. -Wempty-body
Строка: 67
Код: if (a == 5);
Текст предупреждения: warning: suggest braces around empty body in an 'if' statement [-Wempty-body]
Объяснение: После if (a == 5) стоит точка с запятой, что создает пустое тело условия.

5. -Wmisleading-indentation
Строка: 67-68
Код:
if (a == 5);
    printf("This always runs\n");
Текст предупреждения: warning: this 'if' clause does not guard... [-Wmisleading-indentation]
Объяснение: Из-за точки с запятой после if и отступа создается впечатление, что printf относится к условию.

6. -Wchar-subscripts
Строка: 73
Код: intArr[ch] = 100;
Текст предупреждения: warning: array subscript has type 'char' [-Wchar-subscripts]
Объяснение: В качестве индекса массива используется переменная типа char, что может привести к отрицательному индексу.

7. -Wunused-variable
Строка: 45
Код: int unusedVar = 42;
Текст предупреждения: warning: unused variable 'unusedVar' [-Wunused-variable]
Объяснение: Переменная объявлена и инициализирована, но нигде не используется.

8. -Wreturn-type
Строка: 24
Код: int getNumber()
Текст предупреждения: warning: control reaches end of non-void function [-Wreturn-type]
Объяснение: Функция getNumber объявлена как возвращающая значение типа int, но не содержит оператора return.

9. -Wunused-function
Строка: 27
Код: static void unusedHelper() { printf("This function is never called\n"); }
Текст предупреждения: warning: 'unusedHelper' defined but not used [-Wunused-function]
Объяснение: Статическая функция определена, но нигде не вызывается в программе.

10. -Wuninitialized
Строка: 49
Код: if (uninitVar > 0) {
Текст предупреждения: warning: 'uninitVar' is used uninitialized [-Wuninitialized]
Объяснение: Переменная uninitVar используется в условии if, но не была инициализирована.

Предупреждения -Wextra (5 разных типов)
1. -Wmissing-field-initializers
Строка: 76
Код: struct Point p = {10};
Текст предупреждения: warning: missing initializer for field 'y' of 'struct Point' [-Wmissing-field-initializers]
Объяснение: При инициализации структуры Point указано только значение для поля x. Поля y и z остаются неинициализированными.

2. -Wtype-limits
Строка: 80
Код: if (always >= 0) {
Текст предупреждения: warning: comparison of unsigned expression in '>= 0' is always true [-Wtype-limits]
Объяснение: Для беззнакового типа unsigned int условие always >= 0 всегда истинно и избыточно.

3. -Woverflow
Строка: 89
Код: int overflow = 1000000 * 1000000;
Текст предупреждения: warning: integer overflow in expression of type 'int' results in '-727379968' [-Woverflow]
Объяснение: Умножение 1 000 000 на 1 000 000 дает результат, превышающий максимальное значение для типа int.

4. -Wshift-count-overflow
Строка: 93
Код: int bigShift = shift << 100;
Текст предупреждения: warning: left shift count >= width of type [-Wshift-count-overflow]
Объяснение: Сдвиг влево на 100 бит при размере типа int в 32 бита превышает допустимое значение.

5. -Wunused-but-set-variable
Строка: 85
Код:
int x = 5;
x = 10;
Текст предупреждения: warning: variable 'x' set but not used [-Wunused-but-set-variable]
Объяснение: Переменной x присваиваются значения, но после этого она нигде не используется.
