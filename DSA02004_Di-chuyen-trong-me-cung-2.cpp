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
vector<vector<int> > a, vs;
int row[] = {1, 0, 0, -1}, col[] = {0, -1, 1, 0};
string st[] = {"D", "L", "R", "U"};
int n;
bool check;
void init () {
    cin >> n;
    a.resize(n, vector<int> (n, 0));
    FOR (i, 0, n-1) 
        FOR (j, 0, n-1) 
            cin >> a[i][j];
    vs.resize(n, vector<int> (n, 1));
    check = false;
}
// note: có TH quay vòng về vị trí ban đầu VD:RL / DRLU  => lặp vô hạn
// cách 1: 0.15s
void steps (int i, int j, string s) {
    if (i == n-1 && j == n-1 && a[i][j] && vs[i][j]) {
        cout << s << " ";
        check = true;
    }
    else if (i >= 0 && i < n && j >= 0 && j < n && a[i][j] && vs[i][j]) {
        vs[i][j] = 0;  // in ra đáp án được sắp xếp
	    steps (i + 1, j, s + "D");
	    steps (i, j - 1, s + "L");
	    steps (i, j + 1, s + "R");
	    steps (i - 1, j, s + "U");
        vs[i][j] = 1;
	}
}
void test1 () {
    init ();
    if (a[0][0])
        steps(0, 0, "");
    a.clear();
    vs.clear();
    if (!check) cout << "-1";
    cout << endl;
}
// cách 2: 0.05s
void steps2 (int i, int j, string s) {
    FOR (k, 0, 3) {
        int r = i + row[k];
        int c = j + col[k];
        if (r >= 0 && r < n && c >= 0 && c < n && a[r][c] && vs[r][c]) {
            vs[r][c] = 0;
            s += st[k];
            if (r == n-1 && c == n-1){
                cout << s << " ";
                check = true;
            }
            else    steps2 (r, c, s);
            s.pop_back();
            vs[r][c] = 1;
        }
    }
}
void test2 () {
    init ();
    vs[0][0] = 0;
    if (a[0][0])
        steps2(0, 0, "");
    a.clear();
    vs.clear();
    if (!check) cout << "-1";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test1();
    return 0;
}