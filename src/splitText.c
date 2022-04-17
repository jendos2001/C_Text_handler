#include "splitText.h"

int SplitText(Text* text) {
    for (int i = 0; i < text->size; i++){
        if (SplitSentence((text->ptr) + i)){
            text->split_sent += 1;
            continue;
        }
        else{
            for (int j = 0; j < text->split_sent; j++) {
                free((text->ptr)[j].words);
            }
            for (int j = 0; j < text->size; j++) {
                free((text->ptr)[j].ptr);
            }
            free(text->ptr);
            return 0;
        }
    }
    return 1;
}