#include "../inc/libft.h" // подключение заголовочного файла
#include <stdarg.h> // для вариативной функции (для va_list)
#include <unistd.h> // read (для чтения ввода) и _exit (для немедленного выхода из программы)

/* ------------- Блок объявлений и типов ------------- */

// Создание указателя на функцию (t_search_fn)
// любая функция, которая принимает две строки и возвращает int, теперь может называться t_search_fn, это нужно, чтобы мы могли передавать функции как обычные переменные
// typedef - сложный тип, int - вернется, t_search_fn - имя нового типа, * - указатель, аругменты - две строки: саму строка и шаблон (два указателя на символ (на адрес в памяти, где строка начинается))
typedef int (*t_search_fn)(const char *, const char *);

// Это структура-связка. Она соединяет текстовое название режима (например, "substr") с конкретной функцией, которая этот поиск выполняет
typedef struct s_mode
{
    char        *name; // первое поле — имя режима
    t_search_fn func; // второе поле — сама функция, здесь будет адрес одной из функций поиска (check_substr и т.д.)
}               t_mode; // краткое название

/* ------------- Блок функций-предикатов (Callback-и) ------------- */

// Ищет, встречается ли шаблон где угодно внутри строки
int check_substr(const char *str, const char *pattern)
{
    if (ft_strnstr(str, pattern, ft_strlen(str))) // ищет подстроку pattern внутри str, ft_strlen(str) — ограничение по поиску (ищем по всей длине строки)
        return (1);
    return (0);
}

// Сравнивает начало строки с шаблоном
int check_prefix(const char *str, const char *pattern)
{
    size_t len = ft_strlen(pattern);
    if (ft_strncmp(str, pattern, len) == 0) // Сравнивает str и pattern на длину len, если всё совпало возращает 0
        return (1);
    return (0);
}

// Сравнивает хвост строки с шаблоном
int check_suffix(const char *str, const char *pattern)
{
    size_t s_len = ft_strlen(str);
    size_t p_len = ft_strlen(pattern);
    if (s_len < p_len)
        return (0);
    if (ft_strncmp(str + (s_len - p_len), pattern, p_len) == 0) // str + (s_len - p_len) - начать не с начала строки str, а с (s_len - p_len)-го элемента
        return (1);
    return (0);
}

// превращает шаблон-строку в число и сравнивает его с длиной текущей строки
int check_len(const char *str, const char *pattern)
{
    int expected_len = ft_atoi(pattern); // строку в число
    return ((int)ft_strlen(str) == expected_len); // ft_strlen возвращает тип size_t (большое целое число без знака)
}

/* ------------- Вариативная функция (Функция с ...) ------------- */

// для вывода ошибок
void    ft_error_log(int exit_code, int count, ...) // После переменной count может идти сколько угодно дополнительных аргументов любого типа
{
    va_list args; // создание указателя-курсора. Переменная, которая будет шагать по списку неизвестных аргументов (аргументы в памяти лежат друг за другом в ряд)
    va_start(args, count); // устанавливаем курсор. Чтобы начать отсчет сразу после переменной count
    while (count--)
    {
        char *s = va_arg(args, char *); // берет данные там, где сейчас стоит курсор. 2 аргм - какой тип данных там (строка (char *))
        // курсор автоматически сдвигается к следующему аргументу
        ft_putstr_fd(s, 2); // вывод в стандартный канал ошибок (stderr)
    }
    va_end(args); // закрываем список и очищаем курсор
    ft_putchar_fd('\n', 2);
    if (exit_code != 0) // если передали не 0, то программа не просто выведет ошибку, а сразу закроется
        _exit(exit_code);
}

/* ------------- Логика выбора ------------- */

// Функция крутит цикл и сравнивает то, что ввел пользователь (mode_str), с названиями в массиве
// Если находит совпадение, возвращает адрес функции, чтобы программа понимала, какую логику применять
t_search_fn get_mode_func(char *mode_str)
{
    static t_mode modes[] = { // static - чтобы массив не создавался бы заново при каждом вызове функции
        {"substr", check_substr},
        {"prefix", check_prefix},
        {"suffix", check_suffix},
        {"len", check_len},
        {NULL, NULL} // чтобы понять, где заканчивается массив
    };
    int i = 0;
    while (modes[i].name) // пока имя в текущей карточке не NULL
    {
        if (ft_strncmp(modes[i].name, mode_str, ft_strlen(modes[i].name) + 1) == 0) // ft_strlen(modes[i].name) + 1) - тут +1 чтобы полностью строку сравнить вместе с нулевым символом
            return (modes[i].func); // если совпало — отдаем адрес функции
        i++;
    }
    return (NULL);
}

/* ------------- База ------------- */

int main(int argc, char **argv)
{
    t_search_fn search; // переменная, которая будет хранить адрес функции поиска

    if (argc < 3) // потому что: имя программы, режим и шаблон
        ft_error_log(1, 2, "Usage: ", "./search <mode> <pattern> [strings...]");
    
    // argv[0] — это всегда имя программы, argv[1] — это режим (substr и т.д.), argv[2] — что именно ищем

    search = get_mode_func(argv[1]); // // идем в mode за нужной функцией
    if (!search)
        ft_error_log(1, 3, "Error: ", "Unknown mode '", argv[1], "'");

    if (argc > 3)
    {
        // Обработка строк из аргументов
        for (int i = 3; i < argc; i++)
        {
            if (search(argv[i], argv[2])) // вызываем выбранную функцию поиска
                ft_putendl_fd(argv[i], 1); // печатаем строку если нашли (если 1)
        }
    }
    else // если данные переданы через стандартный ввод (stdin)
    {
        char buf[1000];
        int ret;
        while ((ret = read(0, buf, 999)) > 0) // читаем из 0 канала (stdin)
        {
            buf[ret] = '\0'; // в конце прочитанного куска ставим конец
            char **lines = ft_split(buf, '\n'); // режем большой кусок на отдельные строки
            for (int i = 0; lines[i]; i++) // перебор каждой порезанной строки
            {
                if (search(lines[i], argv[2]))
                    ft_putendl_fd(lines[i], 1);
                free(lines[i]); // сразу чистим память за каждой строчкой
            }
            free(lines); // чистим память за самим массивом указателей
        }
    }
    return (0);
}