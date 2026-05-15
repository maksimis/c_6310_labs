#include "txtfile.h"
#include <stdlib.h>

void free_lines(char **lines) {
  int i = 0;

  if (!lines)
    return;

  while (lines[i])
  {
    free(lines[i]);
    i++;
  }
  free(lines);
}