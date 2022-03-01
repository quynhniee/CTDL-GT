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
void backtrack (int i, char a, char b, char c) {
    if (i==1) {
        cout << a << " -> " << c << endl;
        return;
    }
    backtrack(i-1, a, c, b);// lấy cột C làm cọc trung gian. Chuyển n-1 chiếc đĩa sang cột B.
    backtrack(1, a, b, c);  // Ta chuyển chiếc đĩa lớn nhất sang cột C
    backtrack(i-1, b, a, c);// Lấy cột A làm cột trung gian chuyển n-1 chiếc đĩa từ cột B sang cột C
}
void test () {
    cin >> n;
    backtrack(n, 'A', 'B', 'C');
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}