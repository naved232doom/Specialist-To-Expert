#include <bits/stdc++.h>

using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
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
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
ll getpower10(ll a)
{
    ll res = 1;
    for (int i = 0; i < a; ++i)
    {
        res *= 10;
    }
    return res;
}
ll p[19];
ll util(ll x)
{
    if (x <= 9)
        return x;
    ll ans = 9;
    for (int i = 1; i <= 18; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (x / p[i] > j)
            {
                ans += p[i - 1];
            }
            else if (x / p[i] == j)
            {
                debug(p[i]);
                debug(j);
                // bhak sala
                ans += (x % p[i]) / 10;
                debug(ans);
                if (x % 10 >= j)
                    ans++;
            }
        }
    }
    // 4103 1000
    // 4000 01 02 .. . 09 10 11
    return ans;
}
void solve()
{
    p[0] = 1;
    ll a, b;
    cin >> a >> b;

    // generate 10^x values
    for (int i = 1; i <= 19; ++i)
    {
        p[i] = p[i - 1] * 10ll;
    }
    // util(x) gives ans upto x

    cout << util(b) - util(a - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
