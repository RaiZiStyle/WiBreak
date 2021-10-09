#ifndef __FUNCTION__H
#define __FUNCTION__H

// Lib include
#include <curl/curl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Local include
#include "cJSON.h"



char *init_payload(char *password);
int make_query(char *json_payload, char *url);
FILE *init_file(char *filename);
void print_usage();

#endif