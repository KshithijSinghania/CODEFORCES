#include <bits/stdc++.h>
using namespace std;

// --- Utility Macros ---
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = 1e5 + 10;

// --- Function to Read Input Array ---
void readInputArray(int &size, vi &arr)
{
    cin >> size;
    arr.resize(size + 1);
    for (int idx = 1; idx <= size; ++idx)
    {
        cin >> arr[idx];
    }
}

// --- Function to Build Next Occurrence Array ---
void buildNextOccurrence(const vi &arr, vi &nextOccurrence, vi &lastSeen, int size)
{
    fill(lastSeen.begin(), lastSeen.end(), size + 1);
    for (int idx = size; idx >= 1; --idx)
    {
        nextOccurrence[idx] = lastSeen[arr[idx]];
        lastSeen[arr[idx]] = idx;
    }
}

// --- Function to Calculate Minimum Segments ---
int calculateMinSegments(const vi &nextOccurrence, int size)
{
    int currentPos = 1, segmentCount = 0;
    while (currentPos <= size)
    {
        int segmentEnd = currentPos;
        while (true)
        {
            int maxNext = 0;
            for (int idx = currentPos; idx <= segmentEnd; ++idx)
            {
                maxNext = max(maxNext, nextOccurrence[idx]);
            }
            segmentCount++;
            if (maxNext > size)
                break;
            currentPos = segmentEnd + 1;
            segmentEnd = maxNext;
        }
        break;
    }
    return segmentCount;
}

// --- Main Solver Function ---
void solveTestCase()
{
    int n;
    vi inputArr, nextOccurrence, lastSeen;
    readInputArray(n, inputArr);
    nextOccurrence.assign(n + 2, 0);
    lastSeen.assign(n + 2, 0);

    buildNextOccurrence(inputArr, nextOccurrence, lastSeen, n);
    int result = calculateMinSegments(nextOccurrence, n);

    cout << result << endl;
}

// --- Main Function ---
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; ++t)
    {
        solveTestCase();
    }
    return 0;
}
