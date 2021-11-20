#ifndef TEST_14_H
#define TEST_14_H

#include "assert.h"
#include "../json.h"

static void test_14(void) {
    json_object json_data_stack[12];
    char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "{\"msgid\":\"17d009f6e1b\",\"topic\":\"set/value\",\"payload\":{\"i\":[\"3\",\"5\"],\"v\":[4,6]}}");
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
    assert("[2].value == \"set/value\": ", strcmp(json_data_stack[2].value, "set/value") == 0);

    assert("[3].key == \"payload\": ", strcmp(json_data_stack[3].key, "payload") == 0);
    assert("[3].type == JSON_OBJECT: ", json_data_stack[3].type == JSON_OBJECT);
    assert("[3].parent == &[0]: ", json_data_stack[3].parent == &json_data_stack[0]);
    assert("[3].next == NULL: ", json_data_stack[3].next == NULL);
    assert("[3].child == &[4]: ", json_data_stack[3].child == &json_data_stack[4]);
    assert("[3].size == 2: ", json_data_stack[3].size == 2);

    assert("[4].key == \"i\": ", strcmp(json_data_stack[4].key, "i") == 0);
    assert("[4].type == JSON_ARRAY: ", json_data_stack[4].type == JSON_ARRAY);
    assert("[4].parent == &[3]: ", json_data_stack[4].parent == &json_data_stack[3]);
    assert("[4].next == &[7]: ", json_data_stack[4].next == &json_data_stack[7]);
    assert("[4].child == &[5]: ", json_data_stack[4].child == &json_data_stack[5]);
    assert("[4].size == 2: ", json_data_stack[4].size == 2);

    assert("[5].key == NULL: ", json_data_stack[5].key == NULL);
    assert("[5].type == JSON_STRING: ", json_data_stack[5].type == JSON_STRING);
    assert("[5].parent == &[4]: ", json_data_stack[5].parent == &json_data_stack[4]);
    assert("[5].next == &[6]: ", json_data_stack[5].next == &json_data_stack[6]);
    assert("[5].value == \"3\": ", strcmp(json_data_stack[5].value, "3") == 0);

    assert("[6].key == NULL: ", json_data_stack[6].key == NULL);
    assert("[6].type == JSON_STRING: ", json_data_stack[6].type == JSON_STRING);
    assert("[6].parent == &[4]: ", json_data_stack[6].parent == &json_data_stack[4]);
    assert("[6].next == NULL: ", json_data_stack[6].next == NULL);
    assert("[6].value == 5: ", strcmp(json_data_stack[6].value, "5") == 0);

    assert("[7].key == \"v\": ", strcmp(json_data_stack[7].key, "v") == 0);
    assert("[7].type == JSON_ARRAY: ", json_data_stack[7].type == JSON_ARRAY);
    assert("[7].parent == &[3]: ", json_data_stack[7].parent == &json_data_stack[3]);
    assert("[7].next == NULL: ", json_data_stack[7].next == NULL);
    assert("[7].child == &[8]: ", json_data_stack[7].child == &json_data_stack[8]);
    assert("[7].size == 2: ", json_data_stack[7].size == 2);

    assert("[8].key == NULL: ", json_data_stack[8].key == NULL);
    assert("[8].type == JSON_INTEGER: ", json_data_stack[8].type == JSON_INTEGER);
    assert("[8].parent == &[7]: ", json_data_stack[8].parent == &json_data_stack[7]);
    assert("[8].next == &[9]: ", json_data_stack[8].next == &json_data_stack[9]);
    assert("[8].value == \"4\": ", strcmp(json_data_stack[8].value, "4") == 0);

    assert("[9].key == NULL: ", json_data_stack[9].key == NULL);
    assert("[9].type == JSON_INTEGER: ", json_data_stack[9].type == JSON_INTEGER);
    assert("[9].parent == &[7]: ", json_data_stack[9].parent == &json_data_stack[7]);
    assert("[9].next == NULL: ", json_data_stack[9].next == NULL);
    assert("[9].value == 6: ", strcmp(json_data_stack[9].value, "6") == 0);

    json_object *payload = NULL;
    json_object *arr_i = NULL;
    json_object *arr_v = NULL;
    int arr_len = -1;
    json_object *obj_i = NULL;
    json_object *obj_v = NULL;
    char *i = NULL;
    int v = -1;

    payload = json_get(parsed, "payload");
    if (payload) {
        printf("\n Result:\n");
        arr_i = json_get(payload, "i");
        arr_v = json_get(payload, "v");
        arr_len = json_getArrayLength(arr_i);
        if (arr_i && arr_v && arr_len == json_getArrayLength(arr_v)) {
            obj_i = json_getArrayIndex(arr_i, 0);
            obj_v = json_getArrayIndex(arr_v, 0);
            json_getString(obj_i, &i);
            json_getInteger(obj_v, &v);
            printf(" %s: %d\n", i, v);
            for (int _i = 1; _i < arr_len; _i++) {
                obj_i = json_getNext(obj_i);
                obj_v = json_getNext(obj_v);
                json_getString(obj_i, &i);
                json_getInteger(obj_v, &v);
                printf(" %s: %d\n", i, v);
            }
        }
    }

    printf("\n\n");
}

#endif //TEST_14_H
