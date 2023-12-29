#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005], segTree[4 * 100005];
void build(ll ind, ll lo, ll hi)
{
    if (lo == hi)
    {
        segTree[ind] = a[lo];
        return;
    }
    ll mid = lo + ((hi - lo) >> 1);
    build(2 * ind + 1, lo, mid);
    build(2 * ind + 2, mid + 1, hi);
    segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
}

ll query(ll ind, ll lo, ll hi, ll l, ll r)
{
    // completely inside
    if (l <= lo && r >= hi)
        return segTree[ind];

    // completely outside
    if (hi < l || lo > r)
        return 0;

    // overlapping
    ll mid = (lo + hi) >> 1;
    return query(2 * ind + 1, lo, mid, l, r) +
           query(2 * ind + 2, mid + 1, hi, l, r);
}

void Update(ll ind, int lo, int hi, ll pos, ll val)
{
    if (lo == hi)
    {
        segTree[ind] = val;
        return;
    }
    int mid = (lo + hi) >> 1;
    if (pos <= mid)
        Update(ind * 2 + 1, lo, mid, pos, val);
    else
        Update(ind * 2 + 2, mid + 1, hi, pos, val);

    segTree[ind] = (segTree[ind * 2 + 1] + segTree[2 * ind + 2]);
}