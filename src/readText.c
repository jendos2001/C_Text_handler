#include "readText.h"

Text ReadText(FILE* source);
Sentence ReadSentence(FILE* source);

Text ReadText(FILE* source){
    Text text = {calloc(TEXT_LEN, sizeof(Sentence)),
                 0,
                 0,
                 0};
    if (text.ptr == NULL){
        return text;
    }
    int i = 0;
    int n = 0;
    Sentence* tmp_ptr;
    Sentence ws;
    int size = TEXT_LEN;
    do {
        ws = ReadSentence(source);
        if (ws.ptr == NULL) {
            for (int j = 0; j < text.read_sent; j++)
                free(text.ptr[j].ptr);
            free(text.ptr);
            text.ptr = NULL;
            return text;
        }
        if (ws.only_newline) {
            n += 1;
            if (n == 2)
                break;
            continue;
        }
        else {
            n = 0;
        }
        if (ws.EOR){
            break;
        }
        if (ws.empty){
            continue;
        }
        text.ptr[i++] = ws;
        if (i == size - 1){
            size += TEXT_LEN;
            tmp_ptr = realloc(text.ptr, sizeof(Sentence) * size);
            if (tmp_ptr == NULL){
                for (int j = 0; j < text.read_sent; j++)
                    free(text.ptr[j].ptr);
                free(text.ptr);
                text.ptr = NULL;
                return text;
            }
            text.ptr = tmp_ptr;
        }
        text.read_sent++;
    }while (1);
    if (text.read_sent == 0) {
        free(text.ptr);
        return text;
    }
    text.size = i;
    return text;
}