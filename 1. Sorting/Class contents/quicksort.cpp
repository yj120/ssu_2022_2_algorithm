#include <iostream>
#include <random>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r;i++){
        if(arr[i]==x){
            break;
        };
    };
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r-1;j++){
        if(arr[j]<=x){
            swap(&arr[i], &arr[j]);
            i++;
        };
    };
    swap(&arr[i], &arr[r]);
    return i;
};


// return 부분이 강의자료에는 없음 확인...
int select(int arr[],int l,int r,int k){
    int pos = 0;
    if(k>=0 && k<r-l+1){
        int n = r -l + 1;
        int pivot = arr[l + rand() % n];

        int pos = partition(arr, l, r, pivot);
        
        if (pos - l == k)
        {
            return arr[pos];
        }
        else if (pos - l > k)
        {
            return select(arr, l, pos - l, k);
        }
        else
        {
            return select(arr, pos + l, r, k - pos + l - 1);
        };
    };
    return arr[pos];
};
int main(){

    int arr[] = {77, 5, 3, 9, 18, 4, 43, 2, 1, 13};
    int ans = select(arr, 0, 9, 3);
    cout << "ans: "<< ans << endl;

    int s = sizeof(arr) / sizeof(int);
    for (int i = 0; i < s;i++){
        cout << arr[i] << " ";
    };
    cout << "\n";
};