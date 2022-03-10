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

int val, n;
void request (queue<int> &a) {
    int k;
    cin >> k;
    if (k == 1) cout << a.size() << endl;
    else if (k == 2) 
        a.empty() ? cout << "YES\n" : cout << "NO\n";
    else if (k == 3) {
        cin >> val;
        a.push(val);
    }
    else if (k == 4 && !a.empty())
        a.pop();
    else if (k == 5)
        !a.empty() ? cout << a.front() << endl : cout << "-1\n";
    else if (k == 6)
        !a.empty() ? cout << a.back() << endl : cout << "-1\n";
}   
void test () {
    queue<int> a;
    cin >> n;
    while (n--) 
        request(a);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}