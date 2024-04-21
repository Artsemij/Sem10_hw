#include <stdio.h>
#include <string.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char input[1000];
    fgets(input, sizeof(input), file);
    fclose(file);

    int length = strlen(input);
    if (length % 2 != 0) {
        length--;
    }

    for (int i = 0; i < length; i += 2) {
        if (input[i] != ' ') {
            char temp = input[i];
            input[i] = input[i+1];
            input[i+1] = temp;
        }
    }

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    fprintf(file, "%s", input);
    fclose(file);

    return 0;
}