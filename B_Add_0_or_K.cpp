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

void solve(vector<ll> a, ll n, ll k)
{
    vector<ll> ans(n);
    if (k % 2 == 1)
    {
        loop(i, n)
        {
            if (a[i] % 2 == 0)
                ans[i] = a[i];
            else
                ans[i] = a[i] + k;
        }
    }
    else
    {
        if (k != 2)
        {
            ll x;
            loop(i, n)
            {
                if (a[i] % (k - 1) == 0)
                {
                    x = k - 1;
                }
                else
                {
                    x = k - 1 - (a[i] % (k - 1));
                }
                ans[i] = a[i] + (x * (k));
            }
        }
        else
        {
            loop(i, n)
            {
                if (a[i] % 3 == 0)
                {
                    ans[i] = a[i];
                }
                else if ((a[i] + 2) % 3 == 0)
                    ans[i] = a[i] + 2;
                else
                {
                    ans[i] = a[i] + 4;
                }
            }
        }
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
        ll k;
        cin >> k;
        vector<ll> a;
        inp(a, n);
        solve(a, n, k);
    }
}