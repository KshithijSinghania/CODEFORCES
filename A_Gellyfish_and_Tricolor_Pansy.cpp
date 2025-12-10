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
    ll mini=min(a[0],min(a[1],min(a[2],a[3])));
    ll count=0;
    loop(i,n){
        if(a[i]==mini){
            count++;
        }
    }
    if(count==1){
        loop(i,n){
            if(a[i]==mini){
                if(i==0 || i==2){
                    cout<<"Flower"<<endl;
                    return;
                }
                else{
                    cout<<"Gellyfish"<<endl;
                    return;
                }
            }
        }
    }
    if(count==2){
        bool same=false;
        if(a[0]==a[2] && a[0]==mini){
            cout<<"Flower"<<endl;
            return;
        }
        else if(a[1]==a[3] && a[1]==mini){
            cout<<"Gellyfish"<<endl;
            return;
        }
        else{
            cout<<"Gellyfish"<<endl;
            return;
        }
    }
    else{
        cout<<"Gellyfish"<<endl;
        return;
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ull t;
  cin>>t;
  while(t>0){
    t--;
    ll n=4;
    vector <ll> a;
    inp(a,n);
    solve(a,n);

  }
}