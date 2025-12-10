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
  ll tg=a[0];
  map<ll,ll> m;
  loop(i,n){
    m[a[i]]++;
  }
  loop1(i,n-1){
    tg=__gcd(tg,a[i]);
  }
  if(m.find(tg)!=m.end()){
    cout<<n-m[tg]<<"\n";
    return;
  }
  set<ll> s(a.begin(), a.end());
  vector<ll> v(s.begin(), s.end());
  sort1(v);
  int maxi=v.back();
  vector<ll> dp(maxi+1, -1);
  queue <ll> q;
  for(auto it:v){
    dp[it]=0;
    q.push(it);
  }
  while(!q.empty()){
    ll x=q.front();
    q.pop();
    if(x==tg){
      break;
    }
    for(auto it:v){
      ll y=__gcd(x,it);
      if(dp[y]==-1){
        dp[y]=dp[x]+1;
        q.push(y);
      }
    }
  }
  cout<<dp[tg]+n-1<<"\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ull t;
  cin>>t;
  while(t>0){
    t--;
    ll n;
    cin>>n;
    vector <ll> a;
    inp(a,n);
    solve(a,n);
  }
}