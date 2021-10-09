// Standard lib
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Local lib
#include "../header/cJSON.h"
#include "../header/function.h"
#include "../header/argp.h"

// TODO: https://curl.se/libcurl/c/example.html
#include <argp.h>
#include <stdbool.h>



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

struct arguments {
    enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode;
    bool isCaseInsensitive;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'l':
            arguments->mode = LINE_MODE;
            break;
        case 'w':
            arguments->mode = WORD_MODE;
            break;
        case 'i':
            arguments->isCaseInsensitive = true;
            break;
        case ARGP_KEY_ARG:
            return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};

int main(int argc, char *argv[])
{
    struct arguments arguments;

    arguments.mode = CHARACTER_MODE;
    arguments.isCaseInsensitive = false;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    // ...
}