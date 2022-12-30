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
    map<int, int> dp; // key : value -> position : 1
    vector<int> v;
    bool solve(vector<int> stones, int k, int i,map<int,int> dp)
    {

        if (k <= 0) // jump가 0보다 작으면 return
            return false;

        int next = i; // current position + jump

        if (find(stones.begin(),stones.end(),next)==stones.end()){
            //cout << i << endl;
            return false; // 경로에 없으면 return
        } 
        else{ // 경로에 포함되고, 방문을 체크하지 않았으면 1로 체크
            if(dp.find(i)==dp.end()){
                v.push_back(i);
                dp[i] = 1;
            }else if (dp.find(i)!=dp.end()) // 경로에 포함되고, 방문을 체크했으면 그대로 return
                return false;
        };

        bool jump1 = false;
        bool jump2 = false;
        bool jump3 = false;
        bool jump4 = false;
        
        if (k - 3 > i+k)
        {
            jump1 = solve(stones, k - 3, i + k - 3, dp);
        };
        if (!jump1)
        {
            jump2 = solve(stones, k, i + k, dp);
        };
        if (!jump1 && !jump2)
        {
            jump3 = solve(stones, k + 1, i + k + 1, dp);
        };
        if (!jump1 && !jump2 && !jump3)
        {
            jump4 = solve(stones, k + 2, i + k + 2, dp);
        };
        if (!jump1 && !jump2 && !jump3 && !jump4)
        {
            return 0;
        }


        /*
        solve(stones, k - 3, i + k + 3, dp);
        solve(stones, k, i+k, dp);
        solve(stones, k + 1, i+k + 1, dp);
        solve(stones, k + 2, i+k + 2, dp);
*/
        return 0;
    }

    int canCross(vector<int> stones) // 경로 셋팅
    {
        int k = 1;
        int i = 1;
        if (stones[1] != 1){
            return false;
        } // 무조건 1칸 뛴 1번 부터 시작
            
        solve(stones, k, i,dp);

        return 0;
    }
    int print(){
        int value = *max_element(v.begin(), v.end());
        return value;
    }

    
};
int main(){

    vector<int> input = {0,1,3,5,6,8,12,17};
    Solution s;
    int possible;
    possible = s.canCross(input);
    cout << (s.print()) << endl;

    //delete[] input;
    return 0;
};