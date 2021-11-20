#ifndef TEST_11_H
#define TEST_11_H

#include "assert.h"
#include "../json.h"

static void test_11(void) {
    json_object json_data_stack[5];
    char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "{\"key\":[\"value_1\",\"value_2\"]}");
    printf("--- Run %s ---\n", __FUNCTION__);
    printf(" Parse: %s\n\n", buffer);
    json_object *parsed = json_parse(buffer, strlen(buffer), json_data_stack, sizeof(json_data_stack) / sizeof(json_object));

    assert("parsed == &[0]: ", parsed == &json_data_stack[0]);

    assert("[0].key == NULL: ", json_data_stack[0].key == NULL);
    assert("[0].type == JSON_OBJECT: ", json_data_stack[0].type == JSON_OBJECT);
    assert("[0].parent == NULL: ", json_data_stack[0].parent == NULL);
    assert("[0].next == NULL: ", json_data_stack[0].next == NULL);
    assert("[0].child == &[1]: ", json_data_stack[0].child == &json_data_stack[1]);
    assert("[0].size == 1: ", json_data_stack[0].size == 1);

    assert("[1].key == \"key\": ", strcmp(json_data_stack[1].key, "key") == 0);
    assert("[1].type == JSON_ARRAY: ", json_data_stack[1].type == JSON_ARRAY);
    assert("[1].parent == &[0]: ", json_data_stack[1].parent == &json_data_stack[0]);
    assert("[1].next == NULL: ", json_data_stack[1].next == NULL);
    assert("[1].child == &[2]: ", json_data_stack[1].child == &json_data_stack[2]);
    assert("[1].size == 2: ", json_data_stack[1].size == 2);

    assert("[2].key == NULL: ", json_data_stack[2].key == NULL);
    assert("[2].type == JSON_STRING: ", json_data_stack[2].type == JSON_STRING);
    assert("[2].parent == &[1]: ", json_data_stack[2].parent == &json_data_stack[1]);
    assert("[2].next == &[3]: ", json_data_stack[2].next == &json_data_stack[3]);
    assert("[2].value == \"value_1\": ", strcmp(json_data_stack[2].value, "value_1") == 0);

    assert("[3].key == NULL: ", json_data_stack[3].key == NULL);
    assert("[3].type == JSON_STRING: ", json_data_stack[3].type == JSON_STRING);
    assert("[3].parent == &[1]: ", json_data_stack[3].parent == &json_data_stack[1]);
    assert("[3].next == NULL: ", json_data_stack[3].next == NULL);
    assert("[3].value == \"value_2\": ", strcmp(json_data_stack[3].value, "value_2") == 0);

    printf("\n Result:\n");
    json_object *arr_key = json_get(parsed, "key");
    if (arr_key) {
        json_object *elem_0 = json_getArrayIndex(arr_key, 0);
        json_object *elem_1 = json_getArrayIndex(arr_key, 1);
        if (elem_0 && elem_0->value) {
            printf(" 0: %s\n", elem_0->value);
        }
        if (elem_1 && elem_1->value) {
            printf(" 1: %s\n", elem_1->value);
        }
    }

    printf("\n\n");
}

#endif //TEST_11_H
