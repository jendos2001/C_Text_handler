#include "libraries.h"
#include "structures.h"
#include "readAll.h"
#include "sameSent.h"
#include "splitText.h"
#include "functions.h"
#include "writeText.h"
#include "freeMemory.h"

int main() {
    setlocale(LC_ALL, "");
    Text text;
    int a = read(&text);
    if (a == 0){
        return 0;
    }
    delete(&text);
    a = SplitText(&text);
    if (a == 0){
        wprintf(L"Невозможно выделить память. Программа завершена.\n");
        return 0;
    }
    if(function(text) == 1){
        FreeMemory(&text);
        return 0;
    }
    WriteText(text);
    FreeMemory(&text);
    return 0;
}
