#include<stdio.h>

int size = 0;
void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i);
void insert(int array[], int data);
void delete(int array[], int num);
void print(int array[]){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[10];
    insert(array, 9);
    insert(array, 4);
    insert(array, 2);
    insert(array, 5);
    insert(array, 3);
    printf("The minheap after insertion: ");
    print(array);

    delete(array, 4);
    printf("The minheap after deletion: ");
    print(array);

    delete(array, 55);

    return 0;
}
void heapify(int array[], int size, int i){
    if (size == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    if (size == 1)
    {
        printf("Heap has only one element.\n");
        return;
    }
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < size && array[left] < array[smallest])
        smallest = left;
    if(right < size && array[right] < array[smallest]) 
        smallest = right;
    if (smallest != i)
    {
        swap(&array[i], &array[smallest]);
        heapify(array, size, smallest);
    }
}
void insert(int array[], int data){
    if (size == 0)
    {
        array[0] = data;
        size++;
        return;
    }
    array[size]= data;
    size++;
    for (int i = size/2 - 1; i >= 0 ; i--)
    {
        heapify(array, size, i);
    }
}
void delete(int array[], int num){
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == num)
        {
            break;
        }
    }
    if (i == size)
    {
        printf("%d does not exist in the heap.\n", num);
    }
    swap(&array[i], &array[size-1]);
    size--;
    for (int i = size/2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}