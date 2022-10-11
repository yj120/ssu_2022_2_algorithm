#include <iostream>
using namespace std;


void printarr(int *arr, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        cout << arr[i] << " ";
    };
    cout << "\n";
}

void merge(int *arr, int start, int m, int end)
{
    int i, j, k;

    int n1 = m - start + 1;
    int n2 = end - m;

    int *L, *R;
    L = new int[n1];
    R = new int[n2];


    /*왼쪽, 오른쪽 배열에 각각 시작~중간, 중간~끝 값을 넣는다.*/
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
        //cout << "L[i]"<< L[i] << endl;
    };

    
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        //cout << "R[j]"<< R[j] << endl;
    }

    /*인덱스 커서 재설정*/
    i = 0;
    j = 0;
    k = start;

    /*커서 i와 j가 배열 사이즈를 초과하지 않을 때, 계속 왼쪽배열 vs 오른쪽배열 비교*/
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        };
        k++;
    };

    /*커서 i와 j가 배열 사이즈를 넘었을 때-> 배열의 남은 값들을 저장해주기 위함*/
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    };

    // 정렬시킨 k번째 인덱스까지, arr출력
    for (int i = start; i < k;i++){
        cout << arr[i] << " ";
    };
    cout << "\n";
    
};

void sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int m = (start + end) / 2;
        sort(arr, start, m);
        sort(arr, m + 1, end);
        merge(arr, start, m, end);
    };
};

int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int size;
    cin >> size;
    // int input[size];

    int *input;
    input = new int[size];
    for (int idx = 0; idx < size; idx++)
    {
        cin >> input[idx];
    }

    sort(input, 0, size-1);

};