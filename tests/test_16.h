#ifndef TEST_16_H
#define TEST_16_H

#include "assert.h"
#include "../json.h"

static void test_16(void) {
    static json_object json_data_stack[226];
    static char buffer[2 * 1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer,
           "{\"msgid\":\"17d009f6e1b\",\"topic\":\"set/value\",\"payload\":{\"i\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109],\"v\":[1,1439,1,1439,1,1439,1,1439,1,1439,1,1439,1,1439,1230,360,1230,360,1230,360,1230,360,1230,360,1230,360,1230,360,780,840,780,840,780,840,780,840,780,840,780,840,780,840,7,27,6600,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,700,650,100,120,5,300,1800,0,30,2,3,15,80,120,40,300,3600,3600,0,15,0,250,3600,300,0,300,300,0,300,20,0,0,0,0,0,0,0,0,0,1,1,0,58,0,50,50,50,50]}}");
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
    assert("[4].next == &[115]: ", json_data_stack[4].next == &json_data_stack[115]);
    assert("[4].child == &[5]: ", json_data_stack[4].child == &json_data_stack[5]);
    assert("[4].size == 110: ", json_data_stack[4].size == 110);

    assert("[115].key == \"v\": ", strcmp(json_data_stack[115].key, "v") == 0);
    assert("[115].type == JSON_ARRAY: ", json_data_stack[115].type == JSON_ARRAY);
    assert("[115].parent == &[3]: ", json_data_stack[115].parent == &json_data_stack[3]);
    assert("[115].next == NULL: ", json_data_stack[115].next == NULL);
    assert("[115].child == &[116]: ", json_data_stack[115].child == &json_data_stack[116]);
    assert("[115].size == 110: ", json_data_stack[115].size == 110);

    printf("\n\n");
}

#endif //TEST_16_H
