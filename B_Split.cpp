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
    map<ll, ll> m;
    loop(i, 2 * n)
    {
        m[a[i]]++;
    }
    ll ans = 0;
    ll xo = 0;
    for (auto it : m)
    {
        if (it.second % 2 == 0)
        {
        }
        else
        {
            xo++;
            ans += 1;
        }
    }
    ll temp = 0;
    for (auto it : m)
    {
        if (it.second % 2 == 0)
        {
            if (((it.second / 2) % 2) == 1)
                ans += 2;
            else
                temp++;
        }
    }
    ans += ((temp / 2) * 4);
    if (temp % 2 == 1 && xo >= 1)
    {
        ans += 2;
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
        vector<ll> a;
        inp(a, 2 * n);
        solve(a, n);
    }
}