/*
    You're given some points each with a color, either green or blue
    You've to draw as many circles as you can.
    You can draw a circle through a pair of points. Restrictions are:
        No two circles intersect or touch
        The colors of the endpoints have to be same.
        There must be at least 5 points inside the circle, including the endpoints.
*/

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
const int N = 105;
int dp[N][N];

inline int fun(int l, int r) {
    if(r-l < 4) return 0;
    int &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = 0;
    if(s[l] == s[r]) ret = 1 + fun(l+1, r-1);
    for(int i=l; i<r; ++i) ret = max(ret, fun(l, i)+fun(i+1, r));
    return ret;
}

int main() {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof dp);
    int res = fun(0, n-1);
    cout << res << "\n";
    return 0;
}
