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

//for prime factorisation
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

//To check whether the bit is set or not
bool setOrUnset_bit(int num, int idx)
{
    if((num & (1<<idx)) != 0)
    {
        return true; //the bit is set
    }else
    {
        return false; // the bit is unset
    }
}

//To set the given bit in a binary number
void setBit(int num, int idx)
{
    printBinary(num | (1<<idx));
}

//To unset the given bit in a binary number
void unsetBit(int num, int idx)
{
    printBinary(num & (~(1<<idx)));
}

//To toggle the bit of the given binary number
void toggleBit(int num, int idx)
{
    printBinary(num ^ (1<<idx));
}

//To count the number of set bits
int countSet_bits(int num)
{
    int cnt = 0;
    for(int i=31; i>=0; --i)
    {
        if((num & (1<<i))!=0)
        {
            cnt++;
        }
    }
    return cnt;
}

//To check whether a number is even or odd using bit manipulation
bool isEven(int num)
{
    if(num&1)
    {
        return false;
    }else
    {
        return true;
    }
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

//to check the power of 2
bool power_of_2(int num)
{
    if(num & (num-1))
    {
        return false;
    }else
    {
        return true;
    }
}

//to swap two numbers
void swapNumbers(int n1, int n2)
{
    n1 = n1 ^ n2;
    n2 = n2 ^ n1; //assigns n1 to n2

    n1 = n1 ^ n2; //assigns n2 to n1
}









/* BIT MANIPULATION 

*******************************************************************************************************************

//Bit index
7 6 5 4 3 2 1 0 -> From right to left
1 1 1 1 1 0 0 0 -> Least significant bit(LSB): 0th index bit and MSB: (n-1)th index bit 

//Pattern 1
1 0 -> 2^1
1 0 0 -> 2^2
1 0 0 0 -> 2^3
.
.
.
1 0 0 0 ....(n times) -> 2^n

//Pattern 2
1 -> 1
1 1 -> 3
1 1 1 -> 7
.
.
.
1 1 1 1 ......(n-1 times) -> 2^n - 1

//Pattern 3
The binary representation of all odd numbers end with 1 and it happens otherwise in case of even

//Left-shift concept
1<<n -> 2^n

//Set-bit -> 1
//unset-bit -> 0

//To check whether a given indexed bit is set or not
1 1 1 0 1 0 -> to check whether the first index bit is set or not
0 0 0 0 1 0 -> we will take this binary number with the 1st index as 1 and the rest as 0
Now taking and & operator -> (1 1 1 0 1 0) & (0 0 0 0 1 0) => if it comes non zero then the bit is set otherwise unset
0 0 0 0 1 0 -> 1<<1 

//To set a bit in the binary number
we take the or operator with the given binary number and 1<<i

//To reverse the given binary number
we use tilda operator -> ~
~(0 0 0 0 1) -> 1 1 1 1 0 

//To unset a bit in the binary number
we take the and operator with the given binary number and ~(1<<i)

//To toggle a bit
we take xor operator

//To count the number of set bits 
We have an inbuilt function -> __builtin_popcount(num);
For long long we use -> __builtin_popcountll(num);

//To multiply and divide by 2 using bit manipulation
Actually % and / are considered to be slower than the bit operations, so we use the bit manipulation techniques to perform the tasks in lesser time
n>>1 --> It will give us the quotient after dividing num by 2
n<<1 --> It will give us the product after multiplying num by 2

//To change the case of an alphabet using bit manipulation
The binary representation of all the lower case letters has the fifth bit set but in case 
of upper case letters the fifth bit is unset. So the function to change the case is given above.

//To remove the LSB till a given index
Given Binary:            0 0 0 0 1 1 1 0 1 0 1
We want to make it as:   0 0 0 0 1 1 0 0 0 0 0 -> we want to clear the LSB till index 4
METHOD: If we take (0 0 0 0 1 1 1 0 1 0 1) 'and' (1 1 1 1 1 1 0 0 0 0 0) then we will get (0 0 0 0 1 1 0 0 0 0 0)
        To get (1 1 1 1 1 1 0 0 0 0 0) we can use the tilda operator to reverse (0 0 0 0 0 0 1 1 1 1 1)
        To get (0 0 0 0 0 0 1 1 1 1 1) we can subtract 1 from (0 0 0 0 0 1 0 0 0 0 0) or 1<<5

//To clear the MSB till a given index
Given Binary:             0 0 0 0 1 1 1 0 1 0 1
We want to make it as:    0 0 0 0 0 0 0 0 1 0 1 -> we want to clear the MSB till the index 4(inclusive)
METHOD: If we take the 'and' operator with the given binary and (0 0 0 0 0 0 1 1 1 1 1)

//To check whether a number is a power of 2 or not
if we take and operator with n and n-1 and we get 0 then it is power of 2

//XOR properties
a ^ a = 0 and a ^ 0 = a
We can use these properties to swap two numbers and als to eliminate the duplicates in an array in constant space and O(n) time.
eg:  If we are given an array with n even numbers where n-1 even numbers have even counts and only one even nmber has an odd count.
     Then find that one even number in O(n) time and using O(1) space.
Sol: We can solve this question simply by taking xor of all the elements as the elements with even count will become 0
     and the element with odd count is printed at last.

*******************************************************************************************************************
*/










/* SOLVE THE PROBLEM */
void solve(int tc)
{
    int a = 7;
    printBinary(a);
    if(setOrUnset_bit(a,4))
        cout<<"set"<<endl;
    else
        cout<<"unset"<<endl;
    cout<<countSet_bits(a)<<endl;
    setBit(a, 5);
    toggleBit(a, 4);
    cout<<isEven(3)<<endl;

    printBinary('A');
    printBinary('b');

    cout<<change_to_lower_case('A')<<endl;
    cout<<change_to_upper_case('b')<<endl;  

    int z = 101;
    printBinary(z);

    int y = z & (~((1<<5) - 1));  
    printBinary(y);
    cout<<y<<endl;

    cout<<power_of_2(3)<<endl;

    int c = 2;
    int b = 3;
    c = c ^ b;
    b = b ^ c;
    c = c ^ b;
    cout<<c<<b<<endl;
  
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