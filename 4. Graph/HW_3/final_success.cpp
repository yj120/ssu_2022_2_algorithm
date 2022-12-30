#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<int> num_list;
int temp = 0;
int result = 0;

void recur(int *input,int num,int e,int index){
    
    if(index<1){
        result += temp;
        num_list.push_back(temp);
        temp = 0;
        return;
    }
    temp += pow(10, e) * num;
    index = index / 2;
    num = input[index];
    e++;
    
    recur(input,num,e,index);
};




void function(int* arr, int size){

    int *new_arr = new int[size];
    for (int i = 0; i < size;i++){
        new_arr[i + 1] = arr[i];
    };
    int leaf = 0;
    if (size%2==0){
        leaf = size / 2;
    }
    else{
        leaf = size / 2 + 1;
    }
    
    int e = 0;
    int start = size;

    //cout << "leaf: " << leaf << endl;

    for (int i = 0; i < leaf;i++)
    {
        recur(new_arr, new_arr[start], e, start);
        start--;
    };
    
    int sum = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        sum += num_list[i];
    }
    //cout << sum << endl;
    cout << result << endl;
};





int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size; idx++)
    {
        cin >> input[idx];
    }

    function(input, size);

    delete[] input;
    return 0;
};
