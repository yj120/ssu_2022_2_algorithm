#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <queue>
#include <iostream>
using namespace std;


bool visited[100000] = {
    false,
};
char ch[100000];
string st = "";
long long num = 0;

void dfs(int start, vector<int> *arr)
{
    num = +num;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        st += to_string(cur);
        q.pop();
        string tmp = st;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int temp = arr[cur][i];
            // cout << "temp: " << temp << endl;
            if (visited[temp] || arr[temp].size() == 0)
            {
                st += to_string(temp);
                num += stoi(st);
                // cout << "num:" << num << endl;
                st = tmp;
                continue; // 같은 루프에서 장벽
            }
            else
            {
                st = to_string(cur);
                // q.push(temp);
                dfs(temp, arr);
            }
            st = to_string(cur);
        };
    };
};

void function(int *input, int size)
{
    int *list = new int[size];

    vector<int> arr[100000];

    for (int i = 1; i <= size; i++)
    {
        list[i] = input[i - 1];
    };

    int n_size = size / 2;
    for (int i = 1; i <= n_size; i++)
    {
        arr[list[i]].emplace_back(list[i * 2]);
        arr[list[i]].emplace_back(list[i * 2 + 1]);
    };

    dfs(input[0], arr);
    cout << num << endl;
};


int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size; idx++)
    {
        cin >> input[idx];
    };

    function(input, size);
    delete[] input;
    return 0;
};
