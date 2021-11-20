#ifndef TEST_13_H
#define TEST_13_H

#include "assert.h"
#include "../json.h"

static void test_13(void) {
    json_object json_data_stack[5];
    char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "{\"msgid\":\"17d009f6e1b\",\"topic\":\"get/value\",\"payload\":{}}");
    printf("--- Run %s ---\n", __FUNCTION__);
    printf(" Parse: %s\n\n", buffer);
    json_object *parsed = json_parse(buffer, strlen(buffer), json_data_stack, sizeof(json_data_stack) / sizeof(json_object));

    assert("parsed == &[0]: ", parsed == &json_data_stack[0]);

    assert("[0].key == NULL: ", json_data_stack[0].key == NULL);
    assert("[0].type == JSON_OBJECT: ", json_data_stack[0].type == JSON_OBJECT);
    assert("[0].parent == NULL: ", json_data_stack[0].parent == NULL);
    assert("[0].next == NULL: ", json_data_stack[0].next == NULL);
    assert("[0].child == &[1]: ", json_data_stack[0].child == &json_data_stack[1]);
    assert("[0].size == 3: ", json_data_stack[0].size == 3);

    assert("[1].key == \"msgid\": ", strcmp(json_data_stack[1].key, "msgid") == 0);
    assert("[1].type == JSON_STRING: ", json_data_stack[1].type == JSON_STRING);
    assert("[1].parent == &[0]: ", json_data_stack[1].parent == &json_data_stack[0]);
    assert("[1].next == &[2]: ", json_data_stack[1].next == &json_data_stack[2]);
    assert("[1].value == \"17d009f6e1b\": ", strcmp(json_data_stack[1].value, "17d009f6e1b") == 0);

    assert("[2].key == \"topic\": ", strcmp(json_data_stack[2].key, "topic") == 0);
    assert("[2].type == JSON_STRING: ", json_data_stack[2].type == JSON_STRING);
    assert("[2].parent == &[0]: ", json_data_stack[2].parent == &json_data_stack[0]);
    assert("[2].next == &[3]: ", json_data_stack[2].next == &json_data_stack[3]);
    assert("[2].value == \"get/value\": ", strcmp(json_data_stack[2].value, "get/value") == 0);

    assert("[3].key == \"payload\": ", strcmp(json_data_stack[3].key, "payload") == 0);
    assert("[3].type == JSON_OBJECT: ", json_data_stack[3].type == JSON_OBJECT);
    assert("[3].parent == &[0]: ", json_data_stack[3].parent == &json_data_stack[0]);
    assert("[3].next == NULL: ", json_data_stack[3].next == NULL);
    assert("[3].child == NULL: ", json_data_stack[3].child == NULL);
    assert("[3].size == 0: ", json_data_stack[3].size == 0);

    printf("\n\n");
}

#endif //TEST_13_H
