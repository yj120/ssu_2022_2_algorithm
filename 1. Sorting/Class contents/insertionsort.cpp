#include <iostream>
#include <vector>

using namespace std;
void insertionsort(vector<int> &arr);
void print(vector<int> arr);
int main(){

    vector<int> arr = {5, 3, 7, 1, 9, 14, 2, 0, -1, 19};

    insertionsort(arr);
    print(arr);

};

void insertionsort(vector<int> &arr){
    for (int i = 1; i < arr.size();i++){
        int cur = arr[i];
        int j = i - 1;
        while (j >= 0 && cur<arr[j]){
            arr[j + 1] = arr[j];
            j--;
        };
        arr[j + 1] = cur;
    };
};

void print(vector<int> arr){
    for (int i = 0;i<arr.size();i++){
        cout << arr[i] << " ";
    };
};

// bestcase: n (헤더 조건을 한번씩만 확인) 이미 정렬이 되어 있는 상태
// worstcase : n^2 반대로 정렬이 되어 있는 상태
// time complexity : O(n) , 오메가(n^2)
