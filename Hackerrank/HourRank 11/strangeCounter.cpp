#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ll x;
    cin>>x;
    double y = (x/3.0) + 1;
    double z = ceil(log2(y));
    ll n = ll(z);
    ll p = ll(pow(2, n-1));
    ll lt = 3*(p-1);
    ll diff = 3*p;
    ll ans = diff - (x-lt) +1 ;
    cout<<ans<<endl;
    
}
