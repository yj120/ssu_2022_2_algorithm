#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;



bool visited[2000]={false,};


vector<pair<int,int>> jump(int start,int jump){
    vector<pair<int,int>> ans;
    int a, b, c, d;

    a = jump - 3;
    b = jump;
    c = jump + 1;
    d = jump + 2;
    ans.emplace_back(start+a,a);
    ans.emplace_back(start+b,b);
    ans.emplace_back(start+c,c);
    ans.emplace_back(start+d,d);

    return ans;
}

void function(int *input, int size){
    vector<int> v;
    for(int i=0;i<size;i++){
        v.emplace_back(input[i]);
    };

    v.push_back(0);
    //////

    visited[1] = true;
    stack<pair<int, int>> path;
    vector<pair<int,int>> next;
    bool present;
    next = jump(1,1); // 

    for(int i=0;i<next.size();i++){
        int cur = next[i].first;
        if(find(v.begin(),v.end(),cur)!=v.end()){
            path.push(next[i]);
        };
    };

    vector<int> check;
    while(!path.empty()){
        pair<int, int> cur;
        vector<pair<int, int>> next;
        cur = path.top();
        path.pop();
        visited[cur.first] = true;
        check.emplace_back(cur.first);

        next = jump(cur.first, cur.second);

        for(int i=0;i<next.size();i++){
            int cur = next[i].first;
            if(find(v.begin(),v.end(),cur)!=v.end()){
                if(!visited[cur]){
                    path.push(next[i]);
                };
            };
        };
    };
/*
    for(int i=0;i<check.size();i++){
        cout << check[i] << " ";
    };
*/
    int max_value = *max_element(check.begin(), check.end());
    cout << max_value << endl;
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
};