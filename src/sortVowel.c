#include "sortVowel.h"

void sort(Text text){
    wchar_t s[] = L"уеыаоэяиюёУЕЫАОЭЯИЮЁeyuioaEYUIOA";
    for(int i = 0; i < text.size; i++){
        for (int j = 0; j < text.ptr[i].words_counter; j++){
            for (int m = j + 1; m < text.ptr[i].words_counter; m++){
                int n1 = 0;
                int n2 = 0;
                for(int l = 0; l < wcslen(text.ptr[i].words[j].ptr); l++){
                    if (wcschr(s, *(text.ptr[i].words[j].ptr + l)) != NULL){
                        n1 += 1;
                    }
                }
                for(int l = 0; l < wcslen(text.ptr[i].words[m].ptr); l++){
                    if (wcschr(s, *(text.ptr[i].words[m].ptr + l)) != NULL){
                        n2 += 1;
                    }
                }
                if (n1 > n2){
                    wchar_t *tmp = text.ptr[i].words[m].ptr;
                    text.ptr[i].words[m].ptr = text.ptr[i].words[j].ptr;
                    text.ptr[i].words[j].ptr = tmp;
                }
            }
        }
    }
}