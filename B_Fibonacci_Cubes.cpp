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

vector <ll> precompute(ll n){
    vector <ll> fib(n);
    fib[0] = 1;
    fib[1] = 2;
    for(ll i = 2; i < n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]);
    }
    return fib;
}

void solve(vector <vector <ll>> a,ll n){
    vector <ll> fib = precompute(n);
    
    string ans = "";
    ll m=a.size();
    loop(i,m){
        vector <ll> check(n,-1);
        ll w=a[i][0];
        ll l=a[i][1];
        ll h=a[i][2];
        queue <vector <ll>> q;
        q.push({w, l, h});
        ll count=0;
        bool found = false;
        while(!q.empty()){
            vector <ll> curr = q.front();
            q.pop();
            ll wleft=curr[0];
            ll lleft=curr[1];
            ll hleft=curr[2];
            //cout<<wleft<<" "<<lleft<<" "<<hleft<<endl;
            ll start=0;
            ll end=fib.size()-1;
            ll maxi=-1;
            while(start <= end) {
                ll mid = start + (end - start) / 2;
                if(fib[mid]<= wleft && fib[mid] <= lleft && fib[mid] <= hleft) {
                    if(check[mid] == -1)
                    maxi = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            //cout<<maxi<<endl;
            if(maxi!=-1){
                count++;
                check[maxi] = 1;
                q.push({wleft - fib[maxi], lleft - fib[maxi], hleft});
                q.push({fib[maxi], fib[maxi], hleft-fib[maxi]});
                q.push({fib[maxi], lleft - fib[maxi], hleft});
                q.push({wleft - fib[maxi], fib[maxi], hleft});
            }
            else {
                continue;
            }
            //cout<<count<<endl;
            if(count == n) {
                found = true;
                break;
            }
        }
        if(found) {
            ans += "1";
        } else {
            ans += "0";
        }
    }
    cout<< ans << "\n";
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
    vector <vector <ll>> a;
    loop(i,m){
        ll w,l,h;
        cin>>w>>l>>h;
        vector <ll> v;
        v.push_back(w);
        v.push_back(l);
        v.push_back(h);
        a.push_back(v);
    }
    solve(a,n);
    // vector <ll> a;
    // inp(a,n);
    //solve(a,n);
  }
}