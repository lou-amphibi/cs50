/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Если в командной строке не 2 и не 3 аргумента, вернуть ошибку в stderr и дать на вывод сообщение о формате.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Преобразуем второй аргумент командной строки в целочисленное значение, n- количество чисел.
    int n = atoi(argv[1]);

    // Если есть необязательный аргумент, то берем его преобразованное целочисленное значение в качестве семени для генерации псевдослучайных чисел.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // Если необязательный аргумент не указан,берем в качестве семени текущее время.
    else
    {
        srand48((long int) time(NULL));
    }

    // Выводим все n чисел при помощи вызова функции генерации псевдослучайных чисел. Приводим их тип к целочисленому и умножаем на константу LIMIT.
    // Ни одно число не больше LIMIT. По умолчанию drand возвращает float, оно всегда меньше 1, что позволяет нам через умножение на LIMIT задать верхний порог.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48()* LIMIT));
    }

    // success
    return 0;
}