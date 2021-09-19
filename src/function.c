// Local include
#include "../header/function.h"

char *init_jsonData(char *password){
    cJSON *root = NULL;
    cJSON *child = NULL;
    char *json = NULL;
    cJSON *json_data = NULL;

    // Create JSON object
    root = cJSON_CreateObject();
    child = cJSON_CreateObject();
    
    if (!root || !child) {
        fprintf(stderr, "Error: cJSON_CreateObject failed.\n");
        goto cleanup;
    }
    
    cJSON_AddStringToObject(root, "service","sah.Device.Information");
    cJSON_AddStringToObject(root, "method","createContext");
    
    cJSON_AddStringToObject(child, "applicationName", "webui");
    cJSON_AddStringToObject(child, "username", "admin");
    cJSON_AddStringToObject(child, "password", password);

    //Link child to root
    cJSON_AddItemToObject(root, "parameters", child);
        
    json = cJSON_PrintUnformatted(root);
    if (!json) 
        goto cleanup;
    else
        printf("Json data : %s\n", json);

    
    return json;
cleanup:
        cJSON_Delete(root);
        free(json);
        printf("ERROR 128\n");
        return "ERROR 128";
}
