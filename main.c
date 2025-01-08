#include "hashmap.h"
#include "crypt.h"
#include "io.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Parsing arguments
    char *key_path = NULL;
    char *read_path = NULL;
    char *write_path = NULL;
    char *mode = NULL;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                key_path = argv[i + 1];
            } else {
                perror("Missing path for key file!");
                return 1;
            } 
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                read_path = argv[i + 1];
            } else {
                perror("Missing path for read file! (use -d)!");
                return 1;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                write_path = argv[i];
            } else {
                perror("Warning: no output file specified");
                write_path = "id_rizz.enc";
            }
        } else if (strcmp(argv[i], "encrypt") == 0) {
            mode = "encrypt";
        } else if (strcmp(argv[i], "decrypt") == 0) {
            mode = "decrypt";
        }
    }
    // Ensure that required arguments were specified
    if (mode == NULL) {
        perror("No mode was specified! Should be either encrypt or decrypt.");
        return 1;
    } else if (key_path == NULL) {
        perror("No key path was provided!");
        return 1;
    } else if (read_path == NULL) {
        perror("No read file was specified!");
        return 1;
    } else if (write_path == NULL) {
        perror("No output file specified, set to default (id_rizz.enc)");
        write_path = "id_rizz.enc";
    }

    // Make the key into a hashmap
    hash_map hashmap;
    hashmap.hash_function = ascii_hash_function;
    hashmap.hash_function_min = 32;
    hashmap.unhash_function = ascii_unhash_function;
    hashmap.array = load_file(key_path);

    // Read the file at read_path and encrypt/decrypt it (depending on the mode)
    char *read_string = load_file(read_path);
    char *write_string;
    if (strcmp(mode, "encrypt") == 0) {
        write_string = encrypt(read_string, hashmap);
    } else {
        write_string = decrypt(read_string, hashmap);
    }

    // Write the string to the output file
    write_file(write_path, write_string);

    return 0;
}
