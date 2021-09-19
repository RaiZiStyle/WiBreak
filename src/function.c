// Local include
#include "../header/function.h"

int init_jsonData(const char *password){
    cJSON *root = NULL;
    char *json = NULL;
    root = cJSON_CreateObject();
    
    if (!root) {
        fprintf(stderr, "Error: cJSON_CreateObject failed.\n");
        goto cleanup;
    }
    
    cJSON_AddStringToObject(root, "service","sah.Device.Information");
    cJSON_AddStringToObject(root, "method","createContext");
    // cJSON_AddStringToObject(root, "service","sah.Device.Information")
    // cJSON_AddStringToObject(root, "service","sah.Device.Information")
    
        
    json = cJSON_PrintUnformatted(root);
    if (!json) 
        goto cleanup;
    else
        printf("Json data : %s\n", json);

    
    return 0;
cleanup:
        cJSON_Delete(root);
        free(json);
        printf("ERROR 128\n");
        return 128;
}
