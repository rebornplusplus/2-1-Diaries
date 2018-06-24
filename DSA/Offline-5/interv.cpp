#include <bits/stdc++.h>
using namespace std;

struct dat {
	int l, r;
	dat() { l=-1, r=-1; }
	dat(int ll, int rr) { l=ll, r=rr; }
	bool operator<(const dat &p) const { return r > p.r;}
};

int main() {
	int n;
	cin >> n;
	priority_queue< dat > pq;
	int a[n], b[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i] >> b[i];
		pq.push(dat(a[i], b[i]));
	}

	vector< dat > res;
	int past = -1;
	while(!pq.empty()) {
		while(!pq.empty() and pq.top().l < past) pq.pop();
		if(!pq.empty()) {
			dat d = pq.top(); pq.pop();
			res.push_back(d);
			past = d.r;
		}
	}
	cout << res.size() << "\n";
	for(auto x : res) cout << x.l << " " << x.r << "\n";
	return 0;
}

/*

11
8 12
0 6
5 7
3 8
12 14
1 4
3 5
5 9
6 10
7 11
2 13

*/