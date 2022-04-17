#include "readSent.h"

Sentence ReadSentence(FILE* source) {
    Sentence sentence = {NULL,
                         calloc(SENT_LEN, sizeof(wchar_t)),
                         0,
                         0,
                         0,
                         0,
                         0,
                         0};
    if (sentence.ptr == NULL) {
        return sentence;
    }
    int i = 0;
    wchar_t *tmp_ptr;
    wchar_t wc;
    int size = SENT_LEN;
    do {
        wc = fgetwc(source);
        if (feof(source)) {
            free(sentence.ptr);
            sentence.EOR = 1;
            return sentence;
        }
        sentence.ptr[i++] = wc;
        if (i == size - 1) {
            size += SENT_LEN;
            tmp_ptr = realloc(sentence.ptr, sizeof(wchar_t) * size);
            if (tmp_ptr == NULL) {
                free(sentence.ptr);
                sentence.ptr = NULL;
                return sentence;
            }
            sentence.ptr = tmp_ptr;
        }
    } while(!wcschr(L".!?\n", wc));
    sentence.ptr[i] = L'\0';
    if (wcschr(L".!?", sentence.ptr[0])) {
        free(sentence.ptr);
        fgetwc(source);
        sentence.empty = 1;
    }
    else {
        if (sentence.ptr[0] == L'\n') {
            free(sentence.ptr);
            sentence.only_newline = 1;
        } else {
            sentence.size = i;
            if (fgetwc(source) == L'\n')
                sentence.newline = 1;
        }
    }
    return sentence;
}
