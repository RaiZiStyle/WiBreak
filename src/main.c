#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/cJSON.h"
#include "../header/function.h"

// TODO: https://curl.se/libcurl/c/example.html
int main(int argc, char const *argv[]) {
    CURL *curl = NULL;
    struct curl_slist *headers = NULL;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Init failed\n");
        return EXIT_FAILURE;
    }

 
    // Set option
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_URL, "192.168.1.1/ws");
    headers = curl_slist_append(headers, "Authorization: X-Sah-Login");
    // headers = curl_slist_append(headers, "content-type: application/x-sah-ws-4-call+json");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    init_jsonData("toto29");

    // perform out action
    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        fprintf(stderr, "problem");
    }

    fprintf(stdout, "Result code : %d\n", result);

    // Close socket i guess
    curl_easy_cleanup(curl);
    return 0;
}
