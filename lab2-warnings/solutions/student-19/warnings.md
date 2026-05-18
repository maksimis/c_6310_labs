## Предупреждения -Wall

### 1. Неиспользуемая функция

Строка: 18
Код: static void unused_function()
Предупреждение: warning: ‘unused_function’ defined but not used [-Wunused-function]
Объяснение: функция объявлена, но нигде в программе не вызывается.

---

### 2. Отсутствие return

Строка: 24
Код: int missing_return_function()
Предупреждение: warning: control reaches end of non-void function [-Wreturn-type]
Объяснение: функция объявлена как возвращающая тип int, но оператор return отсутствует.

---

### 3. Неиспользуемый параметр

Строка: 31
Код: int unused_parameter_function(int x)
Предупреждение: warning: unused parameter ‘x’ [-Wunused-parameter]
Объяснение: параметр функции передаётся, но внутри функции не используется.

---

### 4. Неиспользуемая переменная

Строка: 86
Код: int unused_variable = 10;
Предупреждение: warning: unused variable ‘unused_variable’ [-Wunused-variable]
Объяснение: переменная объявлена, но далее в программе не используется.

---

### 5. Сравнение знакового и беззнакового типов

Строка: 91
Код: if (signed_number < unsigned_number)
Предупреждение: warning: comparison of integer expressions of different signedness [-Wsign-compare]
Объяснение: сравниваются переменные типов signed и unsigned.

---

### 6. Отсутствие скобок в логическом выражении

Строка: 101
Код: if (a < b && b < c || a == c)
Предупреждение: warning: suggest parentheses around ‘&&’ within ‘||’ [-Wparentheses]
Объяснение: компилятор рекомендует добавить скобки для повышения читаемости выражения.

---

### 7. Использование char как индекса массива

Строка: 109
Код: array[index] = 5;
Предупреждение: warning: array subscript has type ‘char’ [-Wchar-subscripts]
Объяснение: использование типа char как индекса массива может быть опасным, так как char может быть знаковым.

---

### 8. Несоответствие знаковости указателей

Строка: 114
Код: unsigned char *ptr = text;
Предупреждение: warning: pointer targets in initialization differ in signedness [-Wpointer-sign]
Объяснение: указатель unsigned char присваивается переменной типа char*.

---

### 9. Деление на ноль

Строка: 124
Код: int division = 10 / zero;
Предупреждение: warning: division by zero [-Wdiv-by-zero]
Объяснение: деление на переменную, значение которой равно нулю.

---

### 10. Вводящий в заблуждение отступ

Строка: 129

Код:
if (a > 0)
printf("");
printf("");

Предупреждение: warning: misleading indentation [-Wmisleading-indentation]
Объяснение: второй printf выглядит как часть if, но фактически выполняется всегда.

---

### 11. Пустое тело if

Строка: 135
Код: if (a == b);
Предупреждение: warning: suggest braces around empty body [-Wempty-body]
Объяснение: после условия стоит точка с запятой, поэтому тело оператора if пустое.

---

## Предупреждения -Wextra

### 1. Переменная присваивается, но не используется

Строка: 40
Код: x = 10;
Предупреждение: warning: variable ‘x’ set but not used [-Wunused-but-set-variable]
Объяснение: переменной присваивается значение, но она нигде далее не используется.

---

### 2. Пропущены поля структуры

Строка: 51
Код: struct Example example_struct = {1};
Предупреждение: warning: missing initializer for field [-Wmissing-field-initializers]
Объяснение: структура имеет три поля, но инициализируется только одно.

---

### 3. Условие всегда истинно

Строка: 57
Код: if (x >= 0)
Предупреждение: warning: comparison of unsigned expression >= 0 is always true [-Wtype-limits]
Объяснение: для беззнакового типа unsigned условие x >= 0 всегда истинно.

---

### 4. Переполнение при сдвиге

Строка: 65
Код: int x = 1 << 40;
Предупреждение: warning: shift count >= width of type [-Wshift-count-overflow]
Объяснение: выполняется сдвиг на количество бит, превышающее размер типа int.
