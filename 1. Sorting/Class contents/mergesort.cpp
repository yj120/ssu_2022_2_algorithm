#include <iostream>
using namespace std;

int arr[8] = {31,20,27,15,467,4,70,24}; // 테스트배열
int sorted[8]; // 정렬시켜서 저장할 배열
void merge(int *data,int left,int right,int middle);
void mergesort(int *data,int left,int right);



int main(){

    mergesort(arr, 0, 7);

    for (int x = 0; x<8;x++){
        cout << arr[x] << " ";
    };
    cout << "\n";
    return 0;
};

void printarr(int *arr, int start, int end){
    for (int i = start; i < end;i++){
        cout << arr[i] << " ";
    };
    cout << "\n";
}

void merge(int *arr, int start, int mid, int end){
    int i = start; // 오른쪽 파트 인덱스
    int j = mid + 1; // 왼쪽 파트 인덱스
    int k = start; // 새로운 배열 인덱스


    while(i <=mid && j<=end){
        if(arr[i]<=arr[j]){
            sorted[k] = arr[i];
            i++;
        }else{
            // arr[i] > arr[j]
            sorted[k] = arr[j];
            j++;
        };
        k++;
    };

    if(i>mid){ // 오른쪽 파트 값 저장
        for (int t = j; t <= end;t++){
            sorted[k] = arr[t];
            k++;
        };
    }else{ // j>end // 왼쪽 파트 값 저장
        for (int t = i; t <= mid;t++){
            sorted[k] = arr[t];
            k++;
        };
    };
    for (int t = start; t <= end;t++){ 
        arr[t] = sorted[t]; // 정렬시킨 범위까지 arr에 다시 넣어준다.
    };

    printarr(arr, start, k);
    //printarr(arr, j, k);
};




void mergesort(int *arr, int left, int right){

    if(left<right){
        int m = (left + right) / 2;
        mergesort(arr, left, m); // 분할
        mergesort(arr, m + 1, right); // 분할
        merge(arr, left, m, right); // 병합
        
    };
};

// bestcase : NlogN
// worstcase : NlogN
// complexity : 세타(NlogN)
