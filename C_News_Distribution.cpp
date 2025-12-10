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

vector<ll> parent;
vector<ll> compsize;

ll findUPar(ll u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = findUPar(parent[u]);
}
void UnionBycompsize(ll u, ll v)
{
    ll uu = findUPar(u);
    ll uv = findUPar(v);
    if (uu == uv)
        return;
    ll su = compsize[uu];
    ll sv = compsize[uv];
    if (su < sv)
    {
        parent[uu] = uv;
        compsize[uv] += compsize[uu];
    }
    else if (sv < su)
    {
        parent[uv] = uu;
        compsize[uu] += compsize[uv];
    }
    else
    {
        parent[uv] = uu;
        compsize[uu] += compsize[uv];
    }
}

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

void solve(ll n, ll m)
{
    compsize.resize(n + 1, 1);
    loop(i, n + 1)
    {
        parent.push_back(i);
    }
    loop(i, m)
    {
        ll s;
        cin >> s;
        vector<ll> mems;
        loop(j, s)
        {
            ll d;
            cin >> d;
            mems.push_back(d);
        }
        if (s <= 1)
            continue;
        loop(j, s - 1)
        {
            ll u = mems[j];
            ll v = mems[j + 1];
            UnionBycompsize(u, v);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        ll upar = findUPar(i);
        cout << compsize[upar] << " ";
    }
    cout << endl;
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
        // vector <ll> a;
        // inp(a,n);
        solve(n, m);
    }
}