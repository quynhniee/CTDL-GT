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
queue<int> a;
string s;
int n;
void request () {
    cin >> s;
    if (s == "PUSH") {
        cin >> n;
        a.push(n);
    }
    else if (s == "PRINTFRONT") 
        a.empty() ? cout << "NONE\n" : cout << a.front() << endl;
    else if (s == "POP" && !a.empty())
        a.pop();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        request();
    return 0;
}