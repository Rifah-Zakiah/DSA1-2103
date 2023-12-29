#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n);
int insertX(int a[], int n, int pos, int x);
int deleteX(int a[], int n, int x);
int linsrc(int a[], int n, int x);
int binsrc(int a[], int l, int r, int x);
void reverse(int a[], int s, int e);
//******************reverse the linked list function lagbe******************

int main(){
    int a[100] = {8, 64, 9, 56, 67, 64, 2, 16, 3};
    int n = 10;
    cout << "Initial array is:" << endl;
    print(a, n - 1);
    
    cout << "Modified array with 25 at 6th position is:" << endl;
    insertX(a, n, 6, 25);
    print(a, n);
    cout << "Modified array with deleted element 9 is:" << endl;
    deleteX(a, n, 9);
    print(a, n - 1);

    cout << "Enter element for linear search: " << endl;
    int x;
    cin >> x;
    int r = linsrc(a, n-1, x);
    if (r == -1)
    {
        cout << x << " does not exist in the array." << endl;
    }else
    {
        cout << x << " is in position " << r << " in the array." << endl;
    }
    sort(a, a+n-1);
    cout << "Enter element for linear search: " << endl;
    cin >> x;
    r = binsrc(a, 0, n-2, x);
    if (r == -1)
    {
        cout << x << " does not exist in the array." << endl;
    }else
    {
        cout << x << " is in position " << r << " in the array." << endl;
    }
    // reverse(a, 0, n);
    // cout << "Reversed array is: " << endl;
    // print(a, n); 

    return 0;
}
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int insertX(int a[], int n, int pos, int x){
    //n++;
    for (int i = n; i >= pos; i--)
    {
        a[i] = a[i-1];
    }
    a[pos - 1] = x;

    return 0;
}
int deleteX(int a[], int n, int x){
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            break;
        }
    }
    if (i < n)
    {
        n = n-1;
        for (int j = i; j < n; j++)
        {
            a[j] = a[j+1];
        }    
    }
    
    return n;
}
int linsrc(int a[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
        
    }

    return -1;
}
int binsrc(int a[], int l, int r, int x){
    while (l <= r)
    {
        int m = (l+r)/2;
        if (a[m] == x)
        {
            return m;
        }else if (a[m] < x)
        {
            l = m + 1;
        }else
        {
            r = m - 1;
        } 
    }

    return -1;
}
void reverse(int a[], int s, int e){
    while (s < e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
    
}