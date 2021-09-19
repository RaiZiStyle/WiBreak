#ifndef __FUNCTION__H
#define __FUNCTION__H

// Lib include
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Local include
#include "cJSON.h"

char *init_payload(char *password);
int make_query(char *json_payload);
FILE *init_file(char *filename);
void print_usage();

#endif