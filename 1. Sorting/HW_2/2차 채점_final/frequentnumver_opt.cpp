// Find kth element

// map 자료구조를 써보자
// input number(key) : freq(value)++;
// vector<pair<int,int>> p;

// p.emplace_back(value,key)

// quicksort 로 p.first 기준으로 정렬

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using std::pair;
using namespace std;
void function(int *input,int size,int N);
int main(){
    int s;
    int N;
    
    cin >> s;

    // 쓰레기값 이슈 없도록 주의하자 

    int *input = new int[s];
    cin >> N;

    for (int idx = 0; idx < s; idx++)
    {
        cin >> input[idx];  
    };

    function(input,s,N);

    return 0;
};


bool cmp(const pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    else
    {
        return a.first > b.first;
    }
}

void function(int *input, int size, int N)
{
    map<int, int> m;
    vector<pair<int, int>> v;
    

    for (int i = 0; i < size;i++){
        m[input[i]]++;
    };

    for(auto p : m){
        int first, second;
        first = p.second;
        second = p.first;
        v.emplace_back(first, second);
    };

/*
    for (int i = 0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    };
*/
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].second << " ";
    };
};

// 빈도수가 큰 수 부터 출력
// 빈도수가 같으면 내림차순으로 출력
// 시간복잡도 O(n)
// 