#ifndef TEST_07_H
#define TEST_07_H

#include "assert.h"
#include "../json.h"

static void test_07(void) {
    json_object json_data_stack[5];
    char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "{\"key\":[]}");
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
    assert("[1].child == NULL: ", json_data_stack[1].child == NULL);
    assert("[1].size == 0: ", json_data_stack[1].size == 0);

    printf("\n\n");
}

#endif //TEST_07_H
