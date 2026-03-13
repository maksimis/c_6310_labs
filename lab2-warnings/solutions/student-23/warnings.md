# Отчет о предупреждениях
Студент: 23
Задание: 24 (Проверка вхождения подстроки в строку)

## Предупреждения -Wall

### 1. Неиспользуемая статическая функция
- Строка: 17
- Код: static void func() { }
- Текст предупреждения: warning: 'func' defined but not used [-Wunused-function]
- Объяснение: Функция объявлена как static, что ограничивает её видимость текущим файлом, но функция нигде не вызывается.

### 2. Отсутствие return в функции
- Строка: 21
- Код: int get_number() {
    int value = 42;
}
- warning: control reaches end of non-void function [-Wreturn-type]
- Объяснение: Функция объявлена как возвращающая int, но не содержит оператора return.

### 3. Неиспользуемый параметр функции
- Строка: 27
- Код: int contains_substring(const wchar_t *text, const wchar_t *substring, int flag)
- Текст предупреждения: warning: unused parameter 'flag' [-Wunused-parameter]
- Объяснение: Параметр flag передается в функцию, но не используется внутри нее.

### 4. Неиспользуемая переменная
- Строка: 33
- Код: int unused_global = 42;
- Текст предупреждения: warning: unused variable 'unused_global' [-Wunused-variable]
- Объяснение: Переменная объявлена в функции contains_substring(), но не используется в дальнейшем коде.

### 5. Сравнение знакового и беззнакового типов
- Строка: 36
- Код: int a = -1;
unsigned int b = 5;
if (a < b) { }
- Текст предупреждения: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
- Объяснение: Сравнение знакового типа int с беззнаковым unsigned int может дать неожиданный результат.

### 6. Неиспользуемый параметр функции
- Строка: 41
- Код: int x;
printf("%d", x);
- Текст предупреждения: warning: 'x' is used uninitialized in this function [-Wuninitialized]
- Объяснение: Переменная x используется для вывода, но не была инициализирована.

### 7. Присваивание в условии
- Строка: 68
- Код: if (a = b)
- warning: suggest parentheses around assignment used as truth value [-Wparentheses]
- Объяснение: В условии if используется присваивание (=) вместо сравнения (==).

### 8. Сравнение знакового и беззнакового
- Строка: 75
- Код:char c = 2;
int arr[5] = {1,2,3,4,5};
int value = arr[c];
- Текст предупреждения: warning: array subscript has type 'char' [-Wchar-subscripts]
- Объяснение: Использование char в качестве индекса массива опасно, так как char может быть отрицательным.

### 9. Пустое тело условного оператора
- Строка: 83
- Код: if (x > 5);
- Текст предупреждения: warning: suggest braces around empty body in an 'if' statement [-Wempty-body]
- Объяснение: Тело условного оператора пустое из-за точки с запятой, что может указывать на ошибку.

### 10. Деление на ноль
- Строка: 89
- Код: int div_by_zero = 100 / 0;
- Текст предупреждения: warning: division by zero [-Wdiv-by-zero]
- Объяснение: Деление на ноль приводит к неопределенному поведению.

## Предупреждения -Wextra (бонус)

### 1. Сравнение с всегда истинным выражением
- Строка: 96
- Код: unsigned int u = 5; if (u >= 0)
- Текст предупреждения: warning: comparison of unsigned expression >= 0 is always true [-Wtype-limits]
- Объяснение: Для беззнакового типа условие u >= 0 всегда истинно.

### 2. Переменная присваивается, но не используется
- Строка: 104
- Код: int y = 10; y = 20;
- Текст предупреждения: warning: variable 'y' set but not used [-Wunused-but-set-variable]
- Объяснение: Переменной y присваиваются значения, но после этого она нигде не используется.

### 3. Переполнение при константных вычислениях
- Строка: 111
- Код: int y = 2147483647 + 1;
- Текст предупреждения: warning: integer overflow in expression [-Woverflow]
- Объяснение: Сложение максимального значения int с 1 приводит к переполнению.

### 4. Пропущены поля при инициализации структуры
- Строка: 116
- Код: struct Point p = {1, 2};
- Текст предупреждения: warning: missing initializer for field 'z' of 'struct Point' [-Wmissing-field-initializers]
- Объяснение: Структура Point имеет 3 поля (x, y, z), но инициализированы только первые два.

### 5. Сдвиг на количество бит, превышающее размер типа
- Строка: 128
- Код: return x << 100;
- Текст предупреждения: warning: shift count >= width of type [-Wshift-count-overflow]
- Объяснение: Сдвиг на 100 бит при размере int в 32 бита приводит к неопределенному поведению.