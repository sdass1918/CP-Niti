# Binary Exponentiation

## WHY?
To calculate the power of an integer in coding world we generally use the builtin function of pow(a,b) in c++. But the problem arises because the pow() function returns the result in double data type and as we know that the double data type can store large data but the precesion is very low. Thus to solve the problem of overflow and precesion we use binary exponentiation.<br><br>
## IMPLEMENTATION
We imlement this binary exponentiation using the **divide and conquer** algorithm where we divide the given problem into smaller parts and then at last combine all the results to get the final one.<br><br>
**Example:**

* If we want to calculate the value of 2<sup>16</sup> (*16 is an even number*) then we will divide it as follows:<br>
2<sup>16</sup> = 2<sup>8</sup> * 2<sup>8</sup><br>
2<sup>8</sup> = 2<sup>4</sup> * 2<sup>4</sup><br>
2<sup>4</sup> = 2<sup>2</sup> * 2<sup>2</sup><br>
2<sup>2</sup> = 2<sup>1</sup> * 2<sup>1</sup><br>
2<sup>1</sup> = 2 * 2<sup>0</sup><br>
Now if we would have tried to solve the above problem using simple method using the loops then it would have taken O(n) time complexity where n is the power or the exponent. But if we use this divide and conquer algorithm then this would become possible in just O(lg n) time complexity.<br><br>
* If we want to cslculate the value of 3<sup>13</sup> (*13 is an odd number*) then we will have to write it in another way as follows:<br>
3<sup>13</sup> = 3 * 3<sup>12</sup><br>
3<sup>12</sup> = 3<sup>6</sup> * 3<sup>6</sup><br>
3<sup>6</sup> = 3<sup>3</sup> * 3<sup>3</sup><br>
3<sup>3</sup> = 3 * 3<sup>2</sup><br>
3<sup>2</sup> = 3<sup>1</sup> * 3<sup>1</sup><br>
3<sup>1</sup> = 3 * 3<sup>0</sup><br><br>
## RECURSIVE
If we try to implement the solution using recursion then we will divide the function f(a,b) into f(a,b/2) where f(a,b) = a<sup>b</sup> and we go on untill the value of b becomes 0.<br><br>
**Code:**
<pre>
int RecursiveBinaryExponentiation(int a, int b)
{
	if(b==0)
	{
		return 1;
	}
	int res = RecursiveBinaryExponentiation(a, b/2);
	if(a&1)
	{
		return a * res * res;
	}else
	{
		return res * res;
	}
}</pre><br>
## ITERATIVE
Iterative way is generally faster and more efficient than the recursive method and we should always prefer the iterative way over the recursive one.<br><br>
**Method:**<br>
If we have been given to calculate the value of a<sup>b</sup> then we will write the binary representation of b and then we will keep on incrementing the value of a and right shift b by 1 to know if the bit is set or not. As the number of bits in b would be O(lg b) so the time complexity for this method is also **O(lg b)**.<br><br>
**Example**<br>
Let's calculate the value of 3<sup>13</sup> then: <br>
3<sup>13</sup> = 3<sup>(1 1 0 1)</sup><br>
<table>
  <tr>
    <th>a</th>
    <th>b</th>
    <th>ans (<I>Default value = 1</I>)</th>
  </tr>
  <tr>
    <td>3</td>
    <td>1 1 0 1</td>
    <td>3</td>
  </tr>
  <tr>
    <td>3<sup>2</sup></td>
    <td>1 1 0</td>
    <td>3</td>
  </tr>
  <tr>
    <td>3<sup>4</sup></td>
    <td>1 1</td>
    <td>3<sup>5</sup></td>
  </tr>
  <tr>
    <td>3<sup>8</sup></td>
    <td>1</td>
    <td>3<sup>13</sup></td>
  </tr>
</table><br>
<b>Code:</b>
<pre>
int IterativeBinaryExponentiation(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b&1)
		{
			ans = ans * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}
</pre>
<hr>
