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
string s;
void test_case1 () {
    cin >> s;
    stack<char> st;
    FOR (i, 0, s.size()-1) {
        if (s[i] != ')')
            st.push(s[i]);
        else {
            string tmp = "";
            while (st.top() != '(') {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            if (!st.empty() && st.top() == '-') {
                for (auto j:tmp) {
                    if (j == '+')       j = '-';
                    else if (j == '-')  j = '+';
                    st.push(j);
                }
            }
            else 
                for (auto j:tmp)    
                    st.push(j);
        }
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    cout << res << endl;
}
void test_case () {
    cin >> s;
    stack<char> st;
    FOR (i, 0, s.size()-1) {
        if (s[i] == '(' && i >= 1) {
            char c = s[i-1];
            if (c == '-' || c == '+')   st.push(c);
            if (c == '(' && !st.empty())    st.push(st.top());
        }
        if (!st.empty() && st.top() == '-') {
            if (s[i] == '-')    s[i] = '+';
            else if (s[i] == '+')   s[i] = '-';
        }
        if (s[i] == ')' && !st.empty()) st.pop();
    }
    FOR (i, 0, s.size()-1) {
        if (s[i] != '(' && s[i] != ')') 
            cout << s[i];
    }
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test_case();
    return 0;
}