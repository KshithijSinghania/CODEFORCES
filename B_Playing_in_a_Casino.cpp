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
        ll m;
        cin >> m;
        vector<vector<ll>> a;
        loop(i, n)
        {
            vector<ll> temp;
            loop(j, m)
            {
                ll k;
                cin >> k;
                temp.push_back(k);
            }
            a.push_back(temp);
        }
        vector<vector<ll>> b;
        loop(i, m)
        {
            vector<ll> temp;
            loop(j, n)
            {
                temp.push_back(a[j][i]);
            }
            b.push_back(temp);
        }

        loop(i, b.size())
        {
            sort(b[i].begin(), b[i].end());
        }
        ll ans = 0;
        loop(i, m)
        {
            ll wt = -1 * (n - 1);
            loop(j, n)
            {
                ans += (wt * b[i][j]);
                wt += 2;
            }
        }
        cout << ans << endl;
        // inp(a,n);
        // solve(a,n);
    }
}