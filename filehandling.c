#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[] = "sample.txt";
    char content[100];

    // Writing to the file
    fptr = fopen(filename, "w"); // Open for writing
    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    fprintf(fptr, "Hello, this is a file handling example in C.\n");
    fprintf(fptr, "Let's write another line.\n");
    fclose(fptr); // Close the file after writing
    printf("Data written successfully to %s\n", filename);

    // Reading from the file
    fptr = fopen(filename, "r"); // Open for reading
    if (fptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nReading content from %s:\n", filename);
    while (fgets(content, sizeof(content), fptr)) {
        printf("%s", content); // Print each line
    }
    fclose(fptr); // Close the file after reading

    return 0;
}
