#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution
{
public:
    map<pair<int,int>,bool> dp;
    int last;
    vector<int> ans;
    int canCross(vector<int> stones, int pos = 1, int k = 1)
    {
        // 주어진 경로상에 있는 지 확인
        if (find(stones.begin(), stones.end(),pos)== stones.end())
        {
            return 0;
        };
        // k가 (점프 크기가 0보다 작을 때는 return )
        if(k<0){
            return 0;
        };

        // 이미 방문한 곳을 또 방문한다면 return
        if(dp[{pos,k}]==1){
            return 0;
        };

        dp[{pos, k}] = 1;
        ans.push_back(pos);

        bool cond1, cond2, cond3, cond4;

        if(k-3>0){
            cond1 = canCross(stones, pos + k - 3, k - 3);
        };
        if(!cond1){
            cond2 = canCross(stones, pos + k, k);
        };
        if(!cond1 && !cond2){
            cond3 = canCross(stones, pos + k + 1, k + 1);
        };
        if(!cond1 && !cond2 && !cond3){
            cond4 = canCross(stones, pos + k + 2, k + 2);
        };
        if(!cond1 && !cond2 && !cond3 && !cond4){
            return 0;
        };
        return 0;
    };
    int result(){
        int max_value;
        max_value = *max_element(ans.begin(), ans.end());
        return max_value;
    }
};
int main()
{
    Solution ob;
    vector<int> v = {0, 1, 3, 5, 6, 8, 12, 17};
    //ob.canCross(v);
    (ob.canCross(v));
    cout << (ob.result());
}