#ifndef __ARGP__H
#define __ARGP__H
#include <argp.h>
#include <stdbool.h>

// static error_t parse_opt(int key, char *arg, struct argp_state *state)
extern struct argp argp;

struct arguments {
    // enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode;
    char *wordlist;
    char *url_to_query;
    // bool isCaseInsensitive;
};


#endif