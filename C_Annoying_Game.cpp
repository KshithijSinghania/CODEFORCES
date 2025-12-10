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

void solve(vector<ll> a, vector<ll> b, ll n, ll k)
{
    vector<ll> dp1;
    dp1.push_back(a[0]);
    loop1(i, n - 1)
    {
        dp1.push_back(max(dp1[i - 1] + a[i], a[i]));
    }
    vector<ll> dp2(n);
    dp2[n - 1] = (a[n - 1]);
    for (ll i = n - 2; i >= 0; i--)
    {
        dp2[i] = (max(dp2[i + 1] + a[i], a[i]));
    }
    if (k)
    {
        ll ans = *max_element(dp1.begin(), dp1.end());

        for (ll i = 0; i < n; i++)
        {
            ans = max(ans, a[i] + b[i] + (i > 0 ? (dp1[i - 1]) : 0) + (i < (n - 1) ? (dp2[i + 1]) : 0));
        }
        cout << ans << endl;
    }
    else
    {
        cout << *max_element(dp1.begin(), dp1.end()) << endl;
    }
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
        k = k % 2;
        vector<ll> a;
        inp(a, n);
        vector<ll> b;
        inp(b, n);
        solve(a, b, n, k);
    }
}