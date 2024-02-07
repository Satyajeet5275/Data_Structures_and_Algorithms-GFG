#include<bits/stdc++.h>
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pf(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define dbe(x) cout << #x << "=" << x << endl
#define dbe2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define rb pop_back;
#define F first
#define S second
#define nl cout<<endl;
#define out(x) cout<< x << endl;
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sz(x) ((ll)(x).size())
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

typedef long long int  ll;
typedef pair<ll, ll>	 pl;
typedef vector<ll>		 vl;
typedef vector<vl>		vvl;
typedef map<char,ll>	mcl;
typedef map<ll,ll>    mll;
typedef set<ll>        sl;

template <class T>
void outArr(vector<T> &v) { for (auto x : v) cout << x << " "; cout <<endl; }

template <class T>
void inArr(ll n, vector<T> &arr) { T x; for (ll i=0;i < n; i++) { cin >> x; arr.push_back(x); } }


ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool isPrime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int mpow(int base, int exp);
bool isSorted(ll n, vector<ll> &arr);
ll sumArr(ll n, vector<ll> &arr);
bool isVowel(char c);
bool checkBit(ll a, ll i);
ll countSetBits(ll a);

/*===========================================================================================================================*/

void solve() {
    
    
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}


ll sumArr(ll n, vector<ll> &arr) {
	ll ans = 0;
	for(ll i = 0; i < n; i++) ans += arr[i];
	return ans;
}

int mpow(int base, int exp) {
  base %= MOD;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % MOD;
    base = ((ll)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

bool isVowel(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
	return false;
}

bool isSorted(ll n, vector<ll> &arr) {
	for(ll i = 1; i < n; i++) {
		if(arr[i] < arr[i - 1]) return false;
	}
	return true;
}

bool checkBit(ll a, ll i){
    if((a&(1<<i))!=0) return true;
    return false;
}

ll countSetBits(ll a){
  ll ans=0;
  while(a){
    a=a&(a-1);
    ans++;
  }
  return ans;
}
