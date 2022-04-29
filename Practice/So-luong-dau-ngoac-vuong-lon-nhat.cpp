#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
void solution () {
    cin >> s;
    stack<int> st;
    int res = 0, cou = 0;
    FOR (i, 0, s.size()-1) {
        if (s[i] == '(' || s[i] == '[')
            st.push(i);
        else if (s[i] == ')' && !st.empty() && s[st.top()] == '(')
            st.pop();
        else if (s[i] == ']' && !st.empty() && s[st.top()] == '[') {
            ++cou;
            res = max (res, cou);
            st.pop();
        }
        else  {
            cou = 0;
            while (!st.empty()) st.pop();
        }  
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    solution();
    return 0;
}