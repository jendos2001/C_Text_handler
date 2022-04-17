#include "deleteUpper.h"

void del(Text text){
    int n;
    for(int i = 0; i < text.size; i++){
        n = 0;
        for (int j = 0; j < text.ptr[i].words_counter; j++) {
            if (iswupper(*(text.ptr[i].words[j].ptr)) != 0) {
                n += 1;
            }
        }
        if (n != text.ptr[i].words_counter){
            Word *tmp1 = text.ptr[i].words;
            text.ptr[i].words = NULL;
            free(tmp1);

        }
    }
}
