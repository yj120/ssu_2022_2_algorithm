#include <iostream>
using namespace std;

void printarr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    };
    cout << "\n";
}

void swap(int *arr,int idx_a,int idx_b){
    int temp;
    temp = arr[idx_a];
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;
}

void bubblesort(int *arr,int size){
    for (int i = 1; i < size;i++){
        for (int j = 0; j <= size-1;j++){
            if (arr[j] > arr[j+1])
            {
                swap(arr, j+1, j);
            };
        };
        printarr(arr, size);
    };
};

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int size;
    int *arr;
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size;i++){
        cin >> arr[i];
    };

    bubblesort(arr, size);

    //printarr(arr, size);
};