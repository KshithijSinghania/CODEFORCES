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
        vector<vector<ll>> v;
        ll count = 1;
        loop(i, n)
        {
            vector<ll> temp;
            loop(j, n)
            {
                temp.push_back(count);
                count++;
            }
            v.push_back(temp);
        }
        ll temp = 0;
        loop(i, n)
        {
            loop(j, n)
            {
                ll ans = 0;
                ans += v[i][j];
                if (i > 0)
                    ans += v[i - 1][j];
                if (j > 0)
                    ans += v[i][j - 1];
                if (i != (n - 1))
                    ans += v[i + 1][j];
                if (j != (n - 1))
                    ans += v[i][j + 1];
                temp = max(temp, ans);
            }
        }
        cout << temp << endl;
        // vector <ll> a;
        // inp(a,n);
        // solve(a,n);
    }
}