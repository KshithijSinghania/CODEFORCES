#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
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

void solve(vector<ll> a, ll n, ll x)
{
    // vector<ll> premin;
    // vector<ll> premax;
    // vector<ll> postmin;
    // vector<ll> postmax;
    // ll mini = 1e9;
    // loop(i, n)
    // {
    //     mini = min(mini, a[i]);
    //     premin.push_back(mini);
    // }
    // mini = 1e9;
    // loopr(i, n)
    // {
    //     mini = min(mini, a[i]);
    //     postmin.push_back(mini);
    // }
    // reverse(all(postmin));
    // ll maxi = -1e9;
    // loop(i, n)
    // {
    //     maxi = max(maxi, a[i]);
    //     premax.push_back(maxi);
    // }
    // maxi = -1e9;
    // loopr(i, n)
    // {
    //     maxi = max(maxi, a[i]);
    //     postmax.push_back(maxi);
    // }
    // reverse(all(postmax));
    // loop(i, n - 1)
    // {
    //     cout << premin[i] << " " << postmin[i+1] << " " << premax[i] << " " << postmax[i] << endl;
    //     if (min(premin[i], postmin[i + 1]) >= x && max(premin[i], postmin[i + 1]) <= x)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     if (min(premin[i], postmax[i + 1]) >= x && max(premin[i], postmax[i + 1]) <= x)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     if (min(premax[i], postmin[i + 1]) >= x && max(premax[i], postmin[i + 1]) <= x)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     if (min(premax[i], postmax[i + 1]) >= x && max(premax[i], postmax[i + 1]) <= x)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // cout << "NO" << endl;
    loop(i, n - 1)
    {
        if (a[i] <= x && a[i + 1] >= x)
        {
            cout << "YES" << endl;
            return;
        }
        if (a[i] >= x && a[i + 1] <= x)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (n == 1)
    {
        if (a[0] == x)
        {
            cout << "YES" << endl;
            return;
        }
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
        ll n;
        cin >> n;
        vector<ll> a;
        inp(a, n);
        ll x;
        cin >> x;
        solve(a, n, x);
    }
}