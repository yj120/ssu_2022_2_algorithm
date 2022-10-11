#include <iostream>
#include <map>

using namespace std;

int main(){

    int n;
    cin >> n;
    int *l = new int[n];

    for (int i = 0; i < n;i++){
        cin >> l[i];
    };
    
    
    map<int, int> m;

    for (int i = 0; i < n;i++){
        m[l[i]]++;
    };

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
}