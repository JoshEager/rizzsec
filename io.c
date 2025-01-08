#include "io.h"
#include <stdio.h>

char *load_file(char *file_path) {
    // Openning the file in binary mode
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Eror opening file (*file = NULL, memory allocation failed)");
        return NULL;
    }

    // Seek to hte end of the file to determine it's size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking file");
        fclose(file);
        return NULL;
    }
    long file_size = ftell(file);
    if (file_size == -1) {
        perror("Error telling file size");
        fclose(file);
        return NULL;
    }

    // Rewind to the beginning of the file
    rewind(file);

    // Allocating memory to hold the file content (+1 for null terminator)
    char *buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(file);
        return NULL;
    }

    long bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file (fread)");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Null terminate the buffer
    buffer[file_size] = '\0';

    fclose(file);

    return buffer;
}

void write_file(char *file_path, char *content) {
    FILE *file = fopen(file_path, "w");
    fprintf(file, "%s", content);
    fclose(file);
}