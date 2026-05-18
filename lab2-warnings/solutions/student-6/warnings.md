# Отчёт о предупреждениях
**Студент:** 6  
**Задание:** 7 (Проверка числа на простоту)

## Предупреждения -Wall (10 типов)

### 1. Неиспользуемая переменная
- **Строка:** 45 (внутри `warn_unused_var`)
- **Код:** `int unused_local;`
- **Текст предупреждения:** `warning: unused variable 'unused_local' [-Wunused-variable]`
- **Объяснение:** Переменная объявлена, но нигде не используется.

### 2. Неиспользуемый параметр функции
- **Строка:** 50 (внутри `warn_unused_param`)
- **Код:** `static void warn_unused_param(int x) { }`
- **Текст предупреждения:** `warning: unused parameter 'x' [-Wunused-parameter]`
- **Объяснение:** Параметр функции `x` не используется внутри функции.

### 3. Неиспользуемая статическая функция
- **Строка:** 55 (функция `never_called`)
- **Код:** `static void never_called(void) { }`
- **Текст предупреждения:** `warning: 'never_called' defined but not used [-Wunused-function]`
- **Объяснение:** Статическая функция определена, но нигде не вызывается.

### 4. Отсутствие оператора return
- **Строка:** 60 (функция `missing_return`)
- **Код:** `static int missing_return(void) { }`
- **Текст предупреждения:** `warning: no return statement in function returning non-void [-Wreturn-type]`
- **Объяснение:** Функция объявлена как возвращающая `int`, но не содержит оператора `return`.

### 5. Сравнение знакового и беззнакового типов
- **Строка:** 67 (внутри `warn_sign_compare`)
- **Код:** `if (signed_val < unsigned_val)`
- **Текст предупреждения:** `warning: comparison between signed and unsigned integer expressions [-Wsign-compare]`
- **Объяснение:** Сравнение знакового `int` с беззнаковым `unsigned int` может привести к неожиданным результатам.

### 6. Использование неинициализированной переменной
- **Строка:** 75 (внутри `warn_uninitialized`)
- **Код:** `int b = a + 1;`
- **Текст предупреждения:** `warning: 'a' is used uninitialized in this function [-Wuninitialized]`
- **Объяснение:** Переменная `a` не инициализирована перед чтением.

### 7. Отсутствие скобок вокруг присваивания в условии
- **Строка:** 83 (внутри `warn_parentheses`)
- **Код:** `if (x = 5)`
- **Текст предупреждения:** `warning: suggest parentheses around assignment used as truth value [-Wparentheses]`
- **Объяснение:** Присваивание внутри условия `if` часто является опечаткой; скобки делают намерение явным.

### 8. Пустое тело оператора `if`
- **Строка:** 90 (внутри `warn_empty_body`)
- **Код:** `if (cond);`
- **Текст предупреждения:** `warning: empty body in an if-statement [-Wempty-body]`
- **Объяснение:** Точка с запятой сразу после `if` создаёт пустое тело, что может быть непреднамеренным.

### 9. Использование `char` в качестве индекса массива
- **Строка:** 97 (внутри `warn_char_subscript`)
- **Код:** `int val = arr[idx];`
- **Текст предупреждения:** `warning: array subscript has type 'char' [-Wchar-subscripts]`
- **Объяснение:** Использование `char` как индекса может быть проблематичным, так как `char` может быть знаковым, и отрицательные значения могут выходить за границы массива.

### 10. Подозрительное использование `sizeof` с указателем
- **Строка:** 105 (внутри `warn_sizeof_pointer`)
- **Код:** `memcpy(dest, ptr, sizeof(ptr));`
- **Текст предупреждения:** `warning: argument to 'sizeof' in 'memcpy' call is the same expression as the destination; did you mean to use the size of the pointed type? [-Wsizeof-pointer-memaccess]`
- **Объяснение:** `sizeof(ptr)` возвращает размер самого указателя, а не памяти, на которую он указывает. Это распространённая ошибка при копировании памяти.

---

## Предупреждения -Wextra (5 типов)

### 11. Сравнение, всегда истинное из-за ограничений типа
- **Строка:** 113 (внутри `warn_type_limits`)
- **Код:** `if (u >= 0)`
- **Текст предупреждения:** `warning: comparison of unsigned expression >= 0 is always true [-Wtype-limits]`
- **Объяснение:** Для беззнакового `unsigned int` условие `u >= 0` всегда истинно, что делает проверку избыточной.

### 12. Пропущенные инициализаторы полей структуры
- **Строка:** 122 (глобальная структура `warn_missing_field`)
- **Код:** `static struct S warn_missing_field = {1};`
- **Текст предупреждения:** `warning: missing initializer for field 'b' of 'struct S' [-Wmissing-field-initializers]`
- **Объяснение:** Список инициализации содержит значение только для первого поля, остальные остаются неинициализированными.

### 13. Переполнение в константном выражении
- **Строка:** 127 (внутри `warn_overflow`)
- **Код:** `int x = 2147483647 + 1;`
- **Текст предупреждения:** `warning: integer overflow in expression [-Woverflow]`
- **Объяснение:** Прибавление 1 к максимальному значению `int` вызывает неопределённое поведение из-за переполнения.

### 14. Сдвиг на количество бит, превышающее ширину типа
- **Строка:** 132 (внутри `warn_shift_overflow`)
- **Код:** `int x = 1 << 40;`
- **Текст предупреждения:** `warning: shift count >= width of type [-Wshift-count-overflow]`
- **Объяснение:** Сдвиг 32‑битного целого на 40 бит — неопределённое поведение.

### 15. Потенциальное нарушение выравнивания при приведении указателей
- **Строка:** 139 (внутри `warn_cast_align`)
- **Код:** `int *p = (int*)buffer;`
- **Текст предупреждения:** `warning: cast from 'char*' to 'int*' increases required alignment from 1 to 4 [-Wcast-align]`
- **Объяснение:** Приведение плохо выровненного `char*` к `int*` может привести к невыровненному доступу, что неэффективно или запрещено на некоторых архитектурах.