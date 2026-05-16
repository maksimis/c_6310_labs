#include "txtfile.h"

void free_lines(char **lines)
{
    size_t i;

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
