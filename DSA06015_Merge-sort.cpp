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
vector<int> a;
int n;
void init () {
    cin >> n;
    a.resize(n);
    for (auto &i : a)   cin >> i;
}
void merge (int l, int m, int r) {
    vector<int> be, af;
    int b_s = m - l + 1;
    int a_s = r - m;
    for (int i = 0; i < b_s; i++)
        be.push_back(a[i + l]);
    for (int i = 0; i < a_s; i++)
        af.push_back(a[i + m + 1]);
    int i = 0, j = 0, k = l;
    while (i < b_s && j < a_s) {
        if (be[i] <= af[j]) {
            a[k++] = be[i++];
        }
        else {
            a[k++] = af[j++];
        }
    }
    while (i < b_s) 
        a[k++] = be[i++];
    while (j < a_s)
        a[k++] = af[j++];
}
void mergeSort (int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}
void output () {
    for (auto i : a)    cout << i << " ";
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        mergeSort(0, n-1);
        output();
        a.clear();
    }
    return 0;
}
