#include "readAll.h"

#include "libraries.h"

int read(Text* text){
    int k;
    choice1();
    k = userChoice();
    while((k != 1) && (k != 2) && (k != 0)){
        wprintf(L"Некоректные данные. Повторите ввод: ");
        k = userChoice();
    }
    switch (k){
        case 1:
            wprintf(L"Введите текст, оканчивающийся ТРЕМЯ символами переноса строки:\n");
            *text = ReadText(stdin);
            if (text->ptr == NULL){
                wprintf(L"Невозможно выделить память. Программа завершена.\n");
                return 0;
            }
            if (text->read_sent == 0){
                wprintf(L"Вы ввели пустой текст. Программа завершена.\n");
                return 0;
            }
            break;
        case 2:
            wprintf(L"ПРИМЕЧАНИЕ: Длина имени файла должна быть не более %d\n", PATH_LEN-2);
            wchar_t *file_name = (wchar_t*) calloc(PATH_LEN, sizeof(wchar_t));
            wprintf(L"Введите название файла, из которого нужно считать текст: ");
            fgetws(file_name, PATH_LEN, stdin);
            char *buffer = calloc(PATH_LEN * sizeof(wchar_t), sizeof(char));
            *wcschr(file_name, L'\n') = '\0';
            wcstombs(buffer, file_name, sizeof(wchar_t) * PATH_LEN);
            FILE *file_ptr;
            while ((file_ptr = fopen(buffer, "r")) == NULL){
                wprintf(L"Некорректное название файла! Повторите попытку!\n");
                wprintf(L"ОБРАТИТЕ ВНИМАНИЕ! Длина имени файла должна быть не более %d\n", PATH_LEN-2);
                wprintf(L"Введите название файла, из которого будет произведено считывание текста: ");
                fgetws(file_name, PATH_LEN, stdin);
                *wcschr(file_name, L'\n') = '\0';
                wcstombs(buffer, file_name, sizeof(wchar_t) * PATH_LEN);
            }
            *text = ReadText(file_ptr);
            fclose(file_ptr);
            free(file_name);
            free(buffer);
            if (text->ptr == NULL){
                wprintf(L"Невозможно выделить память!.\n");
                return 0;
            }
            if (text->read_sent == 0){
                wprintf(L"Введён пустой текст. Программа завершена!\n");
                return 0;
            }
            break;
        case 0:
            wprintf(L"Программа завершена.\n");
            return 0;
    }
}
