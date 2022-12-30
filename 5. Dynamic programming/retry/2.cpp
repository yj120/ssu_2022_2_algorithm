#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std;
typedef long long int lli;
class Solution
{
public:
    map<lli, int> visited;
    vector<int> num;
    int max_value;
    bool canCross(vector<int> stones, int pos = 1, int k = 1)
    {
        lli key = pos;
        if (visited.find(key) != visited.end())
        {
            num.push_back(key);
            return visited[key];
        };
        cout << pos <<"" << k << endl;

        if(k<0){
            return visited[key] = false;
        }

        int gap = stones[pos] + k;
        cout << "gap :" << gap << endl;

        if(find(stones.begin(),stones.end(),gap)==stones.end()){
            return visited[key] = false;
        }else{
            canCross(stones, gap, k);
            //visited[key] = true;
        }

        /*for (int i = pos + 1; i < stones.size(); i++)
        {
            int gap = stones[i] - stones[pos];


            if (gap < k - 3)
                continue;

            if (gap > k + 3) // 이렇게는 못움직임
            {
                return visited[key] = false;
            }
            if (canCross(stones, i, gap))
            {
                return visited[key] = true;
            }
            ;
        }*/
        num.push_back(key);
        return visited[key] = (pos == stones.size() - 1);
    };

    int ans()
    {
        max_value = *max_element(num.begin(), num.end());
        return max_value;
    }
};
int main()
{
    Solution ob;
    vector<int> v = {0, 1, 2, 3, 8, 9, 11};
    ob.canCross(v);
    cout << (ob.ans());
}