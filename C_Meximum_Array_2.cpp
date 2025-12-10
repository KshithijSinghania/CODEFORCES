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
        ll k;
        cin >> k;
        ll q;
        cin >> q;
        vector<vector<ll>> que1;
        vector<vector<ll>> que2;
        loop(i, q)
        {
            ll type;
            cin >> type;
            ll l;
            cin >> l;
            ll r;
            cin >> r;
            vector<ll> temp;
            temp.push_back(type);
            temp.push_back(l);
            temp.push_back(r);
            if (type == 1)
                que1.push_back(temp);
            else
                que2.push_back(temp);
        }

        vector<ll> ans(n, -1);
        loop(i, que1.size())
        {
            vector<ll> temp = que1[i];
            ll type = temp[0];
            ll l = temp[1];
            ll r = temp[2];
            for (ll j = l - 1; j < r; j++)
            {
                ans[j] = k;
            }
        }
        loop(i, que2.size())
        {
            vector<ll> temp = que2[i];
            ll type = temp[0];
            ll l = temp[1];
            ll r = temp[2];
            for (ll j = l - 1; j < r; j++)
            {
                if (ans[j] == k)
                {
                    ans[j] = k + 1;
                }
                else
                {
                    ans[j] = ((j + 1) % k);
                }
            }
        }
        loop(i, n)
        {
            if (ans[i] == -1)
                ans[i] = k;
        }
        loop(i, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        // solve(a,n);
    }
}