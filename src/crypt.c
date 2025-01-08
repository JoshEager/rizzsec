#include "crypt.h"
#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int strsize(char *string) {
    int size_of_string = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        size_of_string++;
    } size_of_string++; // Add one more for the null terminator
    
    return size_of_string;
}
 
// Used for taking an already encrypted character and finding what
// character it came from
int indexof(char character, char *key) {
    int index;
    bool character_found = false;
    int key_size = strsize(key);
    for (int i = 0; i < key_size - 1; i++) { // We don't want to look for the null terminator (because it isn't actually part of the key), so subtract 1
        if (key[i] == character) {
            index = i;
            character_found = true;
            break;
        }
    }
    // Make sure that the return value is not garbage in the 
    // case that index is not found/assigned. 
    if (character_found == true) {
        return index;        
    } else {
        return -1;
    }

}

char *encrypt(char *plain_string, hash_map hashmap) {
    int size_of_string = strsize(plain_string);
    char *encrypted_string = (char*)malloc(size_of_string * sizeof(char));

    for (int i = 0; i < size_of_string; i++) {
        // Make sure that each character is capable of being hashed. Characters with an ascii value less than 32 cannot
        // be hashed with some hashing algorithms, so this is just a safe check to ensure no data loss. 
        if (plain_string[i] >= hashmap.hash_function_min) {
            encrypted_string[i] = hashmap.array[hashmap.hash_function(plain_string[i])];
        } else {
            encrypted_string[i] = plain_string[i];
        }
    }

    return encrypted_string;
}

char *decrypt(char *encrypted_string, hash_map hashmap) {
    int size_of_string = strsize(encrypted_string);
    char *decrypted_string = (char*)malloc(size_of_string * sizeof(char));

    for (int i = 0; i < size_of_string; i++) {
        int decrypted_value = indexof(encrypted_string[i], hashmap.array);
        // Makes sure that index of the character is actually found 
        if (decrypted_value != -1) {
            decrypted_string[i] = hashmap.unhash_function(decrypted_value);
        } else {
            // It will always jump here once for the null terminator! (issue with index of, since the key has a null terminator appended to it in order to be a valid string)
            decrypted_string[i] = encrypted_string[i];
            // perror("Error: unable to decrypt a character!");
        }
    }

    return decrypted_string;
}
