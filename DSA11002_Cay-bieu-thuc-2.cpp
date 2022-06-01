#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
void solution () {
    int n;
    cin >> n;
    vector<string> s (n, "");
    for (int i = n-1; i >= 0; i--) cin >> s[i]; 
    queue<int> q;
    for (auto i:s) {
        if (isdigit(i[0]))  
            q.push(stoi(i));
        else {
            int n1 = q.front(); q.pop();
            int n2 = q.front(); q.pop();
            if (i == "+")   q.push(n2 + n1);
            else if (i == "-")  q.push(n2 - n1);
            else if (i == "*")  q.push(n2 * n1);
            else if (i == "/")  q.push(n2 / n1);
        }
    }
    cout << q.front() << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}