#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define reverse1(v) reverse(v.begin(), v.end())
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

void solve(vector <ll> a,ll n,ll m){
    map<ll,stack<ll>> class_map;
    for(ll i=0;i<m;i++){
        class_map[a[i]/100].push(i);
    }
    vector<vector<ll>> ans(n, vector<ll>(6));
    vector <ll> floors;
    for(auto it:class_map){
        floors.push_back(it.first);
    }
    sort1(floors);
    ll fsize = floors.size();
    ll temp=n;
    ll toggle=0;
    ll mini=0;
    ll maxi=fsize-1;
    ll i=0;
    while(temp>0){
        if(toggle==0){
            ans[0][i]=class_map[floors[mini]].top();
            class_map[floors[mini]].pop();
            if(class_map[floors[mini]].empty()){
                mini++;
            }
            toggle=1;
        }
        else{
            ans[0][i]=class_map[floors[maxi]].top();
            class_map[floors[maxi]].pop();
            if(class_map[floors[maxi]].empty()){
                maxi--;
            }
            toggle=0;
        }
        i++;
        temp--;
    }
    if(n%2==0){
        vector <ll> temp;
        for(ll j=0;j<n;j++){
            temp.push_back(ans[0][j]);
        }
        for(ll j=1;j<6;j++){
            reverse(temp.begin(), temp.end());
            for(ll k=0;k<n;k++){
                ans[k][j]=temp[k];
            }
        }
    }
    else{
         vector <ll> temp;
        for(ll j=0;j<n;j++){
            temp.push_back(ans[0][j]);
        }
        for(ll j=1;j<6;j++){
            reverse(temp.begin(), temp.end());
            for(ll k=0;k<n;k++){
                ans[k][j]=temp[k];
            }
        }
        ll left=ans[0][n-1];
    }
    for(ll j=0;j<n;j++){
        for(ll k=0;k<6;k++){
            cout<<ans[j][k]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
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
    ll m;
    cin>>m;
    vector <ll> a;
    inp(a,m);
    solve(a,n,m);
  }
}