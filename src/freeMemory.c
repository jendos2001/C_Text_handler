#include "freeMemory.h"

void FreeMemory(Text* text) {
    for (int i=0; i < (text -> size); i++) {
        if (text->ptr[i].words != NULL) {
            free((text->ptr)[i].words);
        }
        free((text->ptr)[i].ptr);
    }
    free(text -> ptr);
}