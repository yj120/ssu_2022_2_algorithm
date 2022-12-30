#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int dp[2001][2001];
    vector<int> v;
    int solve(vector<int> stones, int k, int i)
    {

        if (k < 0) // jump가 0보다 작으면 return
            return 0;

        if (find(stones.begin(), stones.end(), i) == stones.end())
        {
            return 0; // 경로에 없으면 return
        }
        v.push_back(i);

        return 0;
    }

    int canCross(vector<int> stones) // 경로 셋팅
    {
        int k = 1;
        int i = 1;
        for (int i = 0; i < 2001; i++)
        {
            memset(dp[i], -1, sizeof(int) * 2001);
        } // -1로 모두 설정해서 dp[][] 초기화

        if (stones[1] != 1) // 무조건 1칸 뛴 1번 부터 시작
            return false;
        solve(stones, k, i);

        return 1;
    }
    /*
    int print()
    {
        int value = *max_element(v.begin(), v.end());
        return value;
    }*/
};
int main()
{

    vector<int> input = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << "db" << endl;
    Solution s;
    int possible;
    possible = s.canCross(input);
    //cout << (s.print()) << endl;

    // delete[] input;
    return 0;
};