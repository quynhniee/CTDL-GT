#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <stack>
#include <algorithm>
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
    scanf("\n");
    getline(cin, s);
    stack<char> st;
    for (auto i:s) {
        if (i == '(' || i == '[')
            st.push(i);
        else if (i == ')')
            (!st.empty() && st.top() == '(') ?    st.pop() : st.push (i);
        else if (i == ']')
            (!st.empty() && st.top() == '[') ?    st.pop() : st.push (i);
    }
    st.empty() ? cout << "YES\n" : cout << "NO\n";
}
int main () {
    tester()    solution();
    return 0;
}