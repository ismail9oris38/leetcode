#include<stdio.h>
#include<stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void quick_sort(int *array, int low, int high);

int main(void) {
    int numsSize, i, returnSize;
    int *nums, *returnColumnSizes;
    int **result;
    
    // Kullanıcıdan dizi boyutu ve elemanlarını alma
    printf("sayı dizisinin boyutu: ");
    scanf("%d",&numsSize);

    nums = (int*)malloc(sizeof(int) * numsSize);

    printf("sayı dizisinin elemanları: ");
    for (i = 0; i < numsSize; i++) {
        scanf("%d",&nums[i]);
    }
    
    // threeSum fonksiyonunu çağırma
    result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    // Sonuçları yazdırma
    printf("\ntoplamları 0 olan 3'lü : \n [");
    for(i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d],", result[i][0], result[i][1], result[i][2]);
    }
    printf("]");
    
    // Bellek temizleme
    free(nums);
    free(returnColumnSizes);
    for(i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int i, start, end;
    int **returnResult = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    // Diziyi sırala (küçükten büyüğe)
    quick_sort(nums, 0, numsSize - 1);

    printf("nums: \n");
    for(i = 0; i < numsSize; i++) {
        printf(" %d ", nums[i]);
    }
    
    // Ana algoritma
    i = 0;
    while (i < numsSize - 2 && nums[i] <= 0) {
        start = i + 1;
        end = numsSize - 1;
        
        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            
            if (sum == 0) {
                // Bellek genişletme ve yeni sonuç ekleme
                (*returnSize)++;
                
                // Sütun boyutları dizisini genişlet
                *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
                (*returnColumnSizes)[*returnSize - 1] = 3;
                
                // Sonuç dizisini genişlet
                returnResult = realloc(returnResult, sizeof(int*) * (*returnSize));
                returnResult[*returnSize - 1] = malloc(sizeof(int) * 3);
                
                // Değerleri ata
                returnResult[*returnSize - 1][0] = nums[i];
                returnResult[*returnSize - 1][1] = nums[start];
                returnResult[*returnSize - 1][2] = nums[end];
                
                // Tekrar eden elemanları atla
                while (start < end && nums[start] == nums[start + 1]) start++;
                while (start < end && nums[end] == nums[end - 1]) end--;
                
                start++;
                end--;
            }
            else if (sum < 0) {
                start++; // Toplamı artırmak için
            }
            else {
                end--; // Toplamı azaltmak için
            }
        }
        
        // Ana indeks için tekrar eden elemanları atla
        while (i < numsSize - 2 && nums[i] == nums[i + 1]) i++;
        i++;
    }
    
    return returnResult;
}

void quick_sort(int *array, int low, int high) {
    if (low >= high) return; // Temel durum
    
    int pivot = array[high]; // Pivot olarak son eleman
    int i = low - 1; // Küçük elemanların indeksi
    
    // Partition işlemi
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            // Swap işlemi
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Pivot'u doğru yerine yerleştir
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    
    int pivotIndex = i + 1;
    
    // Özyinelemeli olarak iki parçayı sırala
    quick_sort(array, low, pivotIndex - 1);
    quick_sort(array, pivotIndex + 1, high);
}
