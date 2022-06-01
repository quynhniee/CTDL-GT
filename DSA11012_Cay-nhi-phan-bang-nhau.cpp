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

int n, u, v;
char x;

bool isEqual (Node *r1, Node *r2) {
    if (r1 == NULL and r2 == NULL)  return true;
    if (r1->data != r2->data) return false;
    return isEqual (r1->left, r2->left) and isEqual (r1->right, r2->right);
}
void solution () {
    Node *r1 = NULL, *r2 = NULL;
    int n; cin >> n;
    while (n--) {
        cin >> u >> v >> x;
        if (r1 == NULL)  r1 = new Node(u);
        Insert(r1, u, v, x);
    }
    int m; cin >> m;
    while (m--) {
        cin >> u >> v >> x;
        if (r2 == NULL)  r2 = new Node(u);
        Insert(r2, u, v, x);
    }
    cout << isEqual(r1, r2) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}