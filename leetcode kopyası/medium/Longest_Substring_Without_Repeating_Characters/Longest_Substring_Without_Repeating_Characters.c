#include <stdio.h>
#include <stdlib.h>

int string_uzunluk(char *string);
int lengthOfLongestSubstring(char *string, int uzunluk);

int main(void) {
    int i, uzunluk = 0;
    char *string;

    // Dinamik bellek ayırma
    string = (char*)malloc(sizeof(char) * 1000);  // 1000 karakter için bellek ayrılıyor, gerekirse artırabilirsiniz.

    if (string == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;  // Hata durumu
    }

    printf("Metin: \n");
    // Boşluk içeren bir satır okuma
    scanf(" %[^\n]", string);

    uzunluk = string_uzunluk(string);
    printf("uzunluk: %d\n", uzunluk);

    printf("result: %d\n", lengthOfLongestSubstring(string, uzunluk));

    free(string);  // Belleği serbest bırakma
    return 0;
}

int string_uzunluk(char *string) {
    int uzunluk = 0;

    while (*(string + uzunluk) != '\0') uzunluk++;

    return uzunluk;
}

int lengthOfLongestSubstring(char *string, int uzunluk) {
    int charSet[256] = {0}; // Karakterlerin son görüldüğü indeksleri tutar
    int longest = 0;        // En uzun alt dizenin uzunluğu
    int start = 0;          // Sliding window'un başlangıç indeksi

    for (int end = 0; end < uzunluk; end++) {
        // Eğer karakter daha önce görüldüyse, start'ı güncelle
        if (charSet[string[end]] > start) {
            start = charSet[string[end]];
        }

        // En uzun alt dizeyi güncelle
        if (longest < end - start + 1) {
            longest = end - start + 1;
        }

        // Karakterin son görüldüğü indeksi kaydet
        charSet[string[end]] = end + 1;
    }

    return longest;
}
