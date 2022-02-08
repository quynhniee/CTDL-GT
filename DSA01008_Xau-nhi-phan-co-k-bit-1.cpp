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
int n, k;
void permutation (int ones, int zeroes, string res) {
    if (ones == 0) {
        for (int i = 0; i < zeroes; i++)
            res += "0";
        cout << res << endl;
        return;
    }
    else if (zeroes == 0) {
        for (int i = 0; i < ones; i++)
            res += "1";
        cout << res << endl;
        return;
    }
    else {
        permutation(ones, zeroes - 1, res + "0");
        permutation(ones - 1, zeroes, res + "1");
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        permutation(k, n - k, "");
    }
    return 0;
}

// hoặc khởi tạo xâu nhị phân bé nhất có k bit 1 rồi sinh hoán vị