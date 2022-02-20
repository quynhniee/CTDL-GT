#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k, cou;
string Astring;
set <string> ans;
void insertString (string s) {
    if (s[0] != 'A')    {
        ans.insert(Astring + s);
        ++cou;
    }
    FOR (i, 1, s.size() - 1) {
        string s1 = s;
        if (s[i-1] != 'A' && s[i] != 'A') {
            s1.insert(i, Astring);
            ans.insert(s1);
            ++cou;
        }
    }
    if (s.back() != 'A')    {
        ans.insert(s + Astring);
        ++cou;
    }
}
// sinh các xâu AB dài n-k và không chứa k chữ A liên tiếp
void backtracking (int i, string s, int Acou) {
    if (i == n-k) 
        insertString(s);
    else {
        if (Acou < k)
            backtracking(i+1, s + "A", Acou+1);
        backtracking(i+1, s + "B", Acou);
    }
}
void test () {
    cou = 0;
    cin >> n >> k;
    if (k > n)  return;
    FOR (i, 1, k)   Astring += 'A';
    backtracking(0, "", 0);
    cout << cou << endl;
    for (auto i:ans)    cout << i << endl;
    ans.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}