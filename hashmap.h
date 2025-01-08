#pragma once

typedef struct {
    char *array;
    int (*hash_function)(char);
    int hash_function_min;
    int (*unhash_function)(char);
} hash_map;

int ascii_hash_function(char hashee) {
    // Really we just want to chop off the first parts
    // of ascii and have just the characters
    return hashee - 32;
}

int ascii_unhash_function(char hashed) {
    return hashed + 32;
}
