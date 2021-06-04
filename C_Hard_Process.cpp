#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef pair<int, int> pii;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define ld long double
#define rep(i, a) for (ll i = 0; i < a; i++)
#define repe(i, a, b) for (ll i = a; i < b; i++)
#define bac(i, a) for (ll i = a; i >= 0; i--)
#define bace(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define in insert
#define ff first
#define ss second
#define setbit(x) __builtin_popcountll(x)
#define init(c, a) memset(c, a, sizeof(c))
#define all(c) c.begin(), c.end()
#define sz(c) (ll) c.size()
#define lb lower_bound
#define ub upper_bound
#define maxe *max_element
#define mine *min_element
#define rev reverse
#define debug(x) cout << #x << " : " << x << endl;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);
//priority_queue<pii, vector<pii>, greater<pii> > pq;

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    rep(i, n) cin >> arr[i];
    vector<int> pref(n + 1);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        pref[i + 1] = pref[i];
        if (!arr[i])
            pref[i+1] += 1;
        mp[pref[i+1]] = max(i + 1, mp[pref[i+1]]);
    }
    int ans = 0;
    int idx = -1;
    int mxlen = 0;
    for (int i = 0; i < n; ++i)
    {
        int p1=pref[i+1]+k;
        if(arr[i]==0) p1--;
        int p = mp[min(p1,pref[n])]-i;
        //debug(p);
        if(p>mxlen){
            mxlen=max(mxlen,p);
            idx=i;
        }
    }
    cout<<mxlen<<'\n';
    int cnt=k;
    for(int i=idx;i<n&&cnt;++i){
        if(arr[i]==0){
        arr[i]=1;
        cnt--;
        }
    }
    for(int i=0;i<n;++i) cout<<arr[i]<<" ";
    cout<<"\n";

}
int main()
{
    //     fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    while (t--)
        solve();
    return 0;
}