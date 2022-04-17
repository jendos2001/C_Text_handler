#include "writeText.h"

void WriteText(Text text) {
    wprintf(L"------------------------------\n");
    for (int i=0; i < text.size; i++){
        if (text.ptr[i].words != NULL){
            for (int j = 0; j < text.ptr[i].words_counter - 1; j++){
                wprintf(L"%ls", text.ptr[i].words[j].ptr);
                if (text.ptr[i].words[j].punctuation){
                    wprintf(L"%lc", text.ptr[i].words[j].punctuation);
                }
                wprintf(L" ");
            }
            wprintf(L"%ls", text.ptr[i].words[text.ptr[i].words_counter - 1].ptr);
            if (text.ptr[i].words[text.ptr[i].words_counter - 1].punctuation){
                wprintf(L"%lc", text.ptr[i].words[text.ptr[i].words_counter - 1].punctuation);
            }
            if (text.ptr[i].newline){
                wprintf(L"\n");
            }
            else{
                wprintf(L" ");
            }
        }
    }
    wprintf(L"\n------------------------------\n");
}