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
// if greedy doesnt make sense use dp
// think of complements of answers 
// find max places that can be saved upto index i
// answers is n- max(dp[i]), 0<=i<n
ll dp[N];
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), pwr(n), occ(N);
    map<ll, ll> pwi, idx;
    rep(i, n)
    {
        cin >> a[i] >> pwr[i];
        occ[a[i]] = 1;
        idx[a[i]] = i;
        pwi[i] = pwr[i];
    }
    for (int i = 0; i < N; ++i)
    {
        if (!occ[i])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = 1;
            int id = idx[i];
            int p = pwi[id];
            if (i - p - 1 >= 0)
                dp[i] = max(dp[i], dp[i - (p + 1)] + 1);
        }
    }
    ll ans = -inf;
    for (int i = 0; i < n; ++i)
    {
        debug(dp[a[i]]);
        ans = max(ans, dp[a[i]]);
    }
    cout << n - ans << '\n';
}

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
 
// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;
 
    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;
 
            do {
                n /= p;
                exponent++;
            } while (n % p == 0);
 
            result.emplace_back(p, exponent);
        }
 
        return result;
    }
 
    for (int64_t p : primes) {
        if (p * p > n)
            break;
 
        if (n % p == 0) {
            result.emplace_back(p, 0);
 
            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }
 
    if (n > 1)
        result.emplace_back(n, 1);
 
    return result;
}
 
 
int canonicalize(int a) {
    vector<pair<int64_t, int>> prime_factors = prime_factorize(a);
    int product = 1;
 
    for (auto &pf : prime_factors)
        if (pf.second % 2 != 0)
            product *= int(pf.first);
 
    return product;
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
