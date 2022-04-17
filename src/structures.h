#ifndef STRUCTURES
#define STRUCTURES

#include <wchar.h>

typedef struct Word{
    wchar_t* ptr;
    wchar_t punctuation;
}Word;

typedef struct Sentence{
    Word* words;
    wchar_t* ptr;
    int size;
    int words_counter;
    int newline;
    int empty;
    int only_newline;
    int EOR;
}Sentence;

typedef struct Text{
    Sentence* ptr;
    int size;
    int read_sent;
    int split_sent;
}Text;

#endif