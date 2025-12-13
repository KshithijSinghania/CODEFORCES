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

void readVec(vector<ll> &arr, ll n)
{
    loop(i, n)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
}

//-------------------------------------

vector<int> buildSuffixMin(const vector<int> &row, int n)
{
    vector<int> suf = row;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(suf[i], suf[i + 1]);
    return suf;
}

vector<int> buildSuffixMax(const vector<int> &row, int n)
{
    vector<int> suf = row;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i], suf[i + 1]);
    return suf;
}

vector<int> buildRange(const vector<vector<int>> &grid, int n)
{
    vector<int> sufMin = buildSuffixMin(grid[1], n);
    vector<int> sufMax = buildSuffixMax(grid[1], n);

    vector<int> best(2 * n, 2 * n);

    int prefMin = grid[0][0], prefMax = grid[0][0];
    for (int j = 0; j < n; j++)
    {
        prefMin = min(prefMin, grid[0][j]);
        prefMax = max(prefMax, grid[0][j]);

        int mn = min(prefMin, sufMin[j]);
        int mx = max(prefMax, sufMax[j]);

        best[mn - 1] = min(best[mn - 1], mx - 1);
    }

    for (int i = 2 * n - 2; i >= 0; i--)
        best[i] = min(best[i], best[i + 1]);

    return best;
}

ll computeAns(const vector<int> &res, ll n)
{
    ll total = 0;
    for (auto x : res)
        total += (2 * n - x);
    return total;
}

//-------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<vector<int>> grid(2, vector<int>(n));
        for (auto &row : grid)
            for (auto &x : row)
                cin >> x;

        vector<int> ranges = buildRange(grid, n);
        ll ans = computeAns(ranges, n);

        cout << ans << "\n";
    }
}
