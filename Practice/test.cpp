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
int n;
vector<string> s, num;
string x, y;
void output (vector<string> a) {
    for (auto i:a)  cout << i << endl;
}
void numString (int i) {
    FOR (j, 1, n) {
        x += (char) (j + '0');
        if (i == n)
            num.push_back(x);
        else numString(i+1);
        x.pop_back();
    }
}
void charString () {
    for (char i = 'A'; i <= 'A' + n - 1; i++)
        y += i;
    do
        s.push_back(y);
    while (next_permutation(y.begin(), y.end()));
}
void solution () {
    cin >> n;
    x = y = "";
    numString(1);
    charString();
    for (auto i:s)
        for (auto j:num)
            cout << i + j << endl;
    s.clear(); num.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}