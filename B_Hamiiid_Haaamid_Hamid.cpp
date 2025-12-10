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

void inp(string a, ll n, ll pos)
{
    loop(i, n)
    {
        ll d;
        cin >> d;
        a.push_back(d);
    }
}

//-------------------------------------

void solve(string a, ll n, ll pos)
{
    ll rl = 0;
    ll rr = 0;
    map<char, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    if (m.size() == 1)
    {
        for (auto it : m)
        {
            if (it.first == '.')
            {
                cout << 1 << endl;
                return;
            }
        }
    }
    for (ll i = pos - 2; i >= 0; i--)
    {
        if (a[i] == '#')
            rl += i;
    }
    for (ll i = pos; i < n; i++)
    {
        if (a[i] == '#')
            rr += ((n - 1) - i);
    }
    for (ll i = pos - 2; i >= 0; i--)
    {
        if (a[i] == '.')
        {
            rl += i;
            break;
        }
    }
    for (ll i = pos; i < n; i++)
    {
        if (a[i] == '.')
        {
            rr += ((n - 1) - i);
            break;
        }
    }
    if (rl < rr)
    {
        cout << pos << endl;
    }
    else
    {
        cout << n - pos + 1 << endl;
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
        ll pos;
        cin >> pos;
        // vector <ll> a;
        // inp(a,n);
        string a;
        cin >> a;
        solve(a, n, pos);
    }
}