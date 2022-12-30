#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <queue>
using namespace std;

bool visited[100]={false,};
char ch[100];
string st = "";
int num = 0;
vector<int> result;

void dfs(int start, vector<int> *arr){
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        st += to_string(cur);
        q.pop();
        string tmp = st;
        for (int i = 0; i < arr[cur].size();i++){
            int temp = arr[cur][i];
            if(visited[temp] || arr[temp].size()==0){ // 방문을했거나, 방문할 위치의 사이즈가 0 인경우
                st += to_string(temp);
                num =stoi(st);
                //num += num;
                cout <<"num:" << num << endl;
                result.push_back(num);
                st = tmp;
            }else{
                st = to_string(cur);
                //q.push(temp);
                dfs(temp, arr);
            }
            st = to_string(cur);
        };
    };
    int sum = 0;
    for (int i = 0; i < result.size();i++){
        sum += result[i];
    };
    //cout << sum << endl;
};

void function(int *input,int size){
    int *list = new int[size];

    vector<int> arr[100];

    for(int i=1;i<=size;i++){
        list[i] = input[i - 1];
    };

    int n_size = size / 2;
    for (int i = 1; i <= n_size; i++)
    {
        arr[list[i]].emplace_back(list[i * 2]);
        arr[list[i]].emplace_back(list[i * 2 + 1]);
    };
    dfs(input[0], arr);
};



int main(){
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size;idx++){
        cin >> input[idx];
    };

    function(input,size);

    delete[] input;
    return 0;
}