#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_characters(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    printf("�ַ�����%d\n", count);
}

void count_words(FILE *file) {
    int count = 0;
    char ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == ',') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }

    printf("��������%d\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "�÷�: %s [-c|-w] input_file_name\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *input_file_name = argv[2];

    FILE *file = fopen(input_file_name, "r");
    if (file == NULL) {
        perror("�޷����ļ�");
        return 1;
    }

    if (strcmp(parameter, "-c") == 0) {
        count_characters(file);
    } else if (strcmp(parameter, "-w") == 0) {
        count_words(file);
    } else {
        fprintf(stderr, "��Ч�Ĳ���: %s\n", parameter);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
