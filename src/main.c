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






int main(int argc, char *argv[])
{
    struct arguments arguments;

    // arguments.mode = CHARACTER_MODE;
    // arguments.isCaseInsensitive = false;
    arguments.wordlist = "";
    arguments.url_to_query = "";

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    printf("Wordlist : %s, Url : %s\n", arguments.wordlist, arguments.url_to_query);
    // ...
}