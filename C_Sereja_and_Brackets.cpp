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
const int N = 1e6 + 5;
vector<int> t(3 * N), o(3 * N), c(3 * N);
string s;
int n;
typedef pair<int, int> pii;
typedef pair<int, pii> cpii;
cpii getQueries(int x, int y, int l = 0, int r = n, int node = 1)
{
    // debug(x);
    // debug(y);
    if (x >= r || y <= l)
        return {0, {0, 0}};
    if (x <= l && y >= r)
        return {t[node], {o[node], c[node]}};
    int mid = (l + r) / 2;
    auto a1 = getQueries(x, y, l, mid, 2 * node);
    auto a2 = getQueries(x, y, mid, r, 2 * node + 1);
    int tmp = min(a1.ss.ff, a2.ss.ss);
    int T = a1.ff + a2.ff + tmp;
    int O = a1.ss.ff + a2.ss.ff - tmp;
    int C = a1.ss.ss + a2.ss.ss - tmp;
    return {T, {O, C}};
}
void buildTree(int lo = 0, int hi = n, int node = 1)
{
    if (hi - lo < 2)
    {
        if (s[lo] == '(')
            o[node] = 1;
        else
            c[node] = 1;
        return;
    }

    int mid = (lo + hi) / 2;
    buildTree(lo, mid, 2 * node);
    buildTree(mid, hi, 2 * node + 1);
    int tmp = min(o[node * 2], c[node * 2 + 1]);
    t[node] = t[node * 2] + t[node * 2 + 1] + tmp;
    o[node] = o[node * 2] + o[2 * node + 1] - tmp;
    c[node] = c[node * 2] + c[node * 2 + 1] - tmp;
}
void solve()
{
    cin >> s;
    n = sz(s);
    int q;
    cin >> q;
    buildTree();
    //build();

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        auto p = getQueries(l, r);
        int ans = p.ff;
        debug(q);
        debug(p.ff);
        debug(p.ss.ff);
        debug(p.ss.ss)
                cout
            << ans * 2 << '\n';
    }
}
int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
