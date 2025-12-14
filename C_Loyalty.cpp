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
    sort(all(a));
    ll leftptr = 0;
    ll rightptr = n - 1;
    ll val = 0;
    ll ans = 0;
    ll prev = 0;
    vector<ll> temp;
    while (leftptr <= rightptr)
    {
        if (((val + a[rightptr]) / x) > prev)
        {
            ans += a[rightptr];
            val += a[rightptr];
            prev = val / x;
            temp.push_back(a[rightptr]);
            rightptr--;
        }
        else
        {
            val += a[leftptr];
            temp.push_back(a[leftptr]);
            leftptr++;
        }
    }
    cout << ans << endl;
    loop(i, temp.size())
    {
        cout << temp[i] << " ";
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
        ll x;
        cin >> x;
        vector<ll> a;
        inp(a, n);
        solve(a, n, x);
    }
}