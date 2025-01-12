#include <bits/stdc++.h>
using namespace std;

class Functions
{
public:
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

    long long IterativeBinaryExponentiation(long long a, long long b)
    {
    	long long ans = 1;
    	while(b)
    	{
    		if(b&1)
    		{
    			ans = binaryMultiply(ans, a);
    		}
    		a = binaryMultiply(a, a);
    		b >>= 1;
    	}
    	return ans;
    }
    long long binaryMultiply(long long a, long long b)
	{
		long long ans = 0;
		while(b)
		{
			if(b&1)
			{
				ans = (ans + a)%M;
			}
			b >>= 1;
			a = (a + a)%M;
		}
		return ans;
	}
};
