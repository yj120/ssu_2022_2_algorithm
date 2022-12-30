#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
using namespace std;

/*


https://www.techiedelight.com/ko/print-all-paths-from-leaf-to-root-binary-tree/
참고해서 수정하기


재귀를 고쳐야함 시간 조건에서 걸리는 듯...하


*/

struct Node{
    int val = 0;
    int left = 0;
    int right = 0;
};


Node *list[1000];
string st = "";
vector<string> result;

void dfs(int start, int size){

    /*
        string s="";
        string ss = "";
        stack<int> first;
        stack<int> second;
        int cur = 0;
        int iter;
        iter = list[start]->left;
        Node *nptr;
        nptr = list[1];
        int temp = 1;



    /// 깔끔하게 ..똑똑하게 고쳐보자
        s += to_string(list[1]->val);
        while(nptr->left<=size){
            //s += to_string(nptr->val);
            first.push(nptr->val);
            nptr = list[nptr->left];
            s += to_string(nptr->val);
        };

        cout << s << endl;

        Node *rnptr;
        rnptr = list[1];
        while(rnptr->right<=size){
            //s += to_string(nptr->val);
            first.push(rnptr->val);
            rnptr = list[rnptr->right];
            ss += to_string(rnptr->val);
        };

        cout << ss << endl;


        */

};



void printpath(vector<int> const &path)
{
    for (int i = 0; i < path.size(); i++)
    {
        //cout << path.at(i) << endl;
        st += to_string(path.at(i));
    };
    result.push_back(st);
    st = "";
    //cout << "whar? "<< path.at(0) << endl; // 구분자였음

    
};



void printleafnode(Node* node, vector<int> &path,int size){

    // 기본 케이스
    if(!node){
        return;
    };

    // 현재 노드를 경로에 포함
    path.push_back(node->val);

    // 리프노드가 발견되면 경로를 인쇄합니다.
    if(node->left>size || node->right>size){
        printpath(path);
    };

    printleafnode(list[node->left], path, size);
    printleafnode(list[node->right], path, size);

    path.pop_back();
};



void printleafnode(Node *node,int size){
    vector<int> path;
    printleafnode(node, path, size);
};



void function(int *input, int size){

    //Node* list[1000];

    for (int i = 1; i <= size;i++){
        Node *node = new Node;
        node->val = input[i - 1];
        node->left = i * 2;
        node->right = i * 2 + 1;
        list[i] = node;
        //delete[] node;
    };


    printleafnode(list[1],size);

    //cout << "sival" << endl;

    int sum = 0;
    for(int i=0;i<result.size();i++){

        sum += stoi(result[i]);
    };
    cout << sum << endl;
    return;
};

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int idx = 0; idx < size; idx++)
    {
        cin >> input[idx];
    };

    function(input,size);
    delete[] input;
    return 0;
};