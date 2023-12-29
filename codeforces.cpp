#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace chrono;
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define N 1000001
#define ll long long
#define lld long double
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PI 3.141592653589793238462
#define sqrt sqrtl
#define print(vctr) for(auto it:vctr){cout<<it<<" ";}cout<<endl;
#define input(vctr,n) for(ll i=(ll)0;i<(ll)n;i++){ll inp;cin>>inp;vctr.push_back(inp);}
#define sort(vctr) sort(vctr.begin(),vctr.end());
#define rev(vctr) reverse(vctr.begin(),vctr.end());
#define vsum(vctr) accumulate(vctr.begin(),vctr.end(),(ll)0)
#define maxv(v) *max_element(v.begin(),v.end())
#define minv(v) *min_element(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define count_set_bits __builtin_popcountll
#define ff first
#define ss second
#define endl '\n'
#define debug(x) cout<<#x<<" "<<x<<endl;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;

//--------------Modulo Addition Multiplication Subtraction--------//

ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll mod_sub(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD;}

//----------------Power------------------------//

ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a;
    ll temp=POW(a,b/2);
    if(b%2==0) return ((temp%MOD)*(temp%MOD))%MOD;
    else return ((((temp%MOD)*(temp%MOD))%MOD)*a)%MOD;
}

//-----------------lcm-----------------------------//

ll lcm(ll a,ll b){
    ll x=__gcd(a,b);
    return ((a*b)/x);
}

//-----------------Inverse-------------------------//

ll inv(ll i) 
{
    if (i == 1) return 1; 
    return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;
}

//---------------------Factorial-----------------------//

ll *fact;
void calFact() {
    fact=new ll[N];
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<N; i++) fact[i] = mod_mul(fact[i-1], i);
}
 
//-----------------------------ncr--------------------------//
 
ll ncr(ll n, ll r) {
    if(n<r){
        return 0;
    }
    ll ans = fact[n];
    ans = mod_mul(ans, inv(fact[n-r]));
    ans = mod_mul(ans, inv(fact[r]));
    return ans;
}

//-----------------------Sieve-------------------------//

bool* prime;
void sieve(){
    prime = new bool[N];
    for(ll i=0; i<N; i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    for(ll i=2; i<N; i++)
    {
        if(prime[i]){
            for(ll j=i*i; j<N; j+=i){
                prime[j]=false;
            }
        }
    }
}

//---------------------Palindrome Checker--------------//

bool isPal(string& s){
    ll i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// -----------------------------------kmp--------------------//

vector<ll> pre_kmp(string pattern)
{
	ll size = pattern.size();
	vector<ll> pie(size,0);
	pie[0] = 0;
	ll k=0;
	for(int i=1;i<size;i++)
	{
		while(k>0 && pattern[k] != pattern[i] )
		{
			k=pie[k-1];
		}
		if( pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		pie[i]=k;
	}
	
	return pie;
}

void kmp(string text,string pattern)
{
	vector<ll> pie=pre_kmp(pattern);
	ll matched_pos=0;
	for(ll current=0; current< (ll)text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (ll)(pattern.length()) )
		{
			cout<<"Pattern occurs with shift "<< current - (pattern.length() -1 );
			matched_pos = pie[matched_pos-1];
		}
	}
}

//-----------------------------MEX--------------------------//

ll findMex(vector<ll>& v){
    set<ll> s;
    for(auto it:v){
        s.insert(it);
    }
    ll j=0;
    for(auto it:s){
        if(it!=j){
            return j;
        }
        j++;
    }
    return j;
}

//--------------------------is Kth Bit set-------------------------//
 
bool isKthBitSet(ll n, ll k)
{
    if (n & (1LL << k))
        return true;
    return false;
}

//------------------------Decimal to Binary------------------------//

string to_binary(ll num) 
{ 
    string str; 
      while(num){ 
      if(num & 1) // 1 
        str+='1'; 
      else // 0 
        str+='0'; 
      num>>=1;   
    }     
      return str; 
} 

//---------------------------Comparator------------------//

// class cmp1 {
// public:
//     bool operator()(const pair<ll,ll>& a,const pair<ll,ll>& b)
//     {
//         return (a.ff>b.ff);
//     }
// };

//----------------Solve----------------------------//

ll *preCal;
void pre(ll n){
    preCal = new ll[n];
    
}
void solve(){ 
    
}

 
int main()
{
    ll q;
    q=1;
    cin>>q;
    // calFact();
    // calTwoPower
    // sieve();
    // pre(300001);
    cout<<fixed;
    cout<<setprecision(16);
    while(q){
        solve();
        q--;
    }
    return 0;
}
// :)