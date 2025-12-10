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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll dp[n + 1];
        loop(i, n + 1)
        {
            dp[i] = 1;
        }
        for (ll i = 2; i <= n; i++)
        {
            for (ll j = 1; (j * j) <= i; j++)
            {
                if (i % j != 0)
                    continue;
                if ((a[i] > a[j]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                if (a[i] > a[i / j])
                {
                    dp[i] = max(dp[i], 1 + dp[i / j]);
                }
            }
        }
        ll maxi = 1;
        loop(i, n + 1)
        {
            maxi = max(maxi, dp[i]);
        }
        cout << maxi << endl;
    }
}