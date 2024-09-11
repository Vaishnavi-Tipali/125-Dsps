#include <stdio.h>
int price[10];
void arr1() {
    printf("\nBooks having price less than 500:\n");
    for (int i = 0; i < 10; i++) {
        if (price[i] < 500) {
            printf("%d ", price[i]);
        }
    }
    printf("\n");
}
void arr2() {
    printf("\nDuplicate prices:\n");
    int foundDuplicate = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (price[i] == price[j]) {
                
                int isPrinted = 0;
                for (int k = 0; k < i; k++) {
                    if (price[k] == price[i]) {
                        isPrinted = 1;
                        break;
                    }
                }
                if (!isPrinted) {
                    printf("%d ", price[i]);
                    foundDuplicate = 1;
                }
            }
        }
    }
    if (!foundDuplicate) {
        printf("No duplicates found");
    }
    printf("\n");
}

int main() {
    
    printf("Enter the price of 10 books:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &price[i]);
    }

   
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (price[j] > price[j + 1]) {
                int temp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp;
            }
        }
    }

   
    printf("Sorted prices:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", price[i]);
    }
    printf("\n");

   
    arr1();
    arr2();

    return 0;
}

