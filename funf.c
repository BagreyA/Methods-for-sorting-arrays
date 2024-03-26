include "header.h"

void shellSort(int arr[], int n, int *comp, int *move)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                (*comp)++;
                (*move)++;
                arr[j] = arr[j - gap];
            }
            (*comp)++;
            arr[j] = temp;
        }
    }
}

void insertionSort(int arr[], int n, int *comp, int *move)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            (*comp)++;
            (*move)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        (*comp)++;
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n, int *comp, int *move)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            (*comp)++;
            if (arr[j] > arr[j + 1])
            {
                (*move)++;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void heapify(int arr[], int n, int i, int *comp, int *move)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
      {
        largest = l;
      }
    (*comp)++;

    if (r < n && arr[r] > arr[largest])
      {
        largest = r;
      }
    (*comp)++;
  
    if (largest != i)
      {
        (*move)++;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest, comp, move);
      }
  }

void heapSort(int arr[], int n, int *comp, int *move)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
      heapify(arr, n, i, comp, move);
    }

    for (i = n - 1; i >= 0; i--)
    {
        (*move)++;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0, comp, move);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArray(int arr[], int n, int fillType)
{
    int i;
    switch (fillType)
    {
        case 1:
        for (i = 0; i < n; i++)
        {
            printf("Введите элемент %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        break;
        case 2:
        srand(time(NULL));
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000;
        }
        break;
        case 3:
        FILE *file;
        file = fopen("input.txt", "r");
        if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        exit(1);
    }

  for (i = 0; i < n; i++)
    {
      fscanf(file, "%d", &arr[i]);
    }
  fclose(file);
  break;

  default:
  printf("Недопустимый тип заполнения.\n");
  exit(1);
  }
}
