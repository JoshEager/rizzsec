#pragma once

typedef struct {
    char *array;
    int (*hash_function)(char);
    int hash_function_min;
    int (*unhash_function)(char);
} hash_map;

int ascii_hash_function(char hashee);
int ascii_unhash_function(char hashed);
