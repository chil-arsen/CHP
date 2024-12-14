#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void drawArray(int arr[], int n) {
    system("cls"); // Clear screen
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Animation: Move the smaller element down and to the right
                for (int k = 0; k < arr[j] - arr[j + 1]; k++) {
                    gotoxy(j, k);
                    printf(" ");
                }
                for (int k = 0; k <= arr[j + 1]; k++) {
                    gotoxy(j + 1, k);
                    printf("*");
                }
                Sleep(50); // Adjust the sleep time for smoother animation

                // Swap the elements in the array
                swap(&arr[j], &arr[j + 1]);

                // Animation: Move the larger element up and to the left
                for (int k = arr[j + 1]; k >= 0; k--) {
                    gotoxy(j, k);
                    printf("*");
                }
                for (int k = arr[j]; k >= 0; k--) {
                    gotoxy(j + 1, k);
                    printf(" ");
                }
                Sleep(50); // Adjust the sleep time for smoother animation

                // Redraw the updated array
                drawArray(arr, n);
            }
        }
    }
}

int main() {
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Set console window size
    system("mode con: cols=20 lines=10");

    // Initial drawing of the array
    drawArray(arr, n);

    // Sorting and animating the process
    bubbleSort(arr, n);

    // Final drawing of the sorted array
    drawArray(arr, n);

    return 0;
}

