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

    // Находим позицию последней точки
    char* lastDot = strrchr(input, '.');
    if (lastDot != NULL) {
        // Заменяем расширение на .html
        strcpy(lastDot, ".html");
    } else {
        // Если точка не найдена, просто добавляем .html в конце
        strcat(input, ".html");
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