# Отчет о предупреждениях
Студент: 18 Задание: 19 (Вычисление значения функции y = x² + 2x + 1)

## Предупреждения -Wall

### 1. Неиспользуемый результат выражения

- Строка: 11
- Код: ` x * 2;`
- Текст предупреждения: `warning: expression result unused [-Wunused-value]`
- Объяснение: Выражение `x * 2` вычисляет произведение, но результат нигде не сохраняется и не используется.

### 2. Отсутствие возвращаемого значения в функции 

- Строка: 12
- Код: `  }`
- Текст предупреждения: `warning: non-void function does not return a value [-Wreturn-type]`
- Объяснение: Функция объявлена как возвращающая значение типа int (не void), но в ней отсутствует оператор return. 

### 3. Неиспользуемая переменная

- Строка: 16
- Код: ` int x = 1;`
- Текст предупреждения:` warning: unused variable 'x' [-Wunused-variable]`
- Объяснение: Переменная x объявлена и инициализирована значением 1, но нигде в функции не используется. 

### 4. Избыточный спецификатор объявления 

- Строка: 20
- Код: ` const int const signed_value = -5;`
- Текст предупреждения: `warning: duplicate 'const' declaration specifier [-Wduplicate-decl-specifier]`
- Объяснение: Ключевое слово const указано дважды в объявлении переменной. Это избыточно и не влияет на смысл кода, но ухудшает его читаемость. 

### 5. Функция без прототипа

- Строка: 32
- Код:   `int function(p)`
- Текст предупреждения: `warning: a function definition without a prototype is deprecated in all versions of C and is not supported in C23 [-Wdeprecated-non-prototype]`
- Объяснение: Функция определена в старом стиле K&R (без прототипа), где параметры указаны без типов в списке аргументов. В современном C нужно указывать типы параметров непосредственно в скобках.

### 6. Тип char как индекс массива 

- Строка: 41
- Код: ` arr[c] = 42;`
- Текст предупреждения:` warning: array subscript is of type 'char' [-Wchar-subscripts]`
- Объяснение: Переменная типа char используется как индекс массива. Это опасно, потому что char может быть знаковым (signed) или беззнаковым (unsigned) в зависимости от платформы. Значения char могут быть отрицательными (от -128 до -1), что приведёт к обращению за границы массива.

### 7. Несоответствие указателей по знаковости

- Строка: 45
- Код: `signed char *signed_ptr = "hello";`
- Текст предупреждения: `warning: initializing 'signed char *' with an expression of type 'char[6]' converts between pointers to integer types where one is of the unique plain 'char' type and the other is not [-Wpointer-sign]`
- Объяснение: Строковый литерал "hello" имеет тип const char[], но присваивается указателю на signed char*. В C это разные типы: char, signed char и unsigned char.

### 8. Несоответствие указателей по знаковости 

- Строка: 46
- Код:  `unsigned char *unsigned_ptr = "world";`
- Текст предупреждения: `warning: initializing 'unsigned char *' with an expression of type 'char[6]' converts between pointers to integer types where one is of the unique plain 'char' type and the other is not [-Wpointer-sign]`
- Объяснение: Строковый литерал "hello" имеет тип const char[], но присваивается указателю на unsigned char*. В C это разные типы: char, signed char и unsigned char.

### 9. Переменной присваивается значение, но не используется

- Строка: 52
- Код:  `int unused;`
- Текст предупреждения: `warning: variable 'unused' set but not used [-Wunused-but-set-variable]`
- Объяснение: Переменной unused присваивается значение (unused = uninitialized в строке 56), но это значение никогда не читается в программе. 

### 10. Неинициализированная переменная 

- Строка: 56
- Код:  `unused = uninitialized;`
- Текст предупреждения: `warning: variable 'uninitialized' is uninitialized when used here [-Wuninitialized]`
- Объяснение: Переменная uninitialized используется в выражении, но не была инициализирована.

### 11. Неиспользуемая функция 

- Строка: 15
- Код: `static void unused_function(void)`
- Текст предупреждения: `warning: unused function 'unused_function' [-Wunused-function]`
- Объяснение: Статическая функция unused_function определена, но нигде не вызывается в программе.

### 12. Неиспользуемая переменная

- Строка: 45
- Код:  `signed char *signed_ptr = "hello";`
- Текст предупреждения:  `warning: unused variable 'signed_ptr' [-Wunused-variable]`
- Объяснение: Указатель signed_ptr объявлен и инициализирован, но нигде не используется в программе. Это приводит к неоправданному расходу памяти и создаёт "шум" в коде.

### 13. Неиспользуемая переменная

- Строка: 46
- Код: `unsigned char *unsigned_ptr = "world";`
- Текст предупреждения:  `warning: unused variable 'unsigned_ptr' [-Wunused-variable]`
- Объяснение: Указатель unsigned_ptr объявлен и инициализирован, но нигде не используется в программе. Это приводит к неоправданному расходу памяти и создаёт "шум" в коде.