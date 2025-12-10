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

void solve(vector<ll> a, ll n)
{
    // f(x)=x^2 + x - S(x)
    vector<ll> s;
    s.push_back(0);
    loop(i, n)
    {
        s.push_back(s[i] + a[i]);
    }
    vector<ll> f;
    for (ll i = 0; i < n; i++)
    {
        f.push_back(((i + 1) * (i + 1)) + (i + 1) - s[i + 1]);
    }
    ll mini = 0;
    ll ans = 0;
    loop(i, f.size())
    {
        ans = max(ans, f[i] - mini);
        mini = min(mini, f[i]);
    }
    cout << ans + s[n] << endl;
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
        vector<ll> a;
        inp(a, n);
        solve(a, n);
    }
}