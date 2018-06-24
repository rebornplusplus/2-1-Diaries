#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v, temp;
int n;

ll inversion_count(int l, int r) {
	if(l >= r) return 0;

	int mid = (l+r) / 2;
	ll ret = inversion_count(l, mid) + inversion_count(mid+1, r);

	int i=l, j=mid+1, k=0;
	while(i<=mid and j<=r) {
		if(v[j] < v[i]) {
			temp[k++] = v[j++];
			ret += (mid-i+1);
		}
		else temp[k++] = v[i++];
	}
	while(i <= mid) temp[k++] = v[i++];
	while(j <= r) temp[k++] = v[j++];
	for(i=l; i<=r; ++i) v[i] = temp[i-l];
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for(int i=0; i<n; ++i) cin >> v[i];

	temp.resize(n);
	ll res = inversion_count(0, n-1);
	cout << res << "\n";

	return 0;
}