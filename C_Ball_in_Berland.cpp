#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define reverse(v) reverse(v.begin(), v.end())
#define sort1(v) sort(v.begin(), v.end())
#define ld long double
#define ull unsigned long long int
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, n) for (ll i = 1; i <= n; i++)
#define loopr(i, n) for (ll i = n - 1; i >= 0; i--)
#define loopr1(i, n) for (ll i = n; i > 0; i--)
using namespace std;

bool comp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.first > p2.first;
}

void inp(vector<ll> &a, ll n)
{
    loop(i, n)
    {
        ll d;
        cin >> d;
        a.push_back(d);
    }
}

//-------------------------------------

void solve(vector<ll> a, vector<ll> b, ll n)
{
    ll count = 0;
    ll ans = 0;
    unordered_map<ll, ll> mb;
    unordered_map<ll, ll> mg;
    for (ll i = 0; i < n; i++)
    {
        ll boy = a[i];
        ll girl = b[i];
        ll tcount = count;
        if (mb.find(boy) != mb.end())
        {
            tcount = tcount - mb[boy];
        }
        if (mg.find(girl) != mg.end())
        {
            tcount = tcount - mg[girl];
        }
        ans = ans + (tcount > 0 ? tcount : 0);
        mb[boy]++;
        mg[girl]++;
        count++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin >> t;
    while (t > 0)
    {
        t--;
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        ll k;
        cin >> k;
        vector<ll> a;
        inp(a, k);
        vector<ll> b;
        inp(b, k);
        solve(a, b, k);
    }
}