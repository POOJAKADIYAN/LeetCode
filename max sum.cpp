<!-- Given a **2 x N** grid of integer, **A**, choose numbers such that the sum of the numbersis maximum and **no** two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

**Note:** You can choose more than 2 numbers.

**Input Format:**

`The first and the only argument of input contains a 2d matrix, A.`

**Output Format:**

`Return an integer, representing the maximum possible sum.`

**Constraints:**

`1 <= N <= 20000
1 <= A[i] <= 2000`

**Example:**

`Input 1: A = [ [1] [2] ]
Output 1: 2
Explanation 1: We will choose 2.
Input 2: A = [ [1, 2, 3, 4] [2, 3, 4, 5] ]
Output 2: We will choose 3 and 5.`

## SOLUTION- -->

int fun(vector <vector <int>> &A)
{
int dp[A[0].size()+1];
    
    dp[0]=0;
    dp[1]=max(A[0][0],A[1][0]);
    dp[2]=max(A[0][1],A[1][1]);
    for(int i=3;i<=A[0].size();i++)
    {
        dp[i]=max(A[0][i-1],A[1][i-1])+max(dp[i-2],dp[i-3]);
    }
    return max(dp[A[0].size()],dp[A[0].size()-1]);
}
