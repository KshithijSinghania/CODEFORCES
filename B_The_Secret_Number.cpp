#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define reverse1(v) reverse(v.begin(), v.end())
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

void solve(ull n)
{
    ull val = 11;
    vector<ull> ans;
    while (val < 1e18 + 2)
    {
        if (n % val == 0)
            ans.push_back(n / val);
        val = val - 1;
        val = val * 10;
        val++;
    }
    cout << ans.size() << endl;
    if (ans.size())
    {
        reverse(ans.begin(), ans.end());
        loop(i, ans.size())
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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
        ull n;
        cin >> n;
        // vector <ll> a;
        // inp(a,n);
        solve(n);
    }
}