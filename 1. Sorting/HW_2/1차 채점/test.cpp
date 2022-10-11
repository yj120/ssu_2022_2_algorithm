// Find kth element

#include <iostream>
#include <vector>
#include <algorithm>
using std::pair;
using namespace std;

struct p{
    int first;
    int second;
};


bool cmp(p&a, p&b);
void function(int *input);

int s;
int N;
int *input = new int[s];
int *answer = new int[s];

int main()
{

    cin >> s;

    cin >> N;

    for (int idx = 0; idx < s; idx++)
    {
        cin >> input[idx];
    };

    function(input);

    delete[] input; // 동적할당한거 delete
    return 0;
};

bool cmp(p&a, p&b)
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

void function(int*input)
{

    vector<pair<int, int>> v;
    vector<p> vec;

    int k = input[0];
    for (int i = 1; i < s; i++)
    {
        k = max(k, input[i - 1]);
    };

    int new_size = k + 1;

    int *count = new int[new_size];

    // 0으로 초기화
    for (int i = 0; i < new_size; i++)
    {
        count[i] = 0;
    };

    // 각 숫자의 인덱스 값 ++
    for (int i = 0; i < s; i++)
    {
        count[input[i]]++;
    };

    for (int i = 0; i < new_size; i++)
    {
        if (count[i] != 0)
        {
            p tmp;
            tmp.first = count[i];
            tmp.second = i;
            vec.emplace_back(tmp);
        };
    };

    cout << " test "<< endl;

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << v[i].second << " ";
    };
};

// 빈도수가 큰 수 부터 출력
// 빈도수가 같으면 내림차순으로 출력
// 시간복잡도 O(n)