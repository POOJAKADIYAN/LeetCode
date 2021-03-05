<!-- - **Merge sort** gives **O(n logn)** complexity for all the cases, unlike **quick sort** which performs poorly in worst case i.e, **O(n^2)**.

## **1 - MAXIMUM SUM IN CONTIGUOUS SUBARRAY**

Given an array **arr** of **N** integers. Find the contiguous sub-array with maximum sum.

**Input:**The first line of input contains an integer **T** denoting the number of test cases. The description of **T** test cases follows. The first line of each test case contains a single integer **N** denoting the size of array. The second line contains **N** space-separated integers **A1, A2, ..., AN** denoting the elements of the array**.**

**Output:**Print the maximum sum of the contiguous sub-array in a separate line for each test case.

**Constraints:**1 ≤ T ≤ 110 1 ≤ N ≤ 10^6 10^7 ≤ A[i] <= 10^7

**Example:Input**2 5 1 2 3 -2 5 4 -1 -2 -3 -4 **Output**9 -1

**Explanation:Testcase 1:** Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

## **SOLUTION -**

**BRUTE FORCE APPROACH** - to find sum of all subarrays, and keep track of the maximum sum
                       and return it.
                       TC- O(n^2)
                       SC- O(1)

**KADANE'S ALGORITHM** - TC- O(n)

                                          SC- O(1)

                                          Doesn't work for the case where all elements in the array are negative, i.e,             it returns zero.

			int maxsum=0;
	    int currsum=0;
	    for(int j=0;j<n;j++)
	    {
	        currsum=currsum+arr[j];
	        if(currsum>maxsum)
	            maxsum=currsum;
	        else if(currsum<0)
	            currsum=0;
	    }
       return maxsum;

**IMPROVEMENT** -  TC- O(n)

                              SC- O(1)


int curSum = 0, maxSum =INT_MIN;
            for (int i = 0; i < n; i++) 
						{
                curSum += A[i];
                maxSum = max(maxSum, curSum);
                if (curSum < 0) curSum = 0;
            }
            return maxSum;

```python
#code
t=int(input())
while t>0:
    n=int(input())
    arr=list(map(int,input().split()))[:n]
    li=[]
    count=0
    for i in arr:
        count+=i
        li.append(count)
        li.append(i)
    print(max(li))
    del li[:]
    t=t-1 -->
