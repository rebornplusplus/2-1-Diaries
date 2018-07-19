#include <bits/stdc++.h>
using namespace std;

const double X2_MAX = 100000;	// X2_MAX = 2 * max(abs(a[i])) + 1; double the maximum absolute val plus one.
const int NOB = 5;	// Number of Buckets
vector< double > buket[NOB];	// The Buckets

void buket_sort(double *a, int n) {
	for(int i=0; i<NOB; ++i) buket[i].clear();
	for(int i=0; i<n; ++i) {
		a[i] = (a[i]/X2_MAX) + 0.5;
		int which = (a[i] * NOB);
		buket[which].push_back(a[i]);
	}
	for(int i=0; i<NOB; ++i) sort(buket[i].begin(), buket[i].end());
	for(int i=0, j=0; i<NOB; ++i) {
		for(int k=0; k<(int) buket[i].size(); ++k) {
			a[j++] = (buket[i][k] - 0.5) * X2_MAX;
		}
	}
}

int main() {
	int n;
	cin >> n;
	double a[n];
	for(int i=0; i<n; ++i) cin >> a[i];

	buket_sort(a, n);
	for(int i=0; i<n; ++i) cout << a[i] << " ";
	cout << "\n";

	return 0;
}
