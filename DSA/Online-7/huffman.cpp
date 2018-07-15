/*
	The problem asks you to find Huffman Coding
	for given characters and their frequencies
	using your own Max/Min Heap Class
*/

#include <bits/stdc++.h>
using namespace std;

struct dat {
	int f;
	char c;
	int lc, rc;

	dat() {f=0, c=0, lc=-1, rc=-1;}
	dat(int ff, char cc, int ll=-1, int rr=-1) { f=ff, c=cc, lc=ll, rc=rr; }
	bool operator < (const dat &p) const {
		return f < p.f;
	}
	bool operator == (const dat &p) const {
		return f == p.f;
	}
	bool operator > (const dat &p) const {
		return f > p.f;
	}
};

class max_heap {
	#define PARENT(i) (i>>1)
	#define LEFT(i) (i<<1)
	#define RIGHT(i) ((i<<1) | 1)

	static const int INF = 2000000000;
	static const int initial_sz = 2;
	int sz, len;
	dat *a;

	void heapify(int i) {
		int l = LEFT(i);
		int r = RIGHT(i);
		int largest;
		if(l <= sz and a[i-1] < a[l-1]) largest = l;
		else largest = i;
		if(r <= sz and a[largest-1] < a[r-1]) largest = r;
		if(largest != i) {
			swap(a[i-1], a[largest-1]);
			heapify(largest);
		}
	}

	void build_max_heap() {
		for(int i=sz/2; i>=1; --i) {
			heapify(i);
		}
	}

	void increase_key(int i, dat key) {
		if(key < a[i-1]) return ;
		a[i-1] = key;
		while(i > 1 and a[PARENT(i)-1] < a[i-1]) {
			swap(a[i-1], a[PARENT(i)-1]);
			i = PARENT(i);
		}
	}

	void balance() {
		if(sz == 0) {
			a = (dat*) malloc(initial_sz * sizeof(dat));
			len = initial_sz;
		}
		else if(sz == len) {
			int nlen = len<<1;
			dat *temp = (dat*) malloc(nlen * sizeof(dat));
			for(int i=0; i<sz; ++i) temp[i] = a[i];
			free(a);
			a = temp;
			len = nlen;
		}
		else if(sz+sz <= len) {
			int nlen = len>>1;
			if(nlen < initial_sz) nlen = initial_sz;
			dat *temp = (dat*) malloc(nlen * sizeof(dat));
			for(int i=0; i<sz; ++i) temp[i] = a[i];
			free(a);
			a = temp;
			len = nlen;
		}
	}

	void print() {
		cout << " A ( " << sz << " " << len << " ) : ";
		for(int i=0; i<sz; ++i) {
			cout << a[i].f << " " << a[i].c << "; ";
		} cout << "\n";
	}

public:
	max_heap() {
		sz = 0, len = 0;
		balance();
	}

	max_heap(const max_heap &p) {
		sz = 0, len = 0;
		balance();
		while(sz < p.sz) {
			a[sz] = p.a[sz];
			++sz;
			balance();
		}
	}

	void push(dat key) {
		balance();
		++sz;
		a[sz-1] = dat(-INF, 0);
		increase_key(sz, key);
	}

	dat top() {
		if(sz > 0) return a[0];
		cerr << "Ooopsie! Heap is empty!" << "\n";
		return dat(-INF, 0);
	}

	dat pop() {
		if(sz <= 0) {
			cerr << "Ooopsie! Heap is empty!" << "\n";
			return dat(-INF, 0);
		}
		dat ret = a[0];
		a[0] = a[sz-1];
		--sz;
		heapify(1);
		balance();
		return ret;
	}

	bool empty() {
		return sz == 0;
	}

	int size() {
		return sz;
	}

	max_heap operator=(max_heap p) {
		sz = 0, len = 0;
		balance();
		while(sz < p.sz) {
			a[sz] = p.a[sz];
			++sz;
			balance();
		}
		return *this;
	}

	~max_heap() {
		sz = 0, len = 0;
		free(a);
	}
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
	int f[n];
	char c[n];
	for(int i=0; i<n; ++i) cin >> c[i] >> f[i];

	max_heap pq;
	for(int i=0; i<n; ++i) pq.push(dat(-f[i], c[i]));
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
