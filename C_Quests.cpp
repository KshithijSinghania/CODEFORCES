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

ll sol(ll idx, ll same, vector<ll> a, vector<ll> b, ll n, ll k, vector<vector<ll>> &dp)
{
    if (k == 0)
    {
        return 0;
    }
    if (idx == n)
    {
        return 0;
    }
    if (dp[k][same] != -1)
        return dp[k][same];
    if (same)
    {
        ll val1 = b[idx] + sol(idx, 1, a, b, n, k - 1, dp);
        ll val2 = b[idx] + sol(idx + 1, 0, a, b, n, k - 1, dp);
        return dp[k][same] = max(val1, val2);
    }
    ll val1 = a[idx] + sol(idx, 1, a, b, n, k - 1, dp);
    ll val2 = a[idx] + sol(idx + 1, 0, a, b, n, k - 1, dp);
    return dp[k][same] = max(val1, val2);
}

void solve(vector<ll> a, vector<ll> b, ll n, ll k)
{
    vector<ll> preA;
    vector<ll> maxB;
    preA.push_back(a[0]);
    maxB.push_back(b[0]);
    for (ll i = 1; i < min(n, k); i++)
    {
        preA.push_back(preA.back() + a[i]);
        maxB.push_back(max(maxB.back(), b[i]));
    }
    ll ans = 0;
    loop(i, min(n, k))
    {
        ans = max(ans, preA[i] + maxB[i] * (k - i - 1));
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
        ll k;
        cin >> k;
        vector<ll> a;
        inp(a, n);
        vector<ll> b;
        inp(b, n);
        solve(a, b, n, k);
    }
}