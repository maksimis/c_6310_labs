Отчет о предупреждениях

Студент: 1
Задание: Анализ предупреждений компилятора

Предупреждения -Wall
1. Неиспользуемая функция

Строка: 4
Код:

void old_function() {
    int a = 5;
}

Текст предупреждения:
warning: ‘old_function’ defined but not used [-Wunused-function]
Объяснение:
Функция объявлена и определена, но нигде в программе не вызывается.

2. Неиспользуемая переменная

Строка: 10
Код:

int unused = 100;

Текст предупреждения:
warning: unused variable ‘unused’ [-Wunused-variable]
Объяснение:
Переменная объявлена и инициализирована, но не используется в программе.

3. Использование неинициализированной переменной

Строка: 14
Код:

int x;
if (x > 10)

Текст предупреждения:
warning: ‘x’ is used uninitialized [-Wuninitialized]
Объяснение:
Переменная используется в условии до присвоения ей начального значения.

4. Лишний аргумент функции printf

Строка: 23
Код:

printf("Поиск максимума\n", 123);

Текст предупреждения:
warning: too many arguments for format [-Wformat-extra-args]
Объяснение:
В строке формата отсутствуют спецификаторы, но передан дополнительный аргумент.

5. Выход за границы массива

Строка: 26
Код:

int temp = array[10];

Текст предупреждения:
warning: array subscript is above array bounds [-Warray-bounds]
Объяснение:
Размер массива равен 6, обращение к элементу с индексом 10 приводит к неопределённому поведению.

6. Присваивание вместо сравнения

Строка: 30
Код:

if (array[i] = maxn)

Текст предупреждения:
warning: suggest parentheses around assignment used as truth value [-Wparentheses]
Объяснение:
В условии используется оператор присваивания =, а не сравнения ==.

7. Неправильный спецификатор формата

Строка: 39
Код:

printf("Максимум: %f\n", maxn);

Текст предупреждения:
warning: format ‘%f’ expects argument of type ‘double’, but argument has type ‘int’ [-Wformat=]
Объяснение:
Спецификатор %f предназначен для типа double, а передаётся значение типа int.

8. Пустое тело цикла

Строка: 42
Код:

for (int i = 0; i < 5; i++);

Текст предупреждения:
warning: this ‘for’ clause does not guard... [-Wmisleading-indentation]
Объяснение:
Из-за точки с запятой цикл не содержит выполняемых операторов.

9. Сравнение знакового и беззнакового типов

Строка: 46
Код:

if (leng > u)

Текст предупреждения:
warning: comparison of integer expressions of different signedness [-Wsign-compare]
Объяснение:
Переменная leng имеет знаковый тип int, а u — беззнаковый unsigned int.

10. Неиспользуемая переменная

Строка: 52
Код:

int another_unused = 42;

Текст предупреждения:
warning: unused variable ‘another_unused’ [-Wunused-variable]
Объяснение:
Переменная объявлена, но нигде далее не используется.

Предупреждения -Wextra (бонус)
1. Неиспользуемая переменная внутри функции

Строка: 5
Код:

int a = 5;

Текст предупреждения:
warning: unused variable ‘a’ [-Wunused-variable]
Объяснение:
Локальная переменная объявлена, но не используется.

2. Использование присваивания в условии

Строка: 30
Код:

if (array[i] = maxn)

Текст предупреждения:
warning: using the result of an assignment as a condition without parentheses [-Wextra]
Объяснение:
Компилятор дополнительно предупреждает о потенциальной логической ошибке.

3. Переменная может быть неинициализирована

Строка: 14
Код:

int x;

Текст предупреждения:
warning: ‘x’ may be used uninitialized [-Wmaybe-uninitialized]
Объяснение:
Компилятор не гарантирует, что переменной будет присвоено значение перед использованием.

4. Пустой цикл

Строка: 42
Код:

for (int i = 0; i < 5; i++);

Текст предупреждения:
warning: empty body in an if/for/while statement [-Wempty-body]
Объяснение:
Цикл выполняется без полезных действий.

5. Сравнение разных типов

Строка: 46
Код:

if (leng > u)

Текст предупреждения:
warning: comparison between signed and unsigned integer expressions [-Wextra]
Объяснение:
Дополнительное предупреждение о возможных ошибках при неявных преобразованиях типов.