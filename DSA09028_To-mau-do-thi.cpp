#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <unordered_map>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
#define pii pair<int, int>
int v, e, s;
vector<vector<int>> g;
vector<pii> p;
vector<bool> vs;
void init () {
    cin >> v >> e >> s;
    p.clear();
    g.assign(100, vector<int> (100, 0));
    vs.assign(100, false);
    unordered_map<int, int> deg;
    while (e--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1; 
        ++deg[a], ++deg[b];   
    }
    FOR (i, 1, v)   p.push_back({deg[i], i});
}
bool cmp (pii a, pii b) {
    return a.first > b.first;
}
/*
Bước 1: Tính giá trị bậc của các đỉnh trong V. Lập danh sách V’:=[v1tv2, ...,vn] là các đỉnh của đồ thị được sắp xếp theo thứ tự bậc giảm dần: d(v1) > d(v2) > ... > d(vn). 
Ban đầu tất cả các đỉnh trong V (V’) đều chưa được tô màu. Gán i := 1;
Bước 2: Tô màu i cho đỉnh đầu tiên trong danh sách V’. Duyệt lần lượt các đỉnh khác trong V’(nếu có) và chỉ tô màu i cho các đỉnh không kề đỉnh đã có màu i.
Bước 3: Kiểm tra nếu tất cả các đỉnh trong V đã được tô màu thì thuật toán kết thúc, đồ thị đã sử dụng  i màu để tô. Ngược lại, nếu vẫn còn đỉnh chưa được tô thì chuyển sang bước 4.
Bước 4: Loại khỏi danh sách V’ các đỉnh đã tô màu. Sắp xếp lại các đỉnh trong V’ theo thứ tự bậc giảm dần. Gán i := i + 1 và quay lại bước 2.
*/
void solve () {
    int cou = 0;
    sort(p.begin(), p.end(), cmp);
    for (auto u:p) {
        int i = u.second;
        if (vs[i])  continue;
        ++cou;
        vs[i] = true;
        FOR (j, 1, v)
            if (!g[i][j]) vs[j] = true;
    }
    cout << (cou <= s ? "YES\n" : "NO\n");
}
void test_case () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test_case();
    return 0;
}