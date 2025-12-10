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

void solve(vector<ll> a, ll n)
{
    vector<ll> countneg;
    countneg.push_back(0);
    loop(i, n)
    {
        if (a[i] > 0)
            countneg.push_back(countneg.back());
        else
            countneg.push_back(countneg.back() + 1);
    }
    ll even = 0;
    ll odd = 0;
    ll ans = 0;
    loop(i, n + 1)
    {
        if (countneg[i] % 2 == 0)
        {
            ans += even;
            even++;
        }
        else
        {
            ans += odd;
            odd++;
        }
    }
    ll ans1 = (n * (n + 1)) / 2;
    ans1 = ans1 - ans;
    cout << ans1 << " " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t = 1;
    while (t > 0)
    {
        t--;
        ll n;
        cin >> n;
        vector<ll> a;
        inp(a, n);
        solve(a, n);
    }
}