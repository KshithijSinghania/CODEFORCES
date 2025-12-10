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

void solve(vector<pair<ll, ll>> v, ll n, ll k)
{
    ll tans = 0;
    for (ll i = 0; i < n; i++)
    {
        tans += (v[i].second - v[i].first);
    }
    for (ll i = 0; i < n - 1; i++)
    {
        pair<ll, ll> a = v[i];
        pair<ll, ll> b = v[i + 1];
        if (b.first > a.first && b.second <= a.second)
        {
            cout << tans << endl;
            return;
        }
        if (a.first == b.first && a.second <= b.second)
        {
            cout << tans << endl;
            return;
        }
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n - 1; i++)
    {
        pair<ll, ll> a = v[i];
        pair<ll, ll> b = v[i + 1];
        vector<ll> temp;
        temp.push_back(a.first);
        temp.push_back(a.second);
        temp.push_back(b.first);
        temp.push_back(b.second);
        sort(temp.begin(), temp.end());
        ans = min(ans, tans - (a.second - a.first) - (b.second - b.first) + (temp[3] - temp[0]) + (temp[2] - temp[1]));
    }
    cout << ans << endl;
    return;
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
        ll k;
        cin >> k;
        vector<ll> a;
        inp(a, n);
        vector<ll> b;
        inp(b, n);
        vector<pair<ll, ll>> v;
        for (ll i = 0; i < n; i++)
        {
            v.push_back({min(a[i], b[i]), max(a[i], b[i])});
        }
        sort(v.begin(), v.end());
        solve(v, n, k);
    }
}