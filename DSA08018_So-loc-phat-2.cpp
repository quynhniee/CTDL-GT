#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<string> ans;
int n;
void output () {
    cout << ans.size() << endl;
    for (auto i:ans)    cout << i << " ";
    cout << endl;
    ans.clear();
}
void solve () {
    queue<string> q;
    q.push("6");
    q.push("8");
    string temp = q.front();
    while (temp.size() <= n) {
        ans.push_back(temp);
        q.push(temp + "6");
        q.push(temp + "8");
        q.pop();
        temp = q.front();
    }
}
void test () {
    cin >> n;
    solve();
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}