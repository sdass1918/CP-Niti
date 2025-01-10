# Bit Manipulation and Everything about bits and binary number system

## INDEXING
*Index:* 7 6 5 4 3 2 1 0 -> **The indexing starts from right to left**  
*Bits:*&nbsp;&nbsp;&nbsp;1 1 1 1 1 0 0 0  

## MSB and LSB
- **LSB(Least siginificant bit):** The 0th bit is known as the least significant bit.
- **MSB(Most significant bit):** The (n-1)th bit is known as the most significant bit. 

## PATTERNS
- **Pattern 1:**<br>
1 0 -> 2<sup>1</sup><br>
1 0 0 -> 2<sup>2</sup><br>
1 0 0 0 -> 2<sup>3</sup><br>
.<br>
.<br>
.<br>
.<br>
1 0 0 0 . . . .(0 comes n times) -> 2<sup>n</sup><br><br>
- **Pattern 2:**<br>
1 -> 1<br>
1 1 -> 3<br>
1 1 1 -> 7<br>
.<br>
.<br>
.<br>
.<br>
1 1 1 . . . .(n times) -> 2<sup>n</sup>-1<br><br>
- **Pattern 3:**<br>
All the odd numbers end with 1 in their binary representation and all the even numbers end with 0.<br>

## LEFT-SHIFT
**Power of 2:**<br>
1 &lt;&lt; n -> 2<sup>n</sup> => *It will make the nth bit set and all the other bits will remain unset.*<br>

## TECHNIQUES
- **To check whether a given bit is set or not:**<br>
We will take **and** operator between the given binary number and 1 &lt;&lt; i.<br>
**Example:**<br>
1 1 1 0 1 0 -> *to check whether the first index bit is set or not*<br>
0 0 0 0 1 0 -> *we will take this binary number with the 1st index as 1 and the rest as 0*<br>
*Now taking and (&) operator -> (1 1 1 0 1 0) & (0 0 0 0 1 0) => if it comes non zero then the bit is set otherwise unset.*<br><br>
- **To set a bit in the binary number:**<br>
We will use the **or** operator with the given binary number and 1 &lt;&lt; i.<br><br>
- **To reverse the given binary number:**<br>
we use tilda operator -> **~**<br>
**Example:**<br>
~(0 0 0 0 1) -> 1 1 1 1 0<br><br>
- **To unset a bit in the given binary number system:**<br>
we take the **and** operator with the given binary number and ~(1 &lt;&lt; i)<br><br>
- **To toggle a bit:**<br>
we take **xor** operator between the given binary number and 1 &lt;&lt; i.<br><br>
- **To count the number of set bits:**<br>
	- We can use the built-in function from the c++ stl: **__builtin_popcount(num)**<br>
	- For the long long integers we can use another built-in function: **__builtin_popcountll(num)**<br>
	- We can also use the for loop for the 32 based integer system that is we can run a loop from i=31 to i=0 and we can take the and operator between num and (1 &lt;&lt; i) and if it comes out to be a non-zero number then we will just increase the value of cnt.<br><br>
- **To multiply or divide a number by 2:**<br>
	- To get the quotient after dividing the number by 2: n >> 1<br>
	- To get the product we do use the left shift operator: n &lt;&lt; 1<br><br>
- **To change the case of the alphabets:**<br>
The binary representation of all the lower case letters has the **fifth bit** set but in case of upper case letters the fifth bit is unset.<br>
**Example:**<br>
	- *To change the alphabet to lower case:* We take the **or** opeartor with the alphabet and (1 &lt;&lt; 5). This is to set the 5th bit. **(1 &lt;&lt; 5) -> ' '**<br>
	- *To change the alphabet to upper case:* We take the **and** opearator with the alphabet and reverse or ~(1 &lt;&lt; 5). This is to unset the 5th bit. **~(1 &lt;&lt; 5) -> '_'**<br><br>
- **To remove the LSB till a given index:**<br>
**Given Binary:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 0 0 0 0 1 1 1 0 1 0 1<br>
**We want to make it as:**   0 0 0 0 1 1 0 0 0 0 0 -> *we want to clear the LSB till index 4*<br>
**Method:**<br> 
	- If we take (0 0 0 0 1 1 1 0 1 0 1) 'and' (1 1 1 1 1 1 0 0 0 0 0) then we will get (0 0 0 0 1 1 0 0 0 0 0)<br>
	- To get (1 1 1 1 1 1 0 0 0 0 0) we can use the tilda operator to reverse (0 0 0 0 0 0 1 1 1 1 1)<br>
	- To get (0 0 0 0 0 0 1 1 1 1 1) we can subtract 1 from (0 0 0 0 0 1 0 0 0 0 0) or 1<<5<br><br>
- **To remove the MSB till a given index:**<br>
**Given Binary:**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 0 0 0 0 1 1 1 0 1 0 1<br>
**We want to make it as:**   0 0 0 0 0 0 0 0 1 0 1 -> *we want to clear the MSB till index 4(inclusive)*<br>
**Method:** If we take the 'and' operator with the given binary and (0 0 0 0 0 0 1 1 1 1 1)<br><br>
- **To check whether a number is a power of 2 or not:**<br>
We take **and** operator between n and n-1.<br>

## XOR PROPERTIES
- a ^ a = 0 and a ^ 0 = a<br><br>
- **To swap two numbers:**<br>
a = a ^ b<br>
b = b ^ a -> b = (a^b) ^ b => b = a ^ (b^b) => b = a ^ 0 => b = a<br>
a = a ^ b -> a = (a^b) ^ a => a = (a^a) ^ b => a = 0 ^ b => a = b<br><br>
- **To eliminate the duplicates from the array:**<br>
We can eliminate the duplicates from the array simply by using xor in O(n) time and using O(1) time.<br>
**Example:**  If we are given an array with n even numbers where n-1 even numbers have even counts and only one even nmber has an odd count. Then find that one even number in O(n) time and using O(1) space.<br>
**Solution:** We can solve this question simply by taking xor of all the elements as the elements with even count will become 0 and the element with odd count is printed at last.<br>

## BITMASKING
When we represent some numbers using bits then it is known as bit masking. We can use bitmasking in several problems where the sample size is less so that the time complexity dereases. One of the applications include **generation of subsets**.<br>

---
