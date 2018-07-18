#include <bits/stdc++.h>
using namespace std;

const int N = 1000000+7;
int cnt[N+N];

void kounting_sort(int *a, int n) {
	memset(cnt, 0, sizeof cnt);
	for(int i=0; i<n; ++i) ++cnt[a[i]+N];
	for(int i=0, j=0; i<N+N; ++i) {
		while(cnt[i]--) a[j++] = i-N;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; ++i) scanf("%d", a+i);
	
	kounting_sort(a, n);
	for(int i=0; i<n; ++i) printf("%d ", a[i]);
	putchar('\n');
	
	return 0;
}
