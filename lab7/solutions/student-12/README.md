# Лабораторная работа №5 — Сравнение матриц и анализ свойств (Вариант 4)
## Описание:   
Задача «обедающие философы» — это классическая задача синхронизации, предложенная Эдсгером Дейкстрой для демонстрации проблем совместного доступа к ресурсам и взаимных блокировок.

За круглым столом сидят 5 философов. Между каждыми двумя соседними философами лежит одна вилка, всего вилок тоже 5. Перед каждым философом стоит тарелка с блюдом, которое можно есть **только двумя вилками одновременно**. Поэтому для еды философ должен взять вилку слева от себя и вилку справа от себя.

Каждый философ циклически повторяет одно и то же поведение:

- думает;
- испытывает голод;
- пытается взять две вилки;
- ест;
- кладёт вилки обратно и снова начинает думать.

Проблема состоит в том, что вилки — общий ресурс. Если все философы одновременно возьмут по одной вилке и будут ждать вторую, возникнет взаимная блокировка (`deadlock`) — программа зависнет. Поэтому задача состоит не просто в создании потоков, а в корректной синхронизации доступа к вилкам так, чтобы философы могли есть и программа продолжала работать без deadlock.

## Структура итогового проекта:
```
lab7/
├── solutions/
│   └── student-12/
│       ├── philosophers.c
│       ├── README.md
│       └── philosophers.exe
├── README.md
└── check-list.md
```

## Сборка и запуск:
```bash
cd lab7/solutions/student-12
```
```bash
gcc philosophers.c -Wall -Wextra -Werror -pthread -o philosophers
```
```bash
./philosophers  
```

## Пример вывода програмы:
```
Philosopher 5 is THINKING
Philosopher 1 is THINKING
Philosopher 2 is THINKING
Philosopher 3 is THINKING
Philosopher 4 is THINKING
Philosopher 4 is HUNGRY
Philosopher 4 took LEFT fork
Philosopher 4 took RIGHT fork
Philosopher 4 is EATING
Philosopher 1 is HUNGRY
Philosopher 1 took RIGHT fork
Philosopher 1 took LEFT fork
Philosopher 1 is EATING
Philosopher 3 is HUNGRY
Philosopher 2 is HUNGRY
Philosopher 5 is HUNGRY
Philosopher 4 put forks
Philosopher 4 is THINKING
Philosopher 5 took RIGHT fork
Philosopher 5 took LEFT fork
Philosopher 5 is EATING
Philosopher 1 put forks
Philosopher 1 is THINKING
Philosopher 2 took LEFT fork
Philosopher 2 took RIGHT fork
Philosopher 2 is EATING
Philosopher 3 took RIGHT fork
Philosopher 1 is HUNGRY
Philosopher 1 took RIGHT fork
Philosopher 1 took LEFT fork
Philosopher 1 is EATING
Philosopher 3 took LEFT fork
Philosopher 3 is EATING
Philosopher 5 put forks
Philosopher 5 is THINKING
Philosopher 4 is HUNGRY
Philosopher 2 put forks
Philosopher 2 is THINKING
Philosopher 5 is HUNGRY
Philosopher 5 took RIGHT fork
Philosopher 5 took LEFT fork
Philosopher 5 is EATING
Philosopher 4 took LEFT fork
Philosopher 2 is HUNGRY
Philosopher 2 took LEFT fork
Philosopher 2 took RIGHT fork
Philosopher 2 is EATING
Philosopher 1 put forks
Philosopher 1 is THINKING
Philosopher 3 put forks
Philosopher 3 is THINKING
Philosopher 2 put forks
Philosopher 2 is THINKING
Philosopher 3 is HUNGRY
Philosopher 5 put forks
Philosopher 5 is THINKING
Philosopher 1 is HUNGRY
Philosopher 1 took RIGHT fork
Philosopher 1 took LEFT fork
Philosopher 1 is EATING
Philosopher 4 took RIGHT fork
Philosopher 4 is EATING
Philosopher 2 is HUNGRY
Philosopher 2 took LEFT fork
Philosopher 2 took RIGHT fork
Philosopher 2 is EATING
Philosopher 3 took RIGHT fork
Philosopher 5 is HUNGRY
Philosopher 5 took RIGHT fork
Philosopher 5 took LEFT fork
Philosopher 5 is EATING
Philosopher 4 put forks
Philosopher 4 is THINKING
Philosopher 1 put forks
Philosopher 5 put forks
Philosopher 4 is HUNGRY
Philosopher 2 put forks
Philosopher 3 took LEFT fork
Philosopher 3 is EATING
Philosopher 3 put forks
Philosopher 3 is THINKING
Philosopher 4 took LEFT fork
Philosopher 4 took RIGHT fork
Philosopher 4 is EATING
Philosopher 4 put forks
Philosopher 3 is HUNGRY
Philosopher 3 took RIGHT fork
Philosopher 3 took LEFT fork
Philosopher 3 is EATING
Philosopher 3 put forks
```

## Требования:
- [+] Программа компилируется без ошибок и предупреждений командой `gcc philosophers.c -Wall -Wextra -Werror -pthread -o philosophers`.
- [+] Создаются 5 потоков философов через `pthread_create()`.
- [+] Для вилок используется 5 мьютексов.
- [+] Состояние философа реализовано через обычный `enum`.
- [+] Для отслеживания вилок в руках философа используется флаговый `enum`.
- [+] Каждый философ корректно проходит состояния `THINKING`, `HUNGRY`, `EATING`.
- [+] При захвате и освобождении вилок корректно обновляются флаги `PHILO_HAS_LEFT` и `PHILO_HAS_RIGHT`.
- [+] Доступ к вилкам синхронизирован через `pthread_mutex_lock()` / `pthread_mutex_unlock()`.
- [+] Реализовано решение, предотвращающее deadlock.
- [+] Отсутствуют race condition при работе с общими ресурсами (вилки, состояние философов, вывод).
- [+] Все потоки корректно завершаются, `main` ожидает их через `pthread_join()`.
- [+] Все мьютексы корректно уничтожаются после завершения программы.
- [+] Программа не использует глобальные переменные.
- [+] Нет утечек памяти (`valgrind` показывает "All heap blocks were freed").
- [+] Код отформатирован, нет лишних включений заголовочных файлов.

## Критерии оценивания:
- [+] Созданы потоки философов через `pthread_create()`, программа корректно работает в многопоточном режиме
- [+] Для вилок используются мьютексы, доступ к общим ресурсам синхронизирован корректно
- [+] Использованы два перечисления: обычный `enum` для состояний философа и флаговый `enum` для вилок в руках философа
- [+] Реализовано решение без deadlock и race condition, все потоки завершаются корректно, `main` выполняет `pthread_join()`
- [+] Отсутствуют утечки памяти и корректно освобождаются/уничтожаются все ресурсы

### Штрафы:
- [-] Отсутствие обычного `enum` для состояний философа
- [-] Отсутствие флагового `enum` для вилок в руках философа
- [-] Отсутствие мьютексов или некорректная синхронизация — работа не принимается
- [-] Наличие deadlock или race condition при обычном запуске программы 
- [-] Утечки памяти или неуничтоженные мьютексы 
- [-] Использование глобальных переменных 
- [-] Программа не компилируется с флагами `-Wall -Wextra -Werror` и `-pthread`
