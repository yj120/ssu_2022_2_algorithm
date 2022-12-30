#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void function(vector<int> input, int size,int*memo){
    queue<int> list;
    for (int i = 0; i < size;i++){
        list.push(input[i]);
    }

    int start = 0;


    while(!list.empty()){
        int count = 0;
        int cur = list.front();
        list.pop();
        for (int i = start; i < size;i++){
            if(cur>input[i]){
                count++;
            };
        };
        memo[start] = count;
        start++;
    };
    

    for (int i = 0; i < size;i++){
        cout << memo[i] << endl;
    }
}

int main(){

    int size;
    cin >> size;
    int *input = new int[size];
    for (int idx = 0; idx < size; idx++){
        cin >> input[idx];
    };

    int *memo = new int[size];
    vector<int> v;
    vector<int> answer;
    for (int i = 0; i < size;i++){
        v.emplace_back(input[i]);
    };

    function(v, size,memo);

    
}