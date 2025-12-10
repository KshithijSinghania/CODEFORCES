#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define reverse(v) reverse(v.begin(), v.end())
#define sort1(v) sort(v.begin(), v.end())
#define ld long double
#define ull unsigned long long int
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i,n) for(ll i=1;i<=n;i++)
#define loopr(i,n) for(ll i=n-1;i>=0;i--)
#define loopr1(i,n) for(ll i=n;i>0;i--)
using namespace std;

bool comp(pair <ll,ll> p1,pair <ll,ll> p2){
  return p1.first>p2.first;
}

void inp(vector <ll> &a,ll n){
  loop(i,n){
    ll d;
    cin>>d;
    a.push_back(d);
  }
}

//-------------------------------------

void solve(vector <ll> a,ll n){
  vector <ll> ans(n);
  loop(i,n){
    if(mB[i]>mA[i]){
        ans[i]=((1LL<<mB[i])%mod + (1LL<<a[i-pB[mB[i]]])%mod)%mod;
    }
    else if(mA[i]>mB[i]){
        ans[i]=((1LL<<mA[i])%mod + (1LL<<b[i-pA[mA[i]]])%mod)%mod;
    }
    else{
        ll a1=((1LL<<mA[i])%mod + (1LL<<b[i-pA[mA[i]]])%mod)%mod;
        ll a2=((1LL<<mB[i])%mod + (1LL<<a[i-pB[mB[i]]])%mod)%mod;
        ans[i]=max(a1, a2);
    }
  }
  loop(i,n){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ull t;
  cin>>t;
  while(t>0){
    t--;
    // ll n;
    // cin>>n;
    // vector <ll> a;
    // inp(a,n);
    //solve(a,n);
  }
}