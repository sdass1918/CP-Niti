# Binary Multiplication


## WHY?
In case when the value of a increases beyond the long long int scope while calculating the binary exponentiation of a<sup>b</sup> even after we use the **%M** where M is also increased to the value of **10<sup>18</sup>** to hold greater values because if we take the value of a as **long long int** that varies till 10<sup>18</sup> then even when we take the modulo the value of **a%M** might come out to be 10<sup>18</sup> which will then resist the program from calculating the value of a x a as it will go beyond the limit of long long. So in this case there comes **binary multiplication for the large exponentiations**.<br>
The iterative method of binary exponentiation involves multiplying a with itself and then taking the modulo *( (a x a)%M )* so if the size of **a x a** increases and go beyond the limit then there is no further execution and the code comes to halt.<br><br>
## IMPLEMENTATION
We will be using the divide and conquer algorithm again to calculate the product of two large numbers without any halt following the process of binary multiplication. But at first let us look at a simle approach to implement the solution using the divide and conquer algorithm.<br>

- **Brute-force Algorithm:**<br>
If we are trying to multiply let's say a x b then it breaks down to summing up a b times like (a + a + a + . . . .b times) and taking modulo at each step. This is a simple approach which will get executed without any halt and problem as a + a may vary till 2 x 10<sup>18</sup>, long long int can hold this data and when we take the modulo that is (a+a)%M then it again gets reduced and becomes ready for the next step. The problem arises with the time complexity which is O(b), so can we reduce it to O(log b) or something.<br>

- **Binary Multiplication:**<br>
Let us take the example of 3 x 13 then we have the binary representation of 13 as 1 1 0 1, where we will again look for the set bits and will be right shifting b by 1 and incrementing the value of a by a at each step.<br>
3 x 13 = 3 x (1 1 0 1)<br>
3 x 13 = 3 x (8 + 4 + 0 + 1) -> Writing 13 into powers of 2<br>
<table>
	<tr>
		<th>a</th>
		<th>b</th>
		<th>ans (Default value is 0)</th>
	</tr>
	<tr>
		<td>3</td>
		<td>1 1 0 1</td>
		<td>3</td>
	</tr>
	<tr>
		<td>6</td>
		<td>1 1 0</td>
		<td>3</td>
	</tr>
	<tr>
		<td>12</td>
		<td>1 1</td>
		<td>15</td>
	</tr>
	<tr>
		<td>24</td>
		<td>1</td>
		<td>39</td>
	</tr>
</table>
This takes O(lg b) time complexity as there can be lg b bits in the binary representation of b.<br>

<b>Code:</b>
<pre>
	const long long M = 1e18+7;
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
</pre>
<hr>