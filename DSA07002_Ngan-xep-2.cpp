#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
stack<int> a;
int n;
string s;
void input () {
    cin >> s;
    if (s == "PUSH") {
        cin >> n;
        a.push(n);
    }
    else if (s == "POP" && !a.empty())    a.pop();
    else if (s == "PRINT")  
        a.empty() ? cout << "NONE\n" : cout << a.top() << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester() 
        input();
    return 0;
}