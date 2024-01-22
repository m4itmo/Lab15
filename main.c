#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX_LEN 256

void archive_files(int count, char* files[], const char* archive_filename) {
    FILE *archive_file = fopen(archive_filename, "wb");

    if (archive_file == NULL) {
        perror("Error opening archive file");
        exit(1);
    }

    for (int i = 0; i < count; ++i) {
        FILE *input_file = fopen(files[i], "rb");
        if (input_file == NULL) {
            perror("Error opening input file");
            continue;
        }

        // Получаем размер файла
        fseek(input_file, 0, SEEK_END);
        long filesize = ftell(input_file);
        fseek(input_file, 0, SEEK_SET);

        // Записываем имя файла и его размер в архив
        char filename[FILENAME_MAX_LEN] = {0};
        strncpy(filename, files[i], FILENAME_MAX_LEN);
        fwrite(filename, sizeof(char), FILENAME_MAX_LEN, archive_file);
        fwrite(&filesize, sizeof(filesize), 1, archive_file);

        // Копируем содержимое файла в архив
        char buffer[1024];
        while (!feof(input_file)) {
            size_t read = fread(buffer, sizeof(char), sizeof(buffer), input_file);
            fwrite(buffer, sizeof(char), read, archive_file);
        }

        fclose(input_file);
    }

    fclose(archive_file);
}

void unarchive_files(const char* archive_filename) {
    FILE *archive_file = fopen(archive_filename, "rb");

    if (archive_file == NULL) {
        perror("Error opening archive file");
        exit(1);
    }

    while (!feof(archive_file)) {
        char filename[FILENAME_MAX_LEN] = {0};
        long filesize;

        // Читаем имя файла и его размер из архива
        if (fread(filename, sizeof(char), FILENAME_MAX_LEN, archive_file) == 0) break;
        fread(&filesize, sizeof(filesize), 1, archive_file);

        FILE *output_file = fopen(filename, "wb");
        if (output_file == NULL) {
            perror("Error opening output file");
            continue;
        }

        // Копируем содержимое файла из архива
        char buffer[1024];
        for (long remaining = filesize; remaining > 0;) {
            size_t to_read = sizeof(buffer);
            if (remaining < sizeof(buffer)) {
                to_read = remaining;
            }

            size_t read = fread(buffer, sizeof(char), to_read, archive_file);
            fwrite(buffer, sizeof(char), read, output_file);
            remaining -= read;
        }

        fclose(output_file);
    }

    fclose(archive_file);
}

void list_archive_contents(const char* archive_filename) {
    FILE *archive_file = fopen(archive_filename, "rb");

    if (archive_file == NULL) {
        perror("Error opening archive file");
        exit(1);
    }

    printf("Список файлов в архиве '%s':\n", archive_filename);

    while (!feof(archive_file)) {
        char filename[FILENAME_MAX_LEN] = {0};
        long filesize;

        // Читаем имя файла и его размер из архива
        if (fread(filename, sizeof(char), FILENAME_MAX_LEN, archive_file) == 0) break;
        fread(&filesize, sizeof(filesize), 1, archive_file);

        printf("%s\n", filename);

        // Пропускаем данные файла
        fseek(archive_file, filesize, SEEK_CUR);
    }

    fclose(archive_file);
}


int main(int argc, char *argv[]) {
//    if (argc < 3) {
//        fprintf(stderr, "Использование: %s <archive.arc> <file1> [file2] ...\n", argv[0]);
//        return 1;
//    }
//
//    // Архивация файлов
//    archive_files(argc - 2, &argv[2], argv[1]);
//
//    // Для разархивации (пример вызова)
//    unarchive_files("archive.arc");
//
//    list_archive_contents("archive.arc");
//
    return 0;
}
