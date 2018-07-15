// MAX Heap Implementation
// Rafid, 1605109
// July 15 2018 0635

#include <bits/stdc++.h>
using namespace std;

class max_heap {
	#define PARENT(i) (i>>1)
	#define LEFT(i) (i<<1)
	#define RIGHT(i) ((i<<1) | 1)

	static const int INF = 2000000000;
	static const int initial_sz = 2;
	int sz, len, *a;

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

	void increase_key(int i, int key) {
		if(key < a[i-1]) return ;
		a[i-1] = key;
		while(i > 1 and a[PARENT(i)-1] < a[i-1]) {
			swap(a[i-1], a[PARENT(i)-1]);
			i = PARENT(i);
		}
	}

	void balance() {
		if(sz == 0) {
			a = (int*) malloc(initial_sz * sizeof(int));
			len = initial_sz;
		}
		else if(sz == len) {
			int nlen = len<<1;
			int *temp = (int*) malloc(nlen * sizeof(int));
			for(int i=0; i<sz; ++i) temp[i] = a[i];
			free(a);
			a = temp;
			len = nlen;
		}
		else if(sz+sz < len) {
			int nlen = len>>1;
			if(nlen < initial_sz) nlen = initial_sz;
			int *temp = (int*) malloc(nlen * sizeof(int));
			for(int i=0; i<sz; ++i) temp[i] = a[i];
			free(a);
			a = temp;
			len = nlen;
		}
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
			balance();
			a[sz] = p.a[sz];
			++sz;
		}
	}

	void push(int key) {
		balance();
		++sz;
		a[sz-1] = -INF;
		increase_key(sz, key);
	}

	int top() {
		if(sz > 0) return a[0];
		cerr << "Ooopsie! Heap is empty!" << "\n";
		return -INF;
	}

	int pop() {
		if(sz <= 0) {
			cerr << "Ooopsie! Heap is empty!" << "\n";
			return -INF;
		}
		int ret = a[0];
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

	void delete_max() {
		pop();
	}

	int replace(int key) {
		if(sz <= 0) {
			cerr << "Ooopsie! Heap is empty!" << "\n";
			return -INF;
		}
		int ret = a[0];
		a[0] = key;
		heapify(1);
		return ret;
	}

	friend max_heap merge(max_heap &p, max_heap &q) {
		max_heap ret;
		for(int i=0; i<p.sz; ++i) {
			ret.balance();
			ret.a[ret.sz++] = p.a[i];
		}
		for(int i=0; i<q.sz; ++i) {
			ret.balance();
			ret.a[ret.sz++] = q.a[i];
		}
		ret.build_max_heap();
		return ret;
	}

	friend max_heap meld(max_heap &p, max_heap &q) {
		max_heap ret = merge(p, q);
		p.~max_heap();
		q.~max_heap();
		return ret;
	}

	max_heap operator=(max_heap p) {
		sz = 0, len = 0;
		balance();
		while(sz < p.sz) {
			balance();
			a[sz] = p.a[sz];
			++sz;
		}
		return *this;
	}

	~max_heap() {
		sz = 0, len = 0;
		free(a);
	}
};

void print_chart() {
	cout << "\n";
	cout << "B A S I C  C H A R T  T O  O P E R A T E" << "\n";
	cout << "create    -    Creates a new empty heap\n";
	cout << "push x    -    Inserts x\n";
	cout << "pop       -    Extracts the max element\n";
	cout << "top       -    Max element without extraction\n";
	cout << "delete    -    Deletes the max element\n";
	cout << "replace x -    Pops root and insert x\n";
	cout << "size      -    Heap size so far\n";
	cout << "empty     -    Checks whether heap is empty\n";
	cout << "merge     -    Merges last two created heaps\n";
	cout << "meld      -    Melds last two created heaps\n";
	cout << "chart     -    Shows the command chart\n";
	cout << "bye       -    Quits the play\n";
	cout << "\n";
}

int main() {
	max_heap pq1, pq2;
	string s;
	print_chart();
	int cnt = 0;

	while(cin >> s and s != "bye") {
		if(s == "create") {
			++cnt;
			if(cnt % 2 == 1) pq1 = max_heap();
			else pq2 = max_heap();
			continue;
		}
		max_heap &pq = (cnt % 2) ? pq1 : pq2;
		if(s == "push") {
			int key;
			cin >> key;
			pq.push(key);
		}
		else if(s == "pop") {
			cout << pq.pop() << "\n";
		}
		else if(s == "top") {
			cout << pq.top() << "\n";
		}
		else if(s == "delete") {
			pq.delete_max();
		}
		else if(s == "replace") {
			int key;
			cin >> key;
			cout << pq.replace(key) << "\n";
		}
		else if(s == "size") {
			cout << pq.size() << "\n";
		}
		else if(s == "empty") {
			cout << (pq.empty() ? "Yes" : "Nou") << "\n";
		}
		else if(s == "merge") {
			max_heap temp = merge(pq1, pq2);
			pq = temp;
		}
		else if(s == "meld") {
			max_heap temp = meld(pq1, pq2);
			pq = temp;
		}
		else if(s == "chart") {
			print_chart();
		}
		else {
			cout << "Bad commander.\n";
		}
	}

	return 0;
}
