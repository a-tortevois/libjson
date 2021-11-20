#ifndef TEST_15_H
#define TEST_15_H

#include "assert.h"
#include "../json.h"

static void test_15(void) {
    json_object json_data_stack[12];
    char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "{\"payload\":[1,2,3,4,5,6,7,8,9]}");
    printf("--- Run %s ---\n", __FUNCTION__);
    printf(" Parse: %s\n\n", buffer);
    json_object *parsed = json_parse(buffer, strlen(buffer), json_data_stack, sizeof(json_data_stack) / sizeof(json_object));

    assert("parsed == &[0]: ", parsed == &json_data_stack[0]);
    json_object *payload = json_get(parsed, "payload");
    if (payload) {
        printf("\n Result:\n");
        json_object *obj = json_getFirst(payload);
        while (obj != NULL) {
            printf(" %s ", obj->value);
            obj = json_getNext(obj);
        }
        printf("\n");
    }

    printf("\n\n");
}

#endif //TEST_15_H
