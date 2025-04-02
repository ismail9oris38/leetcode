#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen() için eklendi

char* longestCommonPrefix(char** strs, int strsSize); // Fonksiyon prototipi

int main() {
    char* strs[] = {"flower", "flow", "flight"}; // Test dizisi
    int strsSize = sizeof(strs) / sizeof(strs[0]); // Dizi boyutunu hesapla

    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: \"%s\"\n", result);

    free(result); // Dinamik ayrılan belleği serbest bırak
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j, tmp = 1, len, minLen;
    char *result;

    if (strsSize == 0) return ""; // Boş dizi durumu

    // En kısa stringin uzunluğunu bul
    minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        len = strlen(strs[i]);
        if (len < minLen) minLen = len;
    }

    // Sonuç için bellek ayır (+1 null karakter için)
    result = (char *)malloc((minLen + 1) * sizeof(char));
    if (!result) return NULL; // Bellek hatası kontrolü

    i = 0; 
    while (tmp) { // Ortak önek devam ettiği sürece
        j = 0;
        // Tüm stringlerde aynı karakter mi kontrol et
        while (j < strsSize && strs[j][i] != '\0' && strs[j][i] == strs[0][i]) j++;

        if (j != strsSize) tmp = 0; // Farklı karakter bulundu
        else {
            result[i] = strs[0][i]; // Ortak karakteri kaydet
        }
        
        i++;
    }

    result[i-1] = '\0'; // String sonlandırıcı ekle
    return result;
}
