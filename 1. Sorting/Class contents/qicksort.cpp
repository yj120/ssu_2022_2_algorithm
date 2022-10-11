#include <iostream>

using namespace std;

int arr[10] = {23, 123, 324234, 12312, 2123, 24, 456, 56, 123, 564};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(int list[], int left, int right) // pivot을 맨 왼쪽 값으로 정해놓고 시작
{
    if (left >= right)
        return;
    int pivot = left;
    int start = left + 1;
    int end = right;
    while (start <= end) // start가 end 범위 안에서 움직일 때 loop
    {
        while (list[pivot] >= list[start] && start <= right)
            start++; // start 값이 더 클 때 까지 start index 오른쪽으로
        while (list[pivot] <= list[end] && end > left)
            end--; // end 값이 더 작을 때 까지 end index 왼쪽으로
        if (start > end) // start가 end 범위 넘어가면
        {
            swap(list[pivot], list[end]);
        }
        else
            swap(list[start], list[end]); // pivot 값 보다 start index value가 더 크고, // pivot < start index value
                                          // pivot 값이 end index value보다 클때 // pivot > end index value
                                          // -> start index <> end index swap
                                         // 
                                         // 
                                         // 
    }
    quick_sort(list, left, end - 1);
    quick_sort(list, end + 1, right);
}
int main()
{
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}