#include "userChoiсe.h"

int userChoice(){
    wchar_t buffer[USER];
    fgetws(buffer, USER, stdin);
    int num;
    for (int i = 0; i < wcslen(buffer); i++){
        if(iswalpha(buffer[i])){
            return -1;
        }
    }
    swscanf(buffer, L"%d", &num);
    return num;
}