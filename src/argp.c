#include "../header/argp.h"

#include <argp.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const char *argp_program_version = "WiBreak 0.0.1";
const char *argp_program_bug_address = "arthur.guyotpremel@gmail.com";
static char doc[] = "Program used to brute force URL.";
static char args_doc[] = "[-u URL] [-w WORDLIST]";
static struct argp_option options[] = {
    {"url", 'u', "URL_TO_QUERY", 0, "Compare lines instead of characters [REQUIRED]."},
    {"wordlist", 'w', "WORDLIST", 0, "Compare words instead of characters [REQUIRED]."},
    {"verbose", 'v', 0, OPTION_ARG_OPTIONAL, "Show more info"},
    {0}};


// TODO: Need to handle when no argument are given.
static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    int *arg_cout = state->input;
    switch (key) {
        case 'u':
            arguments->url_to_query = arg;
            // printf("arg : %s\n", arg);
            break;
        case 'w':
            arguments->wordlist = arg;
            break;
        case 'v':
            arguments->verbose = 1;
            break;
        
        case ARGP_KEY_END:
            // printf("arguments->wordlist : %s, arguments->url_to_query : %s\n", arguments->wordlist, arguments->url_to_query);
            // Code never reach even when i initialyze arguments in the main.
            if (arguments->wordlist == NULL || arguments->url_to_query == NULL){
                argp_failure(state, 1, 0, "required -u and -w. See --help for more information");
                exit(ARGP_ERR_UNKNOWN);
            }

        default:
            // argp_usage(state);
            return ARGP_ERR_UNKNOWN;
    }
    
    return 0;
}

struct argp argp = {options, parse_opt, args_doc, doc};