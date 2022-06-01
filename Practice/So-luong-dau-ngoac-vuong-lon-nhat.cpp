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
    FORD (i, s.size()-1, 0) {
        if (!st.empty() && ((s[i] == '(' && s[st.top()] == ')') || (s[i] == '[' && s[st.top()] == ']')))
            st.pop();
        else    st.push(i);
    }
    vector<int> pos(1, -1);
    while (!st.empty()) {
        pos.push_back(st.top());
        st.pop();
    }
    pos.push_back(s.size());
    FOR (i, 1, pos.size()-1) {
        cou = 0;
        FOR (j, pos[i-1]+1, pos[i]-1)
            if (s[j] == '[')   {
                ++cou;
                res = max (res, cou);
            }
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}