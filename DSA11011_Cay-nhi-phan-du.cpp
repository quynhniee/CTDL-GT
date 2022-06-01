#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
struct Node {
    int data;
    Node *left, *right;
    Node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void MakeNode (Node* root, int u, int v, char x) {
    x == 'L' ? root->left = new Node(v) : root->right = new Node(v);
}
void Insert (Node* root, int u, int v, char x) {
    if (root == NULL)   return;
    else if (root->data == u) MakeNode(root, u, v, x);
    else {
        Insert(root->left, u, v, x);
        Insert(root->right, u, v, x);
    }
}
bool isFull (Node* root) {
    if (root == NULL)   return true;
    if (root->left == NULL && root->right == NULL)  return true;
    if (!(root->left != NULL && root->right != NULL))   return false;
    return isFull(root->left) and isFull(root->right);
}
void solution () {
    int n, u, v;
    char x;
    cin >> n;
    Node* root = NULL;
    while (n--) {
        cin >> u >> v >> x;
        if (root == NULL)   root = new Node (u);
        Insert(root, u, v, x);
    }
    cout << isFull(root) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}