#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;

template <typename T>
void printa(const vec<T> &a)
{
    for (auto &p : a)
        cout << p << ' ';
    cout << endl;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    in >> p.first;
    in >> p.second;
    return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &e : v)
        in >> e;
    return in;
}
template <typename T>
void print2d(const vec<vec<T>> &v2)
{
    for (const auto &row : v2)
    {
        for (const auto &i : row)
            cout << i << " ";
        cout << endl;
    }
}

static inline ll s3(ll n)
{
    ll s = 0;
    while (n)
    {
        s += n % 3;
        n /= 3;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    vec<ull> p3(40, 1);
    for (int i = 1; i < 40; ++i)
        p3[i] = p3[i - 1] * 3ull;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        ll s = s3(n);
        ll d0 = min(k, n);
        ll d = (d0 % 2 == n % 2) ? d0 : d0 - 1;
        if (d < s)
        {
            cout << -1 << endl;
            continue;
        }

        ll m = (n - d) / 2;
        vec<unsigned long long> cnt(1, (ull)n);
        ull add = 0;
        int x = 0;
        while (m > 0)
        {
            if (x >= (int)cnt.size())
                cnt.pb(0);
            ull avail = cnt[x] / 3ull;
            if (avail == 0)
            {
                ++x;
                continue;
            }
            ull take = (ull)min<ll>(avail, m);
            add += take * p3[x];
            cnt[x] -= take * 3ull;
            if (x + 1 >= (int)cnt.size())
                cnt.pb(0);
            cnt[x + 1] += take;
            m -= (ll)take;
        }

        cout << (3ull * (ull)n + add) << endl;
    }
    return 0;
}
