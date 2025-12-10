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

void solve(ll a, ll b, ll c, ll d)
{
    ll mini = min(a, b);
    ll maxi = max(a, b);
    if (maxi % 2 == 1)
        maxi++;
    if (mini < ((maxi / 2) - 1))
    {
        cout << "NO" << endl;
        return;
    }
    c = c - a;
    d = d - b;
    mini = min(c, d);
    maxi = max(c, d);
    if (maxi % 2 == 1)
        maxi++;
    if (mini < ((maxi / 2) - 1))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        // ll n;
        // cin>>n;
        // vector <ll> a;
        // inp(a,n);
        solve(a, b, c, d);
    }
}