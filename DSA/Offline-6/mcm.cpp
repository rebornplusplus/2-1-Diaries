#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100 + 5;
int p[N];
ll dp[N][N];

// returns the answer for matrices of indices l-r
inline ll mcm(int l, int r) {
    if(l == r) return 0;
    ll &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = LLONG_MAX;
    for(int i=l; i<r; ++i) {
        ll temp = mcm(l, i) + mcm(i+1, r) + p[l] * p[i+1] * p[r+1];
        ret = min(ret, temp);
    }
    return ret;
}

int main() {
    int n = 0;
    while(cin >> p[n]) ++n;
    --n;	// n is the number of matrices

    memset(dp, -1, sizeof dp);
    ll res = mcm(0, n-1);
    cout << res << "\n";

    return 0;
}

// 40 20 30 10 30
// 10 20 30
// 10 20 30 40 30
