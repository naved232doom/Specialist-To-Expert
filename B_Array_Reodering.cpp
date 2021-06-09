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

ll gcd(ll a,ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void solve()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    rep(i,n) cin>>arr[i];
    vector<int> odds,evens;
    rep(i,n){
        if(arr[i]%2) odds.push_back(arr[i]);
        else evens.push_back(arr[i]);
    }
    sort(all(odds));
    sort(all(evens));
    reverse(all(odds));
    reverse(all(evens));
    vector<ll> f;
    for(auto v:evens){
        f.push_back(v);
    }
    for(auto v:odds){
        f.push_back(v);
    }
    int ans=0;
    for(int i=0;i<sz(f);++i){
        for(int j=i+1;j<sz(f);++j){
            if(gcd(f[i],2*f[j])>1){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main()
{
//     fast;
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}