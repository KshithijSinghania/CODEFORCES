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

// compute digit sum in base-3
ll digit_sum_base3(ll value)
{
    ll result = 0;
    while (value > 0)
    {
        result += value % 3;
        value /= 3;
    }
    return result;
}

// build powers of 3 once
void build_power_table(vector<ull> &power_table, ll length)
{
    power_table[0] = 1;
    loop1(i, length - 1)
    {
        power_table[i] = power_table[i - 1] * 3ull;
    }
}

// main solver for each test
void evaluate_case(ll initial, ll restriction, vector<ull> &power_table)
{
    ll sum_digits = digit_sum_base3(initial);

    ll upper_bound = min(restriction, initial);
    ll adjusted = (upper_bound % 2 == initial % 2) ? upper_bound : upper_bound - 1;

    if (adjusted < sum_digits)
    {
        cout << "-1\n";
        return;
    }

    ll remaining = (initial - adjusted) / 2;
    vector<ull> bucket(1, (ull)initial);
    ull extra_contribution = 0;
    ll pos = 0;

    while (remaining > 0)
    {
        if (pos >= (ll)bucket.size())
            bucket.push_back(0);

        ull possible = bucket[pos] / 3ull;
        if (possible == 0)
        {
            pos++;
            continue;
        }

        ull take = (ull)min<ll>(possible, remaining);
        extra_contribution += take * power_table[pos];
        bucket[pos] -= take * 3ull;

        if (pos + 1 >= (ll)bucket.size())
            bucket.push_back(0);
        bucket[pos + 1] += take;

        remaining -= (ll)take;
    }

    cout << (3ull * (ull)initial + extra_contribution) << "\n";
}

//-------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull test_count;
    cin >> test_count;

    vector<ull> power_table(40, 1);
    build_power_table(power_table, 40);

    while (test_count--)
    {
        ll initial, restriction;
        cin >> initial >> restriction;
        evaluate_case(initial, restriction, power_table);
    }
}
