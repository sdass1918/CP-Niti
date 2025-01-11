#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/* MACROS */
#define int long long
#define float double
#define PI 3.1416
#define AREA(r) (r * r * PI)


/* OPERATOR OVERLOADS */

template<typename T> //for taking inputs in vector
istream& operator>>(istream &istream, vector<T> &v)
{
    for(auto &it:v)
    {
        cin>>it;
    }
    return istream;
}

template<typename T1, typename T2>//for taking inputs as pairs
istream& operator>>(istream &istream, pair<T1,T2> &p)
{
    return (istream >> p.first >> p.second);
}

template<typename T> //for giving output in vectors
ostream& operator<<(ostream &ostream, const vector<T> &v)
{
    for(auto &it:v)
    {
        cout<<it<<" ";
    }
    return ostream;
}

template<typename T1, typename T2> //for giving outputs in pair
ostream& operator<<(ostream &ostream, const pair<T1,T2> &p)
{
    return(ostream << p.first << " " << p.second);
}



/* UTILITY FUNCTIONS */

//for determining whether the number is a prime or not
bool SieveOfEratosthenes(int k)
{
    
    vector<bool> prime(k + 1, true);

  for (int p = 2; p * p <= k; p++) {


        
        if (prime[p] == true) {
            for (int i = p * p; i <= k; i += p)
                prime[i] = false;
        }
    }

    if(prime[k]) return true;
    else return false;
}

//For prime factorisation
vector<int> primeFactorization(int n) {
    vector<int> ans;
    vector<int> spf(n + 1); // Smallest Prime Factor array
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) { // i is prime
            spf[i] = i;
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
    
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}


//for prefix sum
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}


//for calculating GCD
int GCD(int a, int b)
{
    while(b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

//for calculating the LCM
int LCM(int a, int b)
{
    return((ll)a*b) / GCD(a,b);
}

//for determining whether the given number is an integer or not
bool isInteger(float x) {
    return std::floor(x) == x;
}

//factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

//Printing the binary form of the given number
void printBinary(int num)
{
    for(int i=10; i>=0; --i)
    {
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

//To change the case to lower case
char change_to_lower_case(char ch)
{
    return (ch | (1<<5)); // we can also use ' '
}

//To change the case to uppercase
char change_to_upper_case(char ch)
{
    return (ch & (~(1<<5))); // we can also use '_'
}
























/* SOLVE THE PROBLEM */
void solve(int tc)
{
    
}















int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<< setprecision(12) << fixed;

    int tests = 1;
    cin>>tests;
    for(int tt=1; tt<=tests; tt++)
    {
        solve(tt);
    }
    return 0;
}
