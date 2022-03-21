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
void test () {
    scanf("\n");
    getline(cin, s);
    stack<int> st;
    int distance = 1e3;
    FOR (i, 0, s.size()-1) {
        if (s[i] == '(') 
            st.push(i);
        else if (s[i] == ')') {
            int temp = i - st.top();
            if (temp == distance + 2 || temp <= 2) {
                cout << "Yes\n";
                return;
            }
            st.pop();
            distance = temp;
        }
    }
    cout << "No\n";
}
int main () {
    tester()    test();
    return 0;
}