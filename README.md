# Usage

You must declare a data stack, with the size being the number of tokens. It should be static to increase performance and memory usage.

 ```C
static json_object json_data_stack[TOKENS_COUNT];
```

You call the JSON parser with the arguments :
- the buffer (the string to parse) and its length
- the data stack and its size

 ```C
json_object *parsed = json_parse(buffer, strlen(buffer), json_data_stack, sizeof(json_data_stack) / sizeof(json_object));
```

The JSON parser will return NULL if an error occurs.

The test cases will help you to understand how to use this library.