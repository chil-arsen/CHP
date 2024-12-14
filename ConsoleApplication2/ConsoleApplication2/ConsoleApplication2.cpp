#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>

// Գույների մուտքագրում
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Ստուգում է թվի պարզ լինելը
bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;

    return true;
}

int main() {
    srand(time(0));

    int N, max, min;
    // Կուրսորի դիրքի որոշման փոփոխական
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        printf("Enter N ");
        scanf("%d", &N);
    } while (N < 0);

    do {
        printf("Enter max min ");
        scanf("%d %d", &max, &min);
    } while (max < min || min < 0 || max < 0);

    int* arr = (int*)malloc(N * sizeof(int));  // Dynamic memory allocation
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Exit with an error code
    }

    // Կուրսորի դիրքի մուտքագրում
    pos.Y = 5;
    // Պատահական թվերի գեներատոր
    for (int i = 0; i < N; i++) {
        pos.X = 30 + 6 * i;
        SetConsoleCursorPosition(hConsole, pos);
        int num = rand() % (max - min + 1) + min;
        arr[i] = num;
        printf("%6d", num);
        // Անիմացիայի քայլերի դանդաղացում
        for (int time = 1; time < 1e+7; time++);
    }

    // Ըստ աճման կարգի դասավորում
    for (int j = 0; j < N - 1; j++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for (int i = 0; i < N - j - 1; i++) {
            pos.X = 30 + 6 * i;
            SetConsoleCursorPosition(hConsole, pos);
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];

                // ... (animation part)

                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            for (int time = 1; time < 1e+7; time++);
        }
    }

    pos.X = 30;
    pos.Y = 7;
    // Պարզ արտադրիչների որոշում և արտածում
    for (int i = 0; i < N; i++) {
        int num = arr[i];
        int j = 2;
        pos.X = 30 + 6 * i;
        pos.Y = 7;
        while (j <= num) {
            if (num % j == 0 && isPrime(j)) {
                num /= j;
                SetConsoleCursorPosition(hConsole, pos);
                printf(ANSI_COLOR_BLUE "%6d", j);
                pos.Y += 2;
                j = 2;
                for (int time = 1; time < 1e+7; time++);
            }
            else {
                j++;
            }
        }

        pos.X += 6;
    }

    // Վերադարձնում է սկզբնական գույնին
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    // Don't forget to free the allocated memory
    free(arr);

    return 0;
}
