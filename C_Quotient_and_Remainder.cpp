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

void inp(vector<ll> &a, ll n)
{
    loop(i, n)
    {
        ll d;
        cin >> d;
        a.push_back(d);
    }
}

void solve(vector<ll> q, vector<ll> r, ll k, ll n)
{
    vector<pair<ll, ll>> qt; // {T_i, q_i}
    qt.reserve(n);

    // compute T_i = floor((k - q_i)/(q_i+1))
    loop(i, n)
    {
        ll qi = q[i];
        ll T = (k - qi) / (qi + 1);
        qt.push_back({T, qi});
    }

    // sort by threshold
    sort(qt.begin(), qt.end());
    // sort r
    sort(r.begin(), r.end());

    ll matches = 0;
    ll j = 0;

    // greedy two-pointer
    loop(i, n)
    {
        ll T = qt[i].first;

        if (j < n && r[j] <= T)
        {
            matches++;
            j++; // use this r
        }
    }

    cout << matches << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> q, r;
        inp(q, n);
        inp(r, n);

        solve(q, r, k, n);
    }
}
