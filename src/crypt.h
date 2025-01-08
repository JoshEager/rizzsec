#pragma once
#include "hashmap.h"

char *encrypt(char *plain_string, hash_map hashmap);
char *decrypt(char *encypted_string, hash_map hashmap);