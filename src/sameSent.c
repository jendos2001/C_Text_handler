#include "sameSent.h"

void delete(Text* text) {
    int i = 0, j = 1;
    while (i < text->size) {
        while (j < text->size) {
            if (!wcscasecmp((text->ptr)[i].ptr, (text->ptr)[j].ptr))  {
                free((text->ptr)[j].ptr);
                for (int k=j; k < text->size - 1; k++)
                    (text->ptr)[k] = (text->ptr)[k+1];
                (text->size) -= 1;
                continue;
            }
            j++;
        }
        i++;
        j = i + 1;
    }
}