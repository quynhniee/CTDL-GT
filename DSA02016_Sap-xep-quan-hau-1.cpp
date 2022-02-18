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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n, cou;
vector<int> col, le, ri;
// đường chéo nghiêng về bên trái => i - j + n
// đường chéo nghiêng về bên phải => i + j - 1
void init () {
    cou = 0;
    cin >> n;
    col.resize(n+1, 1);
    FOR (i, 0, 2*n - 1) {
        le.push_back(1);
        ri.push_back(1);
    }
}
// hàng thứ i => check cột và các hàng chéo xem có trùng queens khác không
void placingQueens (int i) {  
    FOR (j, 1, n) {
        if (col[j] && le[i-j+n] && ri[j+i-1]) {
            col[j] = 0;
            le[i-j+n] = 0;
            ri[i+j-1] = 0;
            if (i == n) ++cou;
            else placingQueens(i+1);
            col[j] = 1;
            le[i-j+n] = 1;
            ri[i+j-1] = 1;
        }
    }
}
void test () {
    init ();
    placingQueens(1);
    cout << cou << endl;
    le.clear();
    ri.clear();
    col.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}