#include <bits/stdc++.h>
using namespace std;

string lcs(string &p, string &q) {
    int m=p.size(), n=q.size();
    int dp[m+1][n+1];
    for(int i=0; i<m; ++i) dp[i][n] = 0;
    for(int i=0; i<n; ++i) dp[m][i] = 0;
    for(int i=m-1; i>=0; --i) {
        for(int j=n-1; j>=0; --j) {
            if(p[i] == q[j]) dp[i][j] = 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int i=0, j=0;
    string ret = "";
    while(i < m and j < n) {
        if(dp[i+1][j] == dp[i][j]) ++i;
        else if(dp[i][j+1] == dp[i][j]) ++j;
        else ret += p[i], ++i, ++j;
    }
    return ret;
}

int main() {
    string p, q;
    cin >> p >> q;
    string res = lcs(p, q);
    cout << res.size() << " " << res << "\n";
    return 0;
}

// AGGTAB GXTXAYB
// ABCDGH AEDFHR
