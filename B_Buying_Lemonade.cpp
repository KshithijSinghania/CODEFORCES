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
    ll start = 1;
    ll end = 2 * k;
    ll ans = LLONG_MAX;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        ll clicks = 0;
        ll left = k;
        bool flag = false;
        // cout<<mid<<"mid"<<endl;
        for (ll i = 1; i <= n; i++)
        {

            if (clicks > mid)
            {
                flag = true;
            }
            clicks += min(left, ((a[i] - a[i - 1]) * (n - i + 1)));

            // cout<<clicks<<" "<<left<<endl;
            left = left - min(left, ((a[i] - a[i - 1]) * (n - i + 1)));
            if (left > 0)
                clicks++;
        }
        if (clicks > mid)
        {
            flag = true;
        }
        if (flag == true)
        {
            start = mid + 1;
        }
        else
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
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
        a.push_back(0);
        sort(a.begin(), a.end());
        solve(a, n, k);
    }
}