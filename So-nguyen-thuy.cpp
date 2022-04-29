#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<string> res;
void solution () {
    queue <string> q;
    q.push("4");
    q.push("5");
    string temp = q.front();
    while (res.size() <= 1e4) {
        res.push_back(temp);
        q.push(temp + "4");
        q.push(temp + "5");
        q.pop();
        temp = q.front();
    }
}
void output (string s) {
    string tmp = s;
    reverse(s.begin(), s.end());
    cout << tmp + s << " ";
}
void test () {
    cin >> n;
    FOR (i, 0, n-1) 
        output(res[i]);
    cout << endl;

}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    tester()    test();
    return 0;
}