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

void solve(ll n, ll a, ll b)
{
    if (n % 2 == 1)
    {
        if (a % 2 == 1 && b % 2 == 1)
        {
            cout << "YES" << endl;
            return;
        }
        else if (a % 2 != 1 && b % 2 == 1 && a < b)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            cout << "YES" << endl;
            return;
        }
        else if (a % 2 != 0 && b % 2 == 0 && a < b)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
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
        ll a;
        cin >> a;
        ll b;
        cin >> b;
        // vector <ll> a;
        // inp(a,n);
        solve(n, a, b);
    }
}