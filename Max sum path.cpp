// Given a `m x n` grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// > Note: You can only move either down or right at any point in time.
// > 

// **Example :**

// `Input : [ 1 3 2`

//                 `4 3 1` 

//                 `5 6 1 ]
// Output : 8`

// `Explination : 1 -> 3 -> 2 -> 1 -> 1`

// ## **SOLUTION -**


int fun(vector <vector <int>> A,int x,int y, int n, int m)
{
    if((x==n-1)&&(y==m-1))
        return A[x][y];
    if(x==n-1)
        return fun(A,x,y+1,n,m)+A[x][y];
    if(y==m-1)
        return fun(A,x+1,y,n,m)+A[x][y];
    return min(fun(A,x+1,y,n,m)+A[x][y],fun(A,x,y+1,n,m)+A[x][y]);
}
int Solution::minPathSum(vector<vector<int> > &A)
{
    int n=A.size();
    int m=A[0].size();
    return fun(A,0,0,n,m);
}