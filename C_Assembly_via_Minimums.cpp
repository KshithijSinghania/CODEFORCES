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

void solve(vector<ll> a, ll n, ll as)
{
    vector<ll> ans;
    map<ll, ll> m;
    loop(i, as)
    {
        m[a[i]]++;
    }
    ll ms = m.size();
    ll count = 1;
    ll nextm = 0;
    auto it = m.begin();
    while (ms > 0)
    {
        ll val = it->first;
        ll num = it->second;
        ans.push_back(val);
        num = num - (n - count);
        count++;
        if (num == 0)
        {
            advance(it, 1);
            ms--;
        }
        else
        {
            m[val] = num;
        }
    }
    while (ans.size() != n)
    {
        ans.push_back(1e9);
    }
    loop(i, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
        ll as;
        as = (n * (n - 1)) / 2;
        vector<ll> a;
        inp(a, as);
        solve(a, n, as);
    }
}