#include "functions.h"

int function(Text text){
    int k;
    choice2();
    k = userChoice();
    while((k != 1) && (k != 2) && (k != 3) && (k != 4) && (k != 0)){
        wprintf(L"Некоректные данные. Повторите ввод: ");
        k = userChoice();
    }
    switch (k){
        case 1:
            pattern(text);
            return 1;
        case 2:
            del(text);
            break;
        case 3:
            sort(text);
            break;
        case 4:
            same(text);
            return 1;
        case 0:
            wprintf(L"Программа завершена.");
            break;
    }
    return 0;
}