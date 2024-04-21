#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char input[1000];
    fgets(input, sizeof(input), file);

    // Удаляем лишние пробелы в начале предложения
    int i = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i]) || ispunct(input[i])) {
            break;
        } else if (input[i] == ' ') {
            i++;
        } else {
            printf("Ошибка: недопустимый символ\n");
            return 1;
        }
    }
    memmove(input, &input[i], strlen(input) - i + 1); 

    // Удаляем лишние сдвоенные пробелы
    int length = strlen(input);
    int j = 0;
    for (i = 0; i < length; i++) {
        if (input[i] == ' ') {
            input[j++] = input[i];
            while (input[i] == ' ') {
                i++;
            }
            i--;
        } else {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';

    fclose(file);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    fprintf(file, "%s", input);
    fclose(file);

    return 0;
}