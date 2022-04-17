#include "splitSent.h"

int SplitSentence(Sentence* ptr_sentence) {
    int size = WORDS_NUM;
    Word *words = calloc(size, sizeof(Word));
    if (words == NULL) {
        free(words);
        return 0;
    }
    int i = 0;
    wchar_t *state;
    Word *temp_ptr;
    wchar_t *word_ptr = wcstok(ptr_sentence->ptr, L" ", &state);
    do{
        ptr_sentence->words_counter += 1;
        words[i].punctuation = 0;
        if (wcschr(L".!?,", word_ptr[wcslen(word_ptr) - 1])) {
            words[i].punctuation = word_ptr[wcslen(word_ptr) - 1];
            word_ptr[wcslen(word_ptr) - 1] = L'\0';
        }
        words[i++].ptr = word_ptr;
        if (i == size - 1){
            size += WORDS_NUM;
            temp_ptr = realloc(words, size * sizeof(Word));
            if (temp_ptr == NULL) {
                free(words);
                return 0;
            }
            words = temp_ptr;
        }
        word_ptr = wcstok(NULL, L" ", &state);
        if (word_ptr == NULL)
            break;
    }while(1);
    ptr_sentence->words = words;
    return 1;
}