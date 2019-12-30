// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

// **Input:**

// The first line of input contains an integer T denoting the number of test cases.The first line of each test case is n and m,n is the number of rows and m is the number of columns.The second line of each test case contains array C[n][m] in row major form.

// **Output:**

// Print maximum size square sub-matrix.

// **Constraints:**

// 1 ≤ T ≤ 1001 ≤ n,m ≤ 500 ≤ C[n][m] ≤ 1

// **Example:**

// **Input:**3

// 5 6

// 0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1

// 2 2

// 1 1 1 1

// 2 2

// 0 0 0 0

// **Output:**3

//        2

//             0

// ## SOLUTION -

// [Maximum size square sub-matrix with all 1s - GeeksforGeeks](https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/)

// Was getting SEG fault for skipping this, 

// while declaring a 2-D vector of size n*m, do write ***vector <vector <int> > (n, vector <int> (m));***

#include<bits/stdc++.h>
using namespace std;
void fun(vector <vector <int> > mat)
{
    int n =mat.size();
    int m = mat[0].size();
    int imax=0;
    int jmax=0;
    vector <vector <int > > s(n, vector <int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mat[i][0])
            ans=1;
        s[i][0]=mat[i][0];
    }
    for(int i=0;i<m;i++)
    {
        if(mat[0][i])
            ans=1;
        s[0][i]=mat[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j])
                s[i][j]=min(s[i][j-1],min(s[i-1][j],s[i-1][j-1]))+1;
            if(s[i][j]>ans)
            {
                ans=s[i][j];
                imax=i;    //if we need to print the submatrix too
                jmax=j;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=imax;i>abs(imax-n);i--)
    {
        for(int j=jmax;j>abs(jmax-m);j--)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    return;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,m;
	    cin>>n>>m;
	    vector <vector <int> > mat(n,vector <int> (m));
	    for(int j=0;j<n;j++)
	        for(int k=0;k<m;k++)
	            cin>>mat[j][k];
	   fun(mat);
	}
	return 0;
}


// TC - O(N*M)

// SC - O(N*M)