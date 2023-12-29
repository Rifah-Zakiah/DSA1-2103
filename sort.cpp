#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

void print(int arr[], int n);

int main(){
    int n;
    cout << "Enter number of elements to sort:" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elemnts for bubble sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }
    bubbleSort(a, n);
    print(a, n);
    cout << "Enter the elemnts for selection sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }
    selectionSort(a, n);
    print(a, n);
    cout << "Enter the elemnts for insertion sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }
    insertionSort(a, n);
    print(a, n);

    return 0;
}
void bubbleSort(int arr[], int n){
    bool flag = false;
    
    for(int i = 0; i < n - 1; i++)
    {                                 
        for(int j = 0; j < n-i-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n ; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            swap(arr[i], arr[min]);
        }
    }
}
void insertionSort(int arr[], int n){
    int k, j;
    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i;
        while (j > 0 && arr[j-1] > k)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = k;
    }
}
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}