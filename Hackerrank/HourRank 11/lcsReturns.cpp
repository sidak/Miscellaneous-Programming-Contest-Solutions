#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define pb push_back
using namespace std;


int arr[5001][5001], rarr[5001][5001];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<char, vector<int>> mp;
    string a,b;
    cin>>a>>b;
    int sz_a = a.size();
    int sz_b = b.size();
    for(int i=0; i<sz_b; i++){
        if(mp.find(b[i])==mp.end()){
            vector<int> x;
            x.pb(i);
            mp[b[i]] = x;
        }
        else{
            mp[b[i]].pb(i);
        }
    }
    
    
    
    for(int i=0; i<a.size()+1; i++){
		for(int j=0; j<b.size()+1; j++){
			arr[i][j]=0;
            rarr[i][j]=0;
		}
	}
    
    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a[i-1]==b[j-1]){
                arr[i][j] = 1+ arr[i-1][j-1];
            }
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }
    
    int lcs =  arr[sz_a][sz_b];
    
    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a[a.size() - i]==b[b.size()-j]){
                rarr[i][j] = 1+ rarr[i-1][j-1];
            }
            else rarr[i][j] = max(rarr[i-1][j], rarr[i][j-1]);
        }
    }
    int ans = 0;
    for(int i=0; i<=a.size(); i++){
        for(auto it = mp.begin(); it!=mp.end(); it++){
            vector<int> idx = (*it).second;
            for(int j =0; j<idx.size(); j++){
                if((arr[i][idx[j]] + rarr[sz_a-i][sz_b-idx[j]-1])==lcs){
                    ans++;
                    break;
                }
            }
        }    
    }
    
    cout<<ans<<endl;
    return 0;
}
