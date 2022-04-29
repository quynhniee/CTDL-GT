#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
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
    stack<char> st;
    for (char i:s) {
        if (i == '(' || i == '[' || i == '{')
            st.push(i);
        else if (i == ')' && st.top() == '(')   
            st.pop();
        else if (i == ']' && st.top() == '[')
            st.pop();
        else if (i == '}' && st.top() == '{')
            st.pop();
        else {
            cout << "false\n";
            return;
        }
    }
    st.empty() ? cout << "true\n" : cout << "false\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}