#include "header.h"

int main() 
{
    int n, choice, fillType, i, comp, move;
    int arr[500];

    printf("Введите количество элементов в массиве(max 500): ");
    while (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Неверный ввод, пожалуйста, введите положительное целое число: ");
        while (getchar() != '\n');
    }

    printf("Выберите метом сортировки:\n");
    printf("1. Shell sort\n");
    printf("2. Insertion sort\n");
    printf("3. Bubble sort\n");
    printf("4. Heap sort\n");
    do 
    {
    printf("Введите номер: ");
    if (scanf("%d", &choice) != 1) 
    {
        printf("Неверный ввод. Пожалуйства введите число.\n");
        while (getchar() != '\n');
    }
    else if (choice < 1 || choice > 4)
    {
        printf("Недопустимый выбор. Пожалуйста, введите число от 1 до 4.\n");
    }
} 
while (choice < 1 || choice > 4);

printf("Выберите метод для заполнения массива:\n");
printf("1. Manually enter elements\n");
printf("2. Generate random elements\n");
printf("3. Read from file\n");
do 
{
    printf("Введите номер:");
    if (scanf("%d", &fillType) != 1) 
    {
        printf("Неверный ввод. Пожалуйства введите число.\n");
        while (getchar() != '\n');
    }
    else if (fillType < 1 || fillType > 3) 
    {
        printf("Недопустимый выбор. Пожалуйста, введите число от 1 до 3.\n");
    }
} 
while (fillType < 1 || fillType > 3);

fillArray(arr, n, fillType);

printf("Несортированный массив: ");
printArray(arr, n);

comp = 0;
move = 0;

switch (choice) 
{
    case 1:
    shellSort(arr, n, &comp, &move);
    break;
    case 2:
    insertionSort(arr, n, &comp, &move);
    break;
    case 3:
    bubbleSort(arr, n, &comp, &move);
    break;
    case 4:
    heapSort(arr, n, &comp, &move);
    break;
    default:
    printf("Недопустимый выбор.\n");
    exit(1);
}

printf("Отсортированный массив: ");
printArray(arr, n);

printf("Количество сравнений: %d\n", comp);
printf("Количество ходов: %d\n", move);

return 0;
}
