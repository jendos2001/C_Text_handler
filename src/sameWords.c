#include "sameWords.h"

void same(Text text){
    wprintf(L"------------------------------\n");
    for (int i = 0; i < text.size; i++){
        int k = 1;
        int num = 0;
        wchar_t** tmp = malloc(text.ptr[i].words_counter * sizeof(wchar_t*));
        for (int j = 0; j < text.ptr[i].words_counter; j++){
            tmp[j] = malloc(wcslen(text.ptr[i].words[j].ptr) * sizeof(wchar_t));
            for (int v = 0; v < wcslen(text.ptr[i].words[j].ptr); v++){
                text.ptr[i].words[j].ptr[v] = towlower(text.ptr[i].words[j].ptr[v]);
            }
            tmp[j] = text.ptr[i].words[j].ptr;
        }
        for (int r = 0; r < text.ptr[i].words_counter; r++){
            for (int r1 = 0; r1 < text.ptr[i].words_counter - 1; r1++){
                if (wcscmp(tmp[r], tmp[r1]) > 0){
                    wchar_t *temp = tmp[r];
                    tmp[r] = tmp[r1];
                    tmp[r1] = temp;
                }
            }
        }
        wprintf(L"В предложении %d:", i + 1);
        for (int z = 0; z < text.ptr[i].words_counter - 1; z++){
            if (wcscmp(tmp[z], tmp[z + 1]) == 0){
                k += 1;
            }
            else if (k > 1){
                wprintf(L"\n%ls:%d", tmp[z], k);
                num += 1;
                k = 1;
            }
        }
        if (k > 1){
            wprintf(L"\n%ls:%d", tmp[text.ptr[i].words_counter - 1], k);
            num += 1;
        }
        if (num == 0){
            wprintf(L" все слова в предложении уникальны!");
        }
        wprintf(L"\n");
    }
    wprintf(L"------------------------------\n");
}
