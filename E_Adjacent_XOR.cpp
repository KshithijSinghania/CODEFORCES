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

//-------------------------------------

void input_vector(vector<ll> &vec, ll n)
{
    loop(i, n)
    {
        ll val;
        cin >> val;
        vec.push_back(val);
    }
}

//-------------------------------------

string check_arrays(const vector<ll> &arr_a, const vector<ll> &arr_b, ll n)
{
    if (arr_a[n - 1] != arr_b[n - 1])
        return "NO";

    vector<ll> diff(n - 1);
    loop(i, n - 1) diff[i] = arr_a[i] ^ arr_b[i];

    bool valid = true;
    for (ll i = 0; i < n - 1 && valid;)
    {
        if (diff[i] == 0)
        {
            i++;
            continue;
        }
        ll j = i;
        while (true)
        {
            if (diff[j] == arr_a[j + 1])
            {
                i = j + 1;
                break;
            }
            if (j == n - 2)
            {
                valid = false;
                break;
            }
            if (diff[j + 1] != (diff[j] ^ arr_a[j + 1]))
            {
                valid = false;
                break;
            }
            j++;
        }
    }
    return valid ? "YES" : "NO";
}

//-------------------------------------

void solve_case()
{
    ll n;
    cin >> n;
    vector<ll> arr_a, arr_b;
    input_vector(arr_a, n);
    input_vector(arr_b, n);
    cout << check_arrays(arr_a, arr_b, n) << "\n";
}

//-------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull t;
    cin >> t;
    while (t--)
    {
        solve_case();
    }
    return 0;
}
