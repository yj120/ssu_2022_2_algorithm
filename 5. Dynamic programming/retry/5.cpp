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
    vector<int> answer;
    bool canCross(vector<int> &stones)
    {
        map<int, set<int>> hashMap; // Initializing required hashmap.
        hashMap[stones[0] + 1] = {1};                   // Viable Jump Sizes to reach 2nd stone.
        for (int i = 1; i < stones.size(); ++i)
        {                             // Traversing all positions
            int position = stones[i]; // Current Position
            for (auto it : hashMap[position])
            {                                      // Traversing all viable jump sizes that can be used from current position.
                hashMap[position + it-3].insert(it-3);
                //cout << it-3 << endl;
                hashMap[position + it].insert(it); // Populating the sets of positions that can be reached from current position with a viable jump size.
                //cout << it << endl;
                hashMap[position + it + 1].insert(it + 1);
                //cout << it+1 << endl;
                hashMap[position + it + 2].insert(it +2);
                cout << it + 2 << endl;
            }
        }
        return hashMap[stones.back()].size() != 0; // Checking the set size of last stone.
    }
};
int main()
{

    vector<int> input = {0, 1, 3, 8,9,11};
    Solution sol;
    cout << (sol.canCross(input)) << endl;
    return 0;
};