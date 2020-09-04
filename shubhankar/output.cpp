#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mp  make_pair
#define mod 1000000007
#define ll long long int
#define ld long double
const int N=1e5+5;ll dp[200001];ll mx=INT_MAX;ll mn=INT_MIN;bool prime[10000001]; 
void Sieve() 
{  memset(prime, true, sizeof(prime));prime[0]=false;prime[1]=false;
    for (ll p=2; p*p<=10000000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=10000000; i += p) 
                prime[i] = false; 
        } } }
bool checkPrime(ll num) {  return prime[num]; }
bool is_prime2(ll n) {
    if (n == 1)return false;
    ll i = 2;// This will loop from 2 to int(sqrt(x))
    while (i*i <= n) { // Check if i divides x without leaving a remainder
        if (n % i == 0) { // This means that n has a factor in between 2 and sqrt(n)  So it is not a prime number
            return false;
        }
        i += 1;} // If we did not find any factor in the above loop,then n is a prime number
    return true;}
bool powerofFour(unsigned int n)//check a number is power of 4 or not
{  return (n!=0 &&  (n&(n-1) == 0) && !(n & 0xAAAAAAAA)); }
bool isPowerOfTwo(ll n) //Check a number is power of 2
{  if(n==0) 
        return false; 
   return (ceil(log2(n)) == floor(log2(n))); }
bool isPowerOFThree(ll n) {  return (1162261467%n==0); }
vector<ll> printDivisors(ll n) 
{ // Note that this loop runs till square root 
    vector<ll>v;
    for (ll i=1; i<=sqrt(n); i++) 
    {  if (n%i == 0) { 
            if (n/i == i) 
                v.push_back(i); 
              else // Otherwise print both 
                {  v.push_back(i);v.push_back(n/i);
                }} 
    } return v;}
ll divSum(ll num) //Efficient approach to sum of divisors of num
{ 
    ll result = 0; 
    for (ll i=2; i<=sqrt(num); i++) 
    { if (num%i==0) 
        {   if (i==(num/i)) 
                result += i; 
            else
                result += (i + num/i); 
        }  } 
    return (result + 1 + num); 
}
ll gcd(ll a , ll b)// Euclidean Algorithm
{
if(b == 0) return a;
else return gcd(b,a%b);
}
ll lcm(ll a,ll b){ return ((a*b)/(gcd(a,b)));  }
ll floorsquareroot(ll x){//Floor(sqrt(x)) algorithn in O(logn time)
    if(x==0||x==1)return x;
    ll st =1;ll en = x;ll ans;
    while(st<=en){
        ll mid = (st+en)/2;
        if(mid*mid==x)return mid;
        if(mid*mid<x){
            st = mid+1;ans = mid;
        }
        else{
            en = mid-1;
        }
    }return ans;
}
ll phi(ll x) {
  ll ans = x;
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans = ans / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ans = ans / x * (x - 1);
  return ans;
}
ll countDigits22(ll n ){  return floor(log10(n))+1; }
ll power(ll a , ll n)// Fast Exponentiation Algorithm
{   ll ans = 1;
     a = a%mod;
     if(a==0)return 0;
    while(n>=1)
    {
        if(n&1)
            ans = (ans*a)%mod;
        n = n>>1;
        a = (a*a)%mod;;
    }return ans;
}
bool isPerfectSquare(ll x)// a number is perfect square or not
{ ll s = sqrt(x);return (s*s == x);}
bool isfibonaaci(ll x)//Check a number is fibonacci number or not
{return (isPerfectSquare(5*x*x+4)||isPerfectSquare(5*x*x-4));}
bool sortbysec(const pair<string,ll> &a,const pair<string,ll> &b) // sorting the pairs on the basics of second value
{ return (a.second < b.second); }
ll modExp(ll a, ll b, ll c) {
	a %= c;
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1){
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;}
	return ans;}
ll ncr(ll n, ll r) { ll p=mod;
	return dp[n] * modExp(dp[n - r] * dp[r] % p, p - 2, p) % p;}
bool is_semiprime(ll p)
{  ll j;
    for(j=2;j<=sqrt(p);j++)
    {  if(is_prime2(j))
        {   if(p%j==0)
            {   if(is_prime2(p/j))
                {
                    if(j!=p/j)
                    return true;
                }}}}
    return false;}
bool allbitsSet(ll n)
{ if((n&(n+1)) == 0)return true;
    else return false;}
ll maxSubArraySum(ll a[], ll size) //Kadane Algorithm For maximun subarray sum.
{ 
   ll max_so_far = a[0]; ll curr_max = a[0]; 
   for (ll i = 1; i < size; i++) 
   { curr_max = max(a[i], curr_max+a[i]); max_so_far = max(max_so_far, curr_max);} 
   return max_so_far; } 
ll trailingZerosFact(ll n)// Trailing zeroes in a factorial
{ ll c =0;
    while(n!=0)
    { c += n/5;n /= 5; }
    return c;}
ll palin(ll n)
{ ll t = n;ll s =0;
    while(n)
    {   ll d = n;s = s*10+d;n /=10;}
    return (t==s);}
vector<ll> efficiprimefactorisation(ll x)
{ vector<ll>v;
     while(x%2==0)
        {  v.push_back(2);
            x=x/2;}
        for(ll j=3;j<=sqrt(x);j=j+2)
        { while(x%j==0)
            {  v.push_back(j);
                x=x/j;
            } }
        if(x>2){ v.push_back(x);} 
        return v;}
ll multiplyb_y_35_x(ll x) { return ((x<<1)+x+(x>>1));}
ll num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 }; 
unsigned int countSetBits(unsigned int num) 
{ 
    int nibble = 0; 
    if (0 == num) 
        return num_to_bits[0]; 
    nibble = num & 0xf; 
    return num_to_bits[nibble] + countSetBits(num >> 4); 
} 
ll sumOfN(ll n){
    return n%2==0 ? n/2 * (n+1) : (n+1)/2 * n;}
ll countZeros(ll n)//Count zeroes in the number
{ ll c = 0;
    while(n!=0)
    {   if((n) == 0)c++; n /= 10;} return c;}
bool canBeSumofConsec(unsigned int n) { return ((n&(n-1)) && n);}
ll grayCode(ll n){ return (n^(n>>1)); }
ll countDigits(ll n){ll count_digits = 0;ll x = n; 
    while(x) { x = x/10;count_digits++; } 
    return count_digits;}
int main()
{  
fastio;
//Start Code
ll t;cin>>t;
while(t--)
{
ll n;cin>>n;
vector<ll>a(n);ll sum=0;
for(ll i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
if(sum%n==0)
cout<<"Yes"<<"\n";
else
cout<<"No"<<"\n";













}
return 0;
//End Code..
}



