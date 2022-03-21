// Standard lib
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Local lib
#include "../header/argp.h"
#include "../header/cJSON.h"
#include "../header/function.h"

// TODO: https://curl.se/libcurl/c/example.html

int main(int argc, char *argv[]) {
    struct arguments arguments;
    
    FILE *wordlist_pt;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;


    // arguments.mode = CHARACTER_MODE;
    // arguments.isCaseInsensitive = false;
    arguments.wordlist = NULL;
    arguments.url_to_query = NULL;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    wordlist_pt = init_file(arguments.wordlist);

    while ((read = getline(&line, &len, wordlist_pt)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        printf("Query with password : %s\n", line);
        char *payload = init_payload(line);
        make_query(payload, arguments.url_to_query);

    }



    // ...
}