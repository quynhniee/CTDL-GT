#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
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
int k;
void SwapString (int l) {
    char x = s[l];
    string res = s;
    FOR (i, l+1, s.size()-1) {
        string temp = s;
        if (x <= s[i]) {
            x = s[i];
            swap(temp[l], temp[i]);
            if (stol(temp) > stol(res)) res = temp;
        }
    }
    if (stol(res) > stol(s)) {
        s = res;
        --k;
    }
}
void backtrack (int i) {
    if (k == 0 || i == s.size()) {
        cout << s << endl;
        return;
    }
    if (i < s.size()) {
        SwapString(i);
        backtrack (i+1);
    }
}
void test () {
    cin >> k >> s;
    backtrack(0);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}