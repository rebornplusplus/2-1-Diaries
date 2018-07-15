/*
	The problem asks you to sort a given
	array by HeapSort using your own Max
	or Min Heap Class
*/

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
		else if(sz+sz <= len) {
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
			a[sz] = p.a[sz];
			++sz;
			balance();
		}
	}

	void HeapSort(int arr[], int n) {
		sz = 0, len = 0;
		balance();
		for(int i=0; i<n; ++i) {
			a[sz++] = arr[i];
			balance();
		}
		build_max_heap();
		for(int i=sz; i>=2; --i) {
			arr[i-1] = a[0];
			swap(a[i-1], a[0]);
			sz--;
			heapify(1);
		}
		arr[0] = a[0];
	}

	void push(int key) {
		++sz;
		a[sz-1] = -INF;
		increase_key(sz, key);
		balance();
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
			ret.a[ret.sz++] = p.a[i];
			ret.balance();
		}
		for(int i=0; i<q.sz; ++i) {
			ret.a[ret.sz++] = q.a[i];
			ret.balance();
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

// The obvious idea :v
void heapsort(int arr[], int n) {
	max_heap pq;
	for(int i=0; i<n; ++i) pq.push(arr[i]);
	for(int i=n-1; i>=0; --i) arr[i] = pq.pop();
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i];

	max_heap pq;
	pq.HeapSort(a, n);
	for(int i=0; i<n; ++i) cout << a[i] << " ";
	cout << "\n";

	return 0;
}
