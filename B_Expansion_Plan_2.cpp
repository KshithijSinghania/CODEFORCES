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

void solve(string s, ll n, ll x, ll y)
{
    x = abs(x);
    y = abs(y);
    ll t1 = max(x, y);
    ll t2 = min(x, y);
    x = t1;
    y = t2;
    loopr(i, n)
    {
        if (s[i] == '4')
        {
            x = abs(x);
            y = abs(y);
            ll t1 = max(x, y);
            ll t2 = min(x, y);
            x = t1;
            y = t2;
            x--;
        }
        else
        {
            x = abs(x);
            y = abs(y);
            ll t1 = max(x, y);
            ll t2 = min(x, y);
            x = t1;
            y = t2;
            x--;
            y--;
        }
        if (x < 0)
            x = 0;
        if (y < 0)
            y = 0;
    }
    if (x <= 0 && y <= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        ll x;
        ll y;
        cin >> x >> y;
        string s;
        cin >> s;
        // vector <ll> a;
        // inp(a,n);
        solve(s, n, x, y);
    }
}