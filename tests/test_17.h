#ifndef TEST_17_H
#define TEST_17_H

#include "assert.h"
#include "../json.h"

static void test_17(void) {
    static json_object json_data_stack[226];
    static char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer,
           "{\"msgid\":\"17d009f6e1b\",\"topic\":\"testInteger\",\"payload\":{\"maxInt\":2147483647,\"minInt\":-2147483648}}");
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
    assert("[2].value == \"testInteger\": ", strcmp(json_data_stack[2].value, "testInteger") == 0);

    assert("[3].key == \"payload\": ", strcmp(json_data_stack[3].key, "payload") == 0);
    assert("[3].type == JSON_OBJECT: ", json_data_stack[3].type == JSON_OBJECT);
    assert("[3].parent == &[0]: ", json_data_stack[3].parent == &json_data_stack[0]);
    assert("[3].next == NULL: ", json_data_stack[3].next == NULL);
    assert("[3].child == &[4]: ", json_data_stack[3].child == &json_data_stack[4]);
    assert("[3].value == 2: ", json_data_stack[3].size == 2);

    assert("[4].key == \"maxInt\": ", strcmp(json_data_stack[4].key, "maxInt") == 0);
    assert("[4].type == JSON_INTEGER: ", json_data_stack[4].type == JSON_INTEGER);
    assert("[4].parent == &[3]: ", json_data_stack[4].parent == &json_data_stack[3]);
    assert("[4].next == &[5]: ", json_data_stack[4].next == &json_data_stack[5]);
    assert("[4].size == 2147483647: ", strcmp(json_data_stack[4].value, "2147483647") == 0);

    assert("[5].key == \"minInt\": ", strcmp(json_data_stack[5].key, "minInt") == 0);
    assert("[5].type == JSON_INTEGER: ", json_data_stack[5].type == JSON_INTEGER);
    assert("[5].parent == &[3]: ", json_data_stack[5].parent == &json_data_stack[3]);
    assert("[5].next == NULL: ", json_data_stack[5].next == NULL);
    assert("[5].value == -2147483648: ", strcmp(json_data_stack[5].value, "-2147483648") == 0);

    printf("\n\n");
}

#endif //TEST_17_H
