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
    unordered_map<ll, vector<pair<ll,ll>>> segment_map;
    for(ll i=0;i<n;){
        ll j=i;
        while(j<n && a[j]==a[i]) j++;
        segment_map[a[i]].push_back({i, j-1});
        i=j;
    }
    set <ll> unique_values;
    loop(i,n){
        unique_values.insert(a[i]);
    }
    map <ll,ll> max_segment_length;
    for(auto it:unique_values){
        vector <pair<ll,ll>> segments = segment_map[it];
        ll maxi=LLONG_MIN;
        for(auto segment:segments){
            ll length = segment.second - segment.first + 1;
            maxi = max(maxi, length);
        }
        max_segment_length[it] = maxi;
    }
    ll min_cost=LLONG_MAX;
    for(auto it:max_segment_length){
        min_cost = min(min_cost, it.first*(n-it.second));
    }
    cout<<min_cost<<"\n";
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