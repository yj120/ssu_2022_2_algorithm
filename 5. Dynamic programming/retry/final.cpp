#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



class Solution {
public:
    map<int,bool> mp;
    vector<int> v;
    bool recursion(int pos, int prevStep, vector<int>& arr, int n, map<pair<int,int>,bool>& memo){

        if(mp[pos]== false || pos > arr[n-1]) return false;
        if(pos == arr[n-1]){
            v.push_back(pos);
            return true;
            
        } 
        if(memo.find({pos,prevStep}) != memo.end()){
            v.push_back(pos);
            return memo[{pos,prevStep}];
            
        };

        bool isPossible;

        if(pos==0){
            isPossible = recursion(pos+1,1,arr,n,memo);
        }
        else{
            if(prevStep-3>0) 
                
                isPossible = recursion(pos+(prevStep-3),prevStep-3,arr,n,memo);
            if(isPossible){
                v.push_back(pos);
                return true;}
            isPossible = recursion(pos+prevStep,prevStep,arr,n,memo);
            if(isPossible) {
                v.push_back(pos);
                return true;}
            isPossible = recursion(pos+(prevStep+1),prevStep+1,arr,n,memo);
            if(isPossible){
                v.push_back(pos);
                return true;}
            isPossible = recursion(pos+(prevStep+2),prevStep+2,arr,n,memo);
            if(isPossible) {
                v.push_back(pos);
                return true;
            };
        }
        
        memo[{pos,prevStep}] = isPossible;
        v.push_back(pos);
        return isPossible;

    }

    bool canCross(vector<int>& stones) {
        
        for(auto itr : stones){ 
            mp[itr] = true;
           
        }
        map<pair<int,int>,bool> memo;
        int n = stones.size();
        return recursion(0,1,stones,n,memo);
    }
    int show(){
        int answer = *max_element(v.begin(), v.end());
        return answer;
    }
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
    vector<int> v;

    for (int i = 0; i < size; i++)
    {
        v.emplace_back(input[i]);
    }
    Solution s;
    cout << (s.canCross(v)) << endl;
    cout << (s.show());
    delete[] input;
    return 0;
}
