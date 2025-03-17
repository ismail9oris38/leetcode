#include<stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void){
    int nums1[] = {1,5,6,7,8};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2[] = {2,4,10,11,12};
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    printf("%d",nums1Size);
    printf("\nresult: %lf",findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size));

    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, size, tmp = 1;
    double medium = 0;

    size = nums1Size + nums2Size;
    

    if (size % 2 == 1) {

        while(i < nums1Size && j < nums2Size && tmp) {

            if (*(nums1 + i) < *(nums2 + j)) {

                i++;

                if ( i + j == size/2 + 1) {

                    medium = *(nums1 + i - 1);
                    tmp = 0;

                }
            }
            else {

                j++;

                if ( i + j == size/2 + 1) {

                    medium = *(nums2 + j - 1);
                    tmp = 0;

                }
            }
        }
        while (tmp && i < nums1Size) {

            i++;
            
            if ( i + j == size/2 + 1) {

                medium = *(nums1 + i - 1);
                tmp = 0;

            }
        }
        while (tmp && j < nums2Size) {

            j++;

            if ( i + j == size/2 + 1) {

                medium = *(nums2 + j - 1);
                tmp = 0;

            }
        }
    }

    else {
        while(i < nums1Size && j < nums2Size && tmp) {

            if (*(nums1 + i) < *(nums2 + j)) {

                i++;

                if ( i + j == size/2) {

                    medium = *(nums1 + i - 1);
                   

                }
                if ( i + j == size/2 + 1) {

                    medium += *(nums1 + i - 1);
                    tmp = 0;

                }
            }
            else {

                j++;

                if ( i + j == size/2) {

                    medium = *(nums2 + j - 1);
                    

                }if ( i + j == size/2 + 1) {

                    medium += *(nums2 + j - 1);
                    tmp = 0;

                }
            }
        }
        while (tmp && i < nums1Size) {

            i++;
            
            if ( i + j == size/2) {

                medium = *(nums1 + i - 1);
                

            }
            if ( i + j == size/2 + 1) {

                medium += *(nums1 + i - 1);
                tmp = 0;

            }
        }
        while (tmp && j < nums2Size) {

            j++;

            if ( i + j == size/2 ) {

                medium = *(nums2 + j - 1);
                

            }
            if ( i + j == size/2 + 1) {

                medium += *(nums2 + j - 1);
                tmp = 0;

            }
        }
        medium /= 2;
    }

    return medium;
    
}