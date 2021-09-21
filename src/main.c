// Standard lib
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Getopt

// Local lib
#include "../header/cJSON.h"
#include "../header/function.h"

// TODO: https://curl.se/libcurl/c/example.html
int main(int argc, char const *argv[]) {
    char *url = NULL;
    char *filename = NULL;
    FILE *fp = NULL;
    int option = 0, return_code = 0;
    char line[256] = {0} ;
    char *json_payload = NULL;

    while ((option = getopt(argc, argv, "hu:f:")) != -1) {
        switch (option) {
            case 'u':
                url = malloc(sizeof(int) * strlen(optarg));
                strcpy(url, optarg);
                printf("Url : %s\n", url);
                break;
            case 'f':
                filename = malloc(sizeof(int) * strlen(optarg));
                strcpy(filename, optarg);
                printf("filename : %s\n", filename);
                // perimeter = 0;
                break;
            case 'h':
                // breadth = atoi(optarg);
                print_usage();
                break;
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }

    if (!url || !filename) {
        print_usage();
        exit(EXIT_FAILURE);
    }
    fp = init_file(filename);


    while (fgets(line, sizeof(line), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s\n", line);
        json_payload = init_payload(line); 
        return_code = make_query(json_payload);
        if (return_code == 200){
            printf("Password is : %s\n", line);
        }
        
    }

    return 0;
}
