#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<string> res;
void output () {
    cout << res.size() << endl;
    for (auto i:res)    cout << i << " ";
    cout << endl;
    res.clear();
}
void solution () {
    cin >> n;
    queue<string> q;
    q.push("6"), q.push("8");
    string temp = q.front();
    while (temp.size() <= n) {
        if (temp.size() == n)
            res.push_back(temp);
        q.push(temp + "6");
        q.push(temp + "8");
        q.pop(), temp = q.front();
    }
}
void test () {
    solution();
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}