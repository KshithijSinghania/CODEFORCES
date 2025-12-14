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

void solve(vector<vector<char>> a, ll n)
{
    multiset<ll> x, y, sum, diff;

    loop(i, n)
    {
        loop(j, n)
        {
            if (a[i][j] == '#')
            {
                x.insert(i);
                y.insert(j);
                sum.insert(i + j);
                diff.insert(i - j);
            }
        }
    }

    if (x.size() < 2)
    {
        cout << "YES\n";
        return;
    }

    bool check = false;

    check |= ((*x.rbegin() - *x.begin()) <= 1 &&
              (*y.rbegin() - *y.begin()) <= 1);

    check |= ((*sum.rbegin() - *sum.begin()) <= 1);
    check |= ((*diff.rbegin() - *diff.begin()) <= 1);

    cout << (check ? "YES\n" : "NO\n");
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

        vector<vector<char>> a(n, vector<char>(n));
        loop(i, n)
        {
            loop(j, n)
            {
                char k;
                cin >> k;
                a[i][j] = k;
            }
        }
        solve(a, n);
    }
}