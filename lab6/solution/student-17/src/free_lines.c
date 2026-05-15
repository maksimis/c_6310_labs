#include "../inc/txtfile.h"
#include <stdlib.h>

void free_lines(char **lines)
{
    int i;

    if (!lines)
        return;
    i = 0;
    while (lines[i])
    {
        free(lines[i]);
        i++;
    }
    free(lines);
}