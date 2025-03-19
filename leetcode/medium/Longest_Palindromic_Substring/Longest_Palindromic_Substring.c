#include<stdio.h>
#include<stdlib.h>

char* longestPalindrome(char* s);

int main(void) {
    int i, j, uzunluk;
    char *string;

    string = (char*)malloc(sizeof(char) * 1000);

    printf("string: ");
    scanf("%s",string);
    
    
    
    uzunluk=0;
    while(*(string+uzunluk) != '\0') uzunluk++;

    printf("%d",uzunluk);

    printf("\noutput: %s",longestPalindrome(string));


    free(string);
    free(longestPalindrome(string));
    return 0;
}

char* longestPalindrome(char* string) {
    int uzunluk = 0, big = 0, start = 0, end = 0;
    char *result;

    // String uzunluğunu hesapla
    while (*(string + uzunluk) != '\0') uzunluk++;

    for (int i = 0; i < uzunluk; i++) {
        // Tek karakter merkezli palindromlar için
        int j = 0;
        while (i - j >= 0 && i + j < uzunluk && *(string + i - j) == *(string + i + j)) j++;

        if (big < (j - 1) * 2 + 1) {
            big = (j - 1) * 2 + 1;
            start = i - (j - 1);
            end = i + (j - 1);
        }

        // Çift merkezli palindromlar için
        j = 0;
        while (i - j >= 0 && i + j + 1 < uzunluk && *(string + i - j) == *(string + i + j + 1)) j++;

        if (big < j * 2) {
            big = j * 2;
            start = i - (j - 1);
            end = i + j;
        }
    }

    // Bellek ayırma
    result = (char*)malloc(sizeof(char) * (end - start + 2)); 

    // Sonucu kopyalama
    int k = 0;
    for (int i = start; i <= end; i++) {
        result[k++] = string[i];
    }
    result[k] = '\0';

    return result;
}
