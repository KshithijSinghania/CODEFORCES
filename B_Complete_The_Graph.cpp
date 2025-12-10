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

void solve(ll n, ll d, ll s, ll t, vector<vector<pair<int, int>>> adj, vector<pair<ll, ll>> broken, vector<vector<ll>> ans)
{
    vector<ll> dist1(n, (ll)(1e9));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    dist1[s] = 0;
    while (pq.size())
    {
        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dist1[it.first] > wt + it.second)
            {
                dist1[it.first] = wt + it.second;
                pq.push({wt + it.second, it.first});
            }
        }
    }
    if (dist1[t] < d)
    {
        cout << "NO" << endl;
        return;
    }
    if (dist1[t] == d)
    {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i][2] == 0)
            {
                cout << ans[i][0] << " " << ans[i][1] << " " << ((ll)(1e9)) << endl;
            }
            else
            {
                cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
            }
        }
        return;
    }
    vector<ll> dist2(n, (ll)(1e9));
    pq.push({0, t});
    dist2[t] = 0;
    while (pq.size())
    {
        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dist2[it.first] > wt + it.second)
            {
                dist2[it.first] = wt + it.second;
                pq.push({wt + it.second, it.first});
            }
        }
    }
    ll first = 0;
    ll second = 0;
    ll val = -1;
    for (auto it : broken)
    {
        if (dist1[it.first] + dist2[it.second] <= d)
        {
            val = d - (dist1[it.first] + dist2[it.second]);
            // cout << val << endl;
            first = it.first;
            second = it.second;
            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i][2] == 0)
                {
                    if ((ans[i][0] == first && ans[i][1] == second) || (ans[i][0] == second && ans[i][1] == first))
                    {
                        cout << ans[i][0] << " " << ans[i][1] << " " << val << endl;
                    }
                    else
                    {
                        cout << ans[i][0] << " " << ans[i][1] << " " << ((ll)(1e9)) << endl;
                    }
                }
                else
                {
                    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
                }
            }
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    t = 1;
    while (t > 0)
    {
        t--;
        ll n;
        cin >> n;
        ll m;
        cin >> m;
        ll d;
        cin >> d;
        ll s, t;
        cin >> s >> t;
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<ll>> ans;
        vector<pair<ll, ll>> broken;
        for (ll i = 0; i < m; i++)
        {
            ll first, second, wt;
            cin >> first >> second >> wt;
            ans.push_back({first, second, wt});
            if (wt == 0)
            {
                wt = (ll)(1e9);
                broken.push_back({first, second});
                broken.push_back({second, first});
            }
            adj[first].push_back({second, wt});
            adj[second].push_back({first, wt});
        }
        if (adj[s].size() == 0 || adj[t].size() == 0)
        {
            cout << "NO" << endl;
            // return;
        }
        else
            solve(n, d, s, t, adj, broken, ans);
    }
}