/*
    rebornplusplus ( 1605109 )
    Jun 24 2018 1236
*/

#include <bits/stdc++.h>
using namespace std;

void padd(string &p, string &q) {
    int np = p.size(), nq = q.size();
    if(np == nq) return ;
    if(np < nq) {
        string zer = "";
        while(np < nq) zer += "0", ++np;
        p = zer + p;
    }
    else {
        string zer = "";
        while(nq < np) zer += "0", ++nq;
        q = zer + q;
    }
}

void trim(string &p) {
    int i;
    for(i=0; i<p.size() and p[i] == '0'; ++i) ;
    if(i < p.size()) p = p.substr(i);
    else p = "0";
}

string addbin(string p, string q) {
    padd(p, q);
    string res(p.size() + 1, '0');
    int carry = 0;
    for(int i=p.size()-1; i>=0; --i) {
        int val = carry + p[i]-'0' + q[i]-'0';
        res[i+1] = (val % 2 ? '1' : '0');
        carry = val/2;
    }
    res[0] = (carry ? '1' : '0');
    trim(res);
    return res;
}

string subbin(string p, string q) {
    padd(p, q);
    for(int i=0; i<q.size(); ++i) q[i] = (q[i] == '0' ? '1' : '0');
    q = string(8, '1') + q;
    q = addbin(q, "1");
    string ret = addbin(p, q);
    if(ret[0] == '1') ret = ret.substr(1);
    trim(ret);
    return ret;
}

string multiply(string x, string y) {
    padd(x, y);
    if(x.size() == 1) return (x == "1" ? y : "0");
    if(y.size() == 1) return (y == "1" ? x : "0");

    int n = x.size(), pos = (n+1) / 2;
    string x1 = x.substr(0, pos), x0 = x.substr(pos);
    string y1 = y.substr(0, pos), y0 = y.substr(pos);
    string p = multiply(addbin(x0, x1), addbin(y0, y1));
    string q = multiply(x0, y0);
    string r = multiply(x1, y1);

    if(n % 2) --n;
    string zer(n, '0');
    string ta = r + zer;
    zer.resize(n/2, '0');
    string tb = subbin(subbin(p, q), r);
    tb = tb + zer;
    string tc = q;
    string res = addbin(addbin(ta, tb), tc);
    return res;
}

int main() {

    string p, q;
    cin >> p >> q;
    string res = multiply(p, q);
    cout << res << "\n";

    return 0;
}
