#ifndef CREPL_SCANNER_H
#define CREPL_SCANNER_H

/**
 * Author: Akash Lohar
 *
 */

#include "str.h"
#include <stdbool.h>

typedef struct {
    str_t *source;
    int position;
    int next_position;
    char ch;
} scanner_t;

scanner_t *scanner_init(str_t *source);

#endif // CREPL_SCANNER_H