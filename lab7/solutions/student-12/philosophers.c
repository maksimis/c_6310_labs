#include <pthread.h> // для потоков и мьютексов
#include <stdio.h> // для printf()
#include <unistd.h> // для usleep()

//макросы
// компилятор до компиляции заменит NUM_PHILOSOPHERS на 5
#define NUM_PHILOSOPHERS 5 // количество философов
#define MEALS_COUNT 3 // количество циклов еды

// состояние философа
// enum - пользовательский тип данных, набор именованных целочисленных констант
typedef enum e_state // typedef чтобы писать t_state вместо enum e_state
{
    THINKING, // = 0(по умолчанию)
    HUNGRY, // = 1
    EATING // = 2
}   t_state;

// какие вилки у философа
// флаговый enum
typedef enum e_philo_flags
{
    PHILO_NONE      = 0,      // 0000, нет вилок
    // << - побитовый сдвиг влево на один
    PHILO_HAS_LEFT  = 1 << 0, // 0001, флаг левой вилки
    PHILO_HAS_RIGHT = 1 << 1  // 0010, флаг правой вилки
    // значения можно комбинировать: 0011 - значит у философа обе вилки
}   t_philo_flags;

// структура философа
// struct - набор переменных внутри одного объекта.
typedef struct s_philosopher
{
    int             id; // номер философа
    t_state         state; // состояние философа
    t_philo_flags   flags; // флаги вилок (0000, 0001, 0010, 0011)
    pthread_t       thread; // pthread_t - тип потока, thread - сам поток философа
    pthread_mutex_t *left_fork; // pthread_mutex_t - тип мьютекса, left_fork - адрес левой вилки
    pthread_mutex_t *right_fork; // pthread_mutex_t *right_fork - адрес правой вилки
}   t_philosopher;

void    think(t_philosopher *philo) // в аргументах указатель на философа, в philo хранится адрес философа в памяти
{
    philo->state = THINKING; // -> доступ к полю структуры через указатель, state - поле состояния, присваивается состояние "THINKING"
    printf("Philosopher %d is THINKING\n", philo->id); // %d - место для числа
    usleep(300000); // пауза на 300000 микросекунд
}

// функция захвата вилок
void    take_forks(t_philosopher *philo) // в аргументах указатель на философа, в philo хранится адрес философа в памяти
{
    if (philo->id % 2 == 0) // четные берут сначала левую, потом правую
    {
        pthread_mutex_lock(philo->left_fork); // захват мьютекса (левой вилки), если мьютекс занят, то потом ждет
        philo->flags |= PHILO_HAS_LEFT; // |= побитовое OR с присваиванием, было 0000 станет 0001
        printf("Philosopher %d took LEFT fork\n", philo->id); // %d - место для числа

        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took RIGHT fork\n", philo->id);
    }
    else // нечетные берут сначала правую, потом левую
    {
        pthread_mutex_lock(philo->right_fork);
        philo->flags |= PHILO_HAS_RIGHT;
        printf("Philosopher %d took RIGHT fork\n", philo->id);

        pthread_mutex_lock(philo->left_fork);
        philo->flags |= PHILO_HAS_LEFT;
        printf("Philosopher %d took LEFT fork\n", philo->id);
    }
}

void    eat(t_philosopher *philo) // в аргументах указатель на философа, в philo хранится адрес философа в памяти
{
    philo->state = HUNGRY; // -> доступ к полю структуры через указатель, state - поле состояния, присваивается состояние "HUNGRY"
    printf("Philosopher %d is HUNGRY\n", philo->id); // %d - место для числа

    take_forks(philo);

    philo->state = EATING;
    printf("Philosopher %d is EATING\n", philo->id); 

    usleep(300000); // пауза на 300000 микросекунд
}

void    put_forks(t_philosopher *philo) // в аргументах указатель на философа, в philo хранится адрес философа в памяти
{
    // проверка, есть левая вилка у философа
    if (philo->flags & PHILO_HAS_LEFT) // -> доступ к полю структуры через указатель, & - побитовое AND. 0011 & 0001 = 0001
    {
        // если результат побитового сравнения не 0, значит левая вилка есть
        pthread_mutex_unlock(philo->left_fork); // функция освобождения мьютекса, то есть философ кладет левую вилку
        // убрираем флаг левой вилки
        philo->flags &= ~PHILO_HAS_LEFT; // ~ это побитовое НЕ, ивертирует биты. 0001 станет 1110. &= - побитовое AND. 0011 & 1110 = 0010 (левая вилка удалена, правая осталась)
    }

    // проверка, есть правая вилка у философа
    if (philo->flags & PHILO_HAS_RIGHT)
    {
        pthread_mutex_unlock(philo->right_fork);
        philo->flags &= ~PHILO_HAS_RIGHT;
    }

    printf("Philosopher %d put forks\n", philo->id); // %d - место для числа
}

void    *philosopher_routine(void *arg) // аргумент — универсальный указатель
{
    t_philosopher  *philo; // указатель на философа
    int             meals; // счётчик еды

    philo = (t_philosopher *)arg; // из void * в t_philosopher *
    meals = 0;

    while (meals < MEALS_COUNT) // пока 3 раза не поест
    {
        think(philo); // думает
        eat(philo); // голодный - берет вилки - ест
        put_forks(philo); // кладет вилки
        meals++;
    }

    return (NULL);
}

int main(void)
{
    pthread_mutex_t forks[NUM_PHILOSOPHERS]; // массив мьютексов, имя[размер]. один мьютекс - одна вилка
    t_philosopher   philosophers[NUM_PHILOSOPHERS]; // массив философов 
    int             i;

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        // pthread_mutex_init - инициализация мьютекса
        pthread_mutex_init(&forks[i], NULL); // & это взять адрес, forks[i] конкретная вилка
        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS)
    {
        // создание каждого философа philosophers[i]
        philosophers[i].id = i + 1;
        philosophers[i].state = THINKING;
        philosophers[i].flags = PHILO_NONE;

        philosophers[i].left_fork = &forks[i]; // показываем где находится его левая вилка
        philosophers[i].right_fork =
            &forks[(i + 1) % NUM_PHILOSOPHERS]; // показываем где находится его правая вилка, стол круглый поэтому для 4-го философа будет нулевая вилка

        // создание потока, каждый философ - отдельный поток
        pthread_create(
            &philosophers[i].thread, // куда сохранить поток, в поле структуры философа.
            NULL, // стандартные настройки потока
            philosopher_routine, // какая функция будет выполняться потоком
            &philosophers[i] // что передается потоку, передаём адрес философа
        );

        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS) // цикл ожидания потоков
    {
        // pthread_join - ждать завершения потока, чтобы main не закончился раньше потоков 
        pthread_join(philosophers[i].thread, NULL); // philosophers[i].thread - конкретный поток
        i++;
    }

    i = 0;
    while (i < NUM_PHILOSOPHERS) // уничтожение мьютексов
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }

    return (0);
}