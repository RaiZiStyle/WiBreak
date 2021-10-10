#include "../header/argp.h"

#include <argp.h>
#include <stdbool.h>
#include <string.h>

const char *argp_program_version = "WiBreak 0.0.1";
const char *argp_program_bug_address = "arthur.guyotpremel@gmail.com";
static char doc[] = "Program used to brute force URL.";
static char args_doc[] = "[FILENAME] [-u URL] [-w WORDLIST]";
static struct argp_option options[] = {
    {"url", 'u', 0, 0, "Compare lines instead of characters."},
    {"wordlist", 'w', 0, 0, "Compare words instead of characters."},
    {0}};



static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'u':
            arguments->url_to_query = arg;
            break;
        case 'w':
            arguments->wordlist = arg;
            break;
        case ARGP_KEY_ARG:
            return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};