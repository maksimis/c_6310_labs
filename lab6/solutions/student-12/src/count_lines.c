#include "txtfile.h"

int count_lines(char **lines)
{
    int count;

    if (!lines)
        return (-1);
    count = 0;
    while (lines[count])
        count++;
    return (count);
}