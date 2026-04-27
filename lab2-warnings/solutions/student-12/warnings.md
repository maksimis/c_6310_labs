# Отчет о предупреждениях
Студент: 12
Задание: 13 (Сумма цифр числа)

## Предупреждения -Wall

### 1. Неиспользуемая функция
- Строка: 14
- Код:
```
static void unused_function() {
    int x = 5;
}
```
- Текст предупреждения: solutions/student-12/main.c:14:13: warning: 'unused_function' defined but not used [-Wunused-function]
- Объяснение: Функция объявлена, но ни разу не вызывается

### 2. Неиспользуемая переменная
- Строка: 30
- Код:
```
    int unused_variable = 10;
```
- Текст предупреждения: solutions/student-12/main.c:30:9: warning: unused variable 'unused_variable' [-Wunused-variable]
- Объяснение: Переменная объявлена, но нигде не используется

### 3. Использование неинициализированной переменной
- Строка: 34
- Код:
```
    int maybe_uninitialized;
    int test = maybe_uninitialized;
```
- Текст предупреждения: solutions/student-12/main.c:34:9: warning: 'maybe_uninitialized' is used uninitialized [-Wuninitialized]
- Объяснение: Переменная была объявлена, но не инициализирована перед использованием

### 4. Сравнение знакового и беззнакового типа
- Строка: 39
- Код:
```
    int a = -1;
    unsigned int b = 1;
    if (a < b) {
    }
```
- Текст предупреждения: solutions/student-12/main.c:39:11: warning: comparison of integer expressions of different signedness: 'int' and 'unsigned int' [-Wsign-compare]
- Объяснение: a — знаковое, b — беззнаковое, сравнение может привести к неожиданным результатам

### 5. Пустое тело if
- Строка: 43
- Код:
```
    if (sum > 100);
```
- Текст предупреждения: solutions/student-12/main.c:43:19: warning: suggest braces around empty body in an 'if' statement [-Wempty-body]
- Объяснение: Условие if ничего не выполняет; лучше добавить фигурные скобки для ясности

### 6. Вводящий в заблуждение отступ
- Строка: 46
- Код:
```
    if (sum > 50)
        printf("Большая сумма\n");
        printf("Это сообщение всегда выводится\n");
```
- Текст предупреждения: solutions/student-12/main.c:46:5: warning: this 'if' clause does not guard... [-Wmisleading-indentation]
- Объяснение: Вторая строка printf не находится внутри if, но выглядит как будто находится

### 7. Деление на ноль
- Строка: 52
- Код: 
```
    if (0) {
        int div_test = 10 / 0;
    }
```
- Текст предупреждения: solutions/student-12/main.c:52:27: warning: division by zero [-Wdiv-by-zero]
- Объяснение: Деление на ноль невозможно, это всегда ошибка выполнения

### 8. Использование char как индекса массива
- Строка: 57
- Код: 
```
    char index = 2;
    buffer[index] = 'a';
```
- Текст предупреждения: solutions/student-12/main.c:57:11: warning: array subscript has type 'char' [-Wchar-subscripts]
- Объяснение: Тип char может быть знаковым, что небезопасно при индексации массива

### 9. Присваивание внутри условия
- Строка: 60
- Код:
```
    if (a = 5) {
    }
```
- Текст предупреждения: solutions/student-12/main.c:60:9: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
- Объяснение: В условии используется присваивание вместо сравнения, что может быть ошибкой

### 10. Отсутствие return в функции
- Строка: 21
- Код:
```
int missing_return_function() {
    int a = 5;
}
```
- Текст предупреждения: solutions/student-12/main.c:21:1: warning: control reaches end of non-void function [-Wreturn-type]
- Объяснение: Функция возвращает int, но не содержит return


## Предупреждения -Wextra (бонус)

### 1. Сравнение, которое всегда истинно/ложно
- Строка: 65
- Код:
```
unsigned int u = 5;
if (u >= 0) {   // всегда true
}
```
- Текст предупреждения: solutions/student-12/main.c:65:11: warning: comparison of unsigned expression in '>= 0' is always true [-Wtype-limits]
- Объяснение: Любое беззнаковое число всегда >= 0, поэтому условие всегда истинно; предупреждение указывает на бессмысленное сравнение.

### 2. Возможно использование неинициализированной переменной
- Строка: 72
- Код:
```
int maybe;
int result;
if (number > 0) {
    result = maybe + 1; // maybe может быть неинициализирован
}
```
- Текст предупреждения: solutions/student-12/main.c:72:16: warning: 'maybe' may be used uninitialized [-Wmaybe-uninitialized]
- Объяснение: Переменная maybe не имеет начального значения перед использованием, что может привести к неопределенному поведению.

### 3. Переменная присвоена, но не используется
- Строка: 76
- Код:
```
int unused_var = 42;
```
- Текст предупреждения: solutions/student-12/main.c:76:9: warning: unused variable 'unused_var' [-Wunused-variable]
- Объяснение: Переменной присвоено значение, но оно нигде не используется; компилятор предупреждает о бесполезной переменной.

### 4. Параметр присвоен, но не используется
- Строка: 79
- Код:
```
void set_but_unused_param(int param) {
    param = 123; // присваивание, но параметр не используется
}
```
- Текст предупреждения: solutions/student-12/main.c:79:35: warning: parameter 'param' set but not used [-Wunused-but-set-parameter]
- Объяснение: Параметру присваивается значение внутри функции, но оно не используется; компилятор предупреждает о потенциально ненужном коде.

### 5. Сдвиг больше размера типа
- Строка: 84
- Код:
```
int shift_example = 1 << 32;
```
- Текст предупреждения: solutions/student-12/main.c:84:27: warning: left shift count >= width of type [-Wshift-count-overflow]
- Объяснение: В типе int обычно 32 бита, поэтому сдвиг на 32 или больше битов приводит к неопределенному поведению; компилятор предупреждает о потенциальной ошибке сдвига.
