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
    Node *left;
    Node *right;
    Node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int n;

void MakeNode (Node* root, int u, int v, char c) {
    c == 'L' ? root->left = new Node(v) : root->right = new Node(v);
}

void Insert (Node* root, int u, int v, char c) {
    if (root == NULL)   return;
    if (root->data == u)    MakeNode(root, u, v, c);
    else {
        Insert(root->left, u, v, c);
        Insert(root->right, u, v, c);
    }
}
int Level (Node* root) {
    if (root == NULL)   return 0;
    else if (root->left == NULL && root->right == NULL) return 1;
    return Level(root->left) + Level(root->right); 
}
void test_case () {
    cin >> n;
    int u, v; char c;
    Node *root = NULL;
    while (n--) {
        cin >> u >> v >> c;
        if (root == NULL)   root = new Node(u);
        Insert (root, u, v, c);
    }
    cout << (Level(root->left) == Level(root->right)) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test_case();
    return 0;
}