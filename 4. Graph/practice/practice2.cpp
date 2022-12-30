#include <iostream>
#include <vector>
using namespace std;

// 이진 트리 노드를 저장할 데이터 구조
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// 주어진 노드가 리프 노드인지 확인하는 함수
bool isLeaf(Node *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

// Vector에 있는 경로를 역순으로 인쇄합니다(리프 노드에서 루트 노드까지).
void printPath(vector<int> const &path)
{
    for (int i = 0; i< path.size(); i++)
    {
        cout << path.at(i) << " > ";
    }

    //cout << path.at(0) << endl;
}

// 리프에서 루트 노드까지의 모든 경로를 출력하는 재귀 함수
void printLeafToRootPaths(Node *node, vector<int> &path)
{
    // 기본 케이스
    if (node == nullptr)
    {
        return;
    }

    // 현재 노드를 경로에 포함
    path.push_back(node->data);

    // 리프 노드가 발견되면 경로를 인쇄합니다.
    if (isLeaf(node))
    {
        printPath(path);
    }

    // 왼쪽 및 오른쪽 하위 트리에 대해 반복
    printLeafToRootPaths(node->left, path);
    printLeafToRootPaths(node->right, path);

    // backtrack: 왼쪽, 오른쪽 하위 트리가 완료된 후 현재 노드를 제거합니다.
    path.pop_back();
}

// 리프에서 루트 노드까지의 모든 경로를 출력하는 메인 함수
void printLeafToRootPaths(Node *node)
{
    // 리프-루트 경로를 저장할 Vector
    vector<int> path;

    // 재귀 함수 호출
    printLeafToRootPaths(node, path);
}

int main()
{
    /* 다음 트리 생성
               1
             /   \
            /     \
           /       \
          2         3
         / \       / \
        /   \     /   \
       4     5   6     7
                / \
               /   \
              8     9
    */

    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(0);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    /*
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
*/
/*
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i=0;i<9;i++){
        Node *root = new Node(arr[i]);
        if(root->left==NULL){
            root->left = new Node(arr[i]);
        }else if(root->right==NULL){
            root->right = new Node(arr[i]);
        }else{

        }
        root = root->left;
        root = root->right;
    }
    */

    // 모든 리프에서 루트 경로를 인쇄합니다.
    printLeafToRootPaths(root);

    return 0;
}
