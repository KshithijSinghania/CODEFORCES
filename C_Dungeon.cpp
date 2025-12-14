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
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second > p2.second;
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

void solve(priority_queue<int, vector<int>, greater<int>> pq, vector<pair<ll, ll>> monsters, vector<ll> dummy, ll ns, ll nm)
{
    ll ans = 0;
    ll ptr = 0;
    ll ptr1 = 0;
    while (pq.size())
    {
        ll sword = pq.top();
        pq.pop();
        // cout << sword << " " << pq.size() << endl;
        if (ptr < monsters.size())
        {
            ll mons = monsters[ptr].first;
            ll get = monsters[ptr].second;
            if (mons <= sword)
            {
                // cout << ptr << " " << mons << " " << get << endl;
                ans++;
                if (get > 0)
                    pq.push(max(get, sword));
                ptr++;
                continue;
                //   cout << pq.size() << " " << pq.top() << endl;
            }
        }

        if (ptr1 < dummy.size())
        {
            ll dummymns = dummy[ptr1];
            if (dummymns <= sword)
            {
                ans++;
                ptr1++;
            }
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
        ll ns;
        cin >> ns;
        ll nm;
        cin >> nm;
        vector<ll> a;
        inp(a, ns);
        vector<ll> b;
        inp(b, nm);
        vector<ll> c;
        inp(c, nm);
        vector<pair<ll, ll>> monsters;
        loop(i, nm)
        {
            monsters.push_back({b[i], c[i]});
        }
        sort(monsters.begin(), monsters.end(), comp);
        // solve(a,n);
        vector<pair<ll, ll>> temp1;
        vector<pair<ll, ll>> temp2;
        vector<ll> dummy;
        loop(i, nm)
        {
            if (monsters[i].second == 0)
            {
                temp2.push_back({monsters[i].first, monsters[i].second});
                dummy.push_back(monsters[i].first);
            }
            else
            {
                temp1.push_back({monsters[i].first, monsters[i].second});
            }
        }
        // loop(i, temp2.size())
        // {
        //     temp1.push_back({temp2[i].first, temp2[i].second});
        // }
        priority_queue<int, vector<int>, greater<int>> pq;
        loop(i, ns)
        {
            pq.push(a[i]);
        }
        solve(pq, temp1, dummy, ns, nm);
    }
}