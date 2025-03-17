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
    int i, j, uzunluk;
    char *result;
    
    return result;
}


// char* longestPalindrome(char* string) {
//     int start, end, big = 0;
//     char *result;
//     int i, j, uzunluk = 0;

//     result = (char*)malloc(sizeof(char) * 1000);

//     while(*(string+uzunluk) != '\0') uzunluk++;

//     for (i = 0; i < uzunluk; i++) {
//         j = 1;

//         while (*(string + i + j) == *(string + i - j) && i + j < uzunluk && i - j >=0) {
//             j++;
//         }

//         if ( j > big ) {

//             big = j;
//             j--;
//             start = i - j;
//             end = i + j;     
//         }
//     }
//     j = 0;
//     for (i = start; i <= end; i++) {

//         *(result + j++)= *(string + i);
        
//     }
    
//     return result;
// }
// 'a','b','c','b','g','\0'