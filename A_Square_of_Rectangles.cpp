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
    return (p1.first * p1.second > p2.first * p2.second);
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

void solve(vector<pair<ll, ll>> v)
{
    sort(v.begin(), v.end(), comp);
    ll maxl = v[0].first;
    ll maxb = v[0].second;
    // niche
    // ek ke niche ek
    if (v[1].first == maxl && v[2].first == maxl && v[1].second + v[2].second + maxb == maxl)
    {
        cout << "YES" << endl;
        return;
    }
    // ek ke niche 2
    if (v[1].first + v[2].first == maxl && v[1].second == v[2].second && maxb + v[1].second == maxl)
    {
        cout << "YES" << endl;
        return;
    }

    // side mein
    if (v[1].second == maxb && v[2].second == maxb && v[1].first + v[2].first + maxl == maxb)
    {
        cout << "YES" << endl;
        return;
    }
    if (v[1].second + v[2].second == maxb && v[1].first == v[2].first && maxl + v[1].first == maxb)
    {
        cout << "YES" << endl;
        return;
    }
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
        vector<pair<ll, ll>> v;
        for (ll i = 0; i < 3; i++)
        {
            ll l, b;
            cin >> l >> b;
            v.push_back({l, b});
        }
        solve(v);
    }
}