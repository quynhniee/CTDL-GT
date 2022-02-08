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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<vector<int> > a;
bool check;
void init () {
    cin >> n;
    vector<int> x;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        for (auto &j : x)   cin >> j;
        a.push_back(x);
    }
    check = false;
}
void backtrack (int i, int j, string s) {
    if (i == n-1 && j == n-1 && a[i][j])   {
        cout << s << " ";
        check = true;
        return;
    }
    else if (i < n && i >= 0 && j < n && j >= 0 && a[i][j]) {
        backtrack(i + 1, j, s + "D");
        backtrack(i, j + 1, s + "R");
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        backtrack(0, 0, "");
        if (!check) cout << "-1";
        cout << endl;
        a.clear();
    }
    return 0;
}