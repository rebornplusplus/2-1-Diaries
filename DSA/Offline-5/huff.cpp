#include <bits/stdc++.h>
using namespace std;

struct dat {
	int f;
	char c;
	int lc, rc;
	dat() { f=0, c=0, lc=-1, rc=-1; }
	dat(int ff, char cc, int ll=-1, int rr=-1) { f=ff, c=cc, lc=ll, rc=rr; }
	bool operator < (const dat &p) const { return f > p.f; }
};

vector< dat > v;
vector< pair< char, string > > res;

void dfs(dat d, string s="") {
	if(d.lc == -1 and d.rc == -1) res.push_back(make_pair(d.c, s));
	if(d.lc > -1) dfs(v[d.lc], s+"0");
	if(d.rc > -1) dfs(v[d.rc], s+"1");
}

int main() {
	int n;
	cin >> n;
	priority_queue< dat > pq;
	while(n--) {
		char c;
		int f;
		cin >> c >> f;
		pq.push(dat(f, c));
	}

	v.clear();
	while(pq.size() > 1) {
		dat a = pq.top(); pq.pop();
		dat b = pq.top(); pq.pop();
		v.push_back(a);
		v.push_back(b);
		dat temp(a.f+b.f, 0, v.size()-2, v.size()-1);
		pq.push(temp);
	}
	v.push_back(pq.top()); pq.pop();
	res.clear();
	dfs(v.back());
	for(auto x : res) cout << x.first << " " << x.second << "\n";

	return 0;
}

/*

6
a 45
b 13
c 12
d 16
e 9
f 5

*/