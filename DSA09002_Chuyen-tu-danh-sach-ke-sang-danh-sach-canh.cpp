#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
int n;
vector<vector<int> > edge;
void pushElements (vector<int> &b, int row) {
    stringstream ss(s);
    string token;
    while (ss >> token) {
        int val = stoi(token);
        if (val > row)  b.push_back(val);
    }
}
void input () {
    cin >> n;
    edge.resize(n+1);
    FOR (i, 1, n) {
        scanf("\n");
        getline(cin, s);
        pushElements(edge[i], i);
    }
}
void output () {
    FOR (i, 1, n-1) 
        for (auto j:edge[i])
            cout << i << " " << j << endl;
}
void test () {
    input();
    output();
    edge.clear();
}
int main () {
    test();
    return 0;
}