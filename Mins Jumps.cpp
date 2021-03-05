<!-- Given an array of non-negative integers, **A**, of length **N**, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the **minimum** number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

**Input Format:**

`The first and the only argument contains an integer array, A.`

**Output Format:**

`Return an integer, representing the answer as described in the problem statement.`

**Constraints:**

`1 <= N <= 1e6
0 <= A[i] <= 50000`

**Examples:**

`Input 1: A = [2, 1, 1]
Output 1: 1
Explanation 1: The shortest way to reach index 2 is Index 0 -> Index 2 that requires only 1 jump.
Input 2: A = [2,3,1,1,4]
Output 2: 2
Explanation 2: The shortest way to reach index 4 is Index 0 -> Index 1 -> Index 4 that requires 2 jumps.`

## **SOLUTION -**

A[i+1]=A[i]+1.......

A[0]=0;,...........
 -->

int Solution::jump(vector<int> &a) 
{
    if(a[0]==0&&a.size()==1)
        return 0;
    if(a[0]==0)
        return -1;
    int step=a[0],maxreach=0,count=1;
    for(int i=1;i<a.size();i++)
    {
        if(i==a.size()-1)
            return count;
        maxreach=max(maxreach,a[i]+i);
        step--;
        if(step==0)
        {
            count++;
            if(i>=maxreach) 
                return -1;
            step=maxreach-i;
        }
    }
    return -1;
}
