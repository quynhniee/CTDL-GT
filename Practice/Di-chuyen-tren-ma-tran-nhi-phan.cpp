#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <bitset>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<vector<string> > a;
void init () {
    cin >> n;
    a.assign(n+1, vector<string>(n+1, "0"));
    FOR (i, 0, n-1)
        FOR (j, 0, n-1)
            cin >> a[i][j];
}

void binToHex (string s) {
    bitset<200> set(s);
    cout << hex << set.to_ullong() << endl;
}
void binToHex2 (string s) {
    string res = "";
    char bin[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (s.size() % 4 != 0)
        s = "0" + s;
    for (int i = 0; i < s.size(); i += 4) {
        string temp = s.substr(i, 4);
        res += bin[stoi(temp, 0, 2)];
    }
    cout << res << endl;
}
struct data {
    int i, j;
    string trace;
};
void solve () {
    string res = "";
    queue<data> q;
    q.push({0, 0, a[0][0]});
    while (!q.empty()) {
        int r = q.front().i, c = q.front().j;
        string s = q.front().trace;
        q.pop();
        if (r == n-1 && c == n-1) {
            res = max(res, s);
        }
        else if (r < n && c < n)
            if (a[r+1][c] != a[r][c+1]) {
                while (!q.empty())    q.pop();
                if (a[r+1][c] == "1") {
                    q.push({r+1, c, s + a[r+1][c]});
                }
                else if (a[r][c+1] == "1") {
                    q.push({r, c+1, s + a[r][c+1]});
                }
            }
            else {
                if (r+1 < n)
                    q.push({r+1, c, s + a[r+1][c]});
                if (c+1 < n)
                    q.push({r, c+1, s + a[r][c+1]});
            }
        
    }
    binToHex2(res);
}
void solution () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}
/*
void solve () {
    string res = "";
    queue<data> q;
    q.push({0, 0, a[0][0]});
    while (!q.empty()) {
        int r = q.front().i, c = q.front().j;
        string s = q.front().trace;
        q.pop();
        if (r == n-1 && c == n-1) {
            res = max(res, s);
        }
        if (r+1 < n)
            q.push({r+1, c, s + a[r+1][c]});
        if (c+1 < n)
            q.push({r, c+1, s + a[r][c+1]});
        
    }
    convert(res);
}
*/