#include "pattern.h"

void pattern(Text text) {
    wprintf(L"------------------------------\n");
    wchar_t** patterns = malloc(text.size * sizeof(wchar_t*));
    for (int i = 0; i < text.size; i++) {
        wchar_t **tmp = malloc(text.ptr[i].words_counter * sizeof(wchar_t *));
        for (int j = 0; j < text.ptr[i].words_counter; j++) {
            tmp[j] = malloc(wcslen(text.ptr[i].words[j].ptr) * sizeof(wchar_t));
            tmp[j] = text.ptr[i].words[j].ptr;
        }
        for (int q = 0; q < text.ptr[i].words_counter; q++) {
            for (int w = text.ptr[i].words_counter - 1; w > q; w--) {
                if (wcslen(tmp[w - 1]) > wcslen(tmp[w])) {
                    wchar_t *s = tmp[q];
                    tmp[q] = tmp[w];
                    tmp[w] = s;
                }
            }
        }
        if (text.ptr[i].words_counter > 1){
            if (wcslen(tmp[0]) > wcslen(tmp[1])) {
                wchar_t *s = tmp[0];
                tmp[0] = tmp[1];
                tmp[1] = s;
            }
        }

        int count = 0;
        patterns[i] = malloc((wcslen(tmp[text.ptr[i].words_counter - 1]) + 1) * sizeof(wchar_t));
        wchar_t* s = malloc((wcslen(tmp[text.ptr[i].words_counter - 1]) + 1) * sizeof(wchar_t));
        if(text.ptr[i].words_counter == 1){
                patterns[i] = tmp[0];
        }
        else{
            for(int t = 0; t <wcslen(tmp[0]); t++){
                wchar_t temp;
                for(int n = 1; n < text.ptr[i].words_counter; n++){
                    if(tmp[n][t] == tmp[n - 1][t]){
                        temp = tmp[n][t];
                    }
                    else{
                        temp = '?';
                        break;
                    }
                }
                patterns[i][count] = temp;
                count += 1;
            }
            int len = count;
            if(len != wcslen(tmp[text.ptr[i].words_counter - 1])){
                patterns[i][len] = L'*';
            }
        }
    }
    for (int z = 0; z < text.size; z++){
        wprintf(L"Предложению %d соответсвует данная маска: %ls\n", z, patterns[z]);
    }
    for (int y = 0; y < text.size; y++){
        free(patterns[y]);
    }
    free(patterns);
    wprintf(L"------------------------------\n");
}
