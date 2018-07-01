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

int main() {
    cin >> s;
    n = s.size();
    for(int l=1; l<=n; ++l) {
        for(int i=0; i+l-1<n; ++i) {
            int j = i+l-1;
            dp[i][j] = 0;
            if(l < 5) continue;
            if(s[i] == s[j]) dp[i][j] = 1 + dp[i+1][j-1];
            for(int k=i; k<j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";

    return 0;
}
