// To WAP that counts the minimum operations required to convert string A to string B. The allowed operations are- 

// Addition, Deletion and Substitution

// eg- KITTEN to SITTING 

// K→S

// E→I

// add G

// i.e, total 3 operations

// ## **SOLUTION-**

// BASE CASE- when either of the string has length 0 then operations = length of other string.

// Compare the 2 strings from the ending, if last character matches, then reduce the size and call the function again. Else, choose minimun(operations for addition, deletion, subs.)

//                         Addition- (A[n],   B[m-1])  **+1**

//                         Deletion- (A[n-1],  B[m]) **+1**        

//                         Substitution - (A[n-1],    B[m-1])  **+1**

//                     Therefore     i.e., return min(op. for addition, op. for deletion, op. for substitution) **+1**


#include<bits/stdc++.h>
using namespace std;
int fun(string x,string y,int n,int m)
{
	if(n==0||m==0)
	    return m>=n?m:n;
	else if(x[n-1]==y[m-1])
		return fun(x,y,n-1,m-1);
	else
		return min(fun(x,y,n-1,m),min(fun(x,y,n-1,m-1),fun(x,y,n,m-1)))+1;
}
int main()
{
	string x,y;
	cin>>x>>y;
	int result;
	int n=x.length();
	int m=y.length();
	cout<<fun(x,y,n,m);
	return 0;
}


// 3 hours for the above.....

// ## **DYNAMIC APPROACH-**


#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int fun(string x,string y,int n,int m)
{
	if(dp[n][m]!=-1)
	    return dp[n][m];
	if(n==0||m==0)
	    return dp[n][m] = m>=n?m:n;
	else if(x[n-1]==y[m-1])
		return dp[n][m] = fun(x,y,n-1,m-1);
	else
		return dp[n][m]= min(fun(x,y,n-1,m)+1,min(fun(x,y,n-1,m-1)+1,fun(x,y,n,m-1)+1));
}
int main()
{
	string x,y;
	cin>>x>>y;
	int result;
	int n=x.length();
	int m=y.length();
	memset(dp,-1,sizeof(dp));
	int dp[n][m];
	cout<<fun(x,y,n,m);
	return 0;
}


// ## BETTER -


#include<bits/stdc++.h> 
using namespace std; 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 
int editDistDP(string str1, string str2, int m, int n) 
{ 
	int dp[m+1][n+1]; 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i==0) 
				dp[i][j] = j; 		
			else if (j==0) 
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 
			else
				dp[i][j] = 1 + min(dp[i][j-1], // Insert 
								dp[i-1][j], // Remove 
								dp[i-1][j-1]); // Replace 
		} 
	} 
	return dp[m][n]; 
} 
int main() 
{ 
	string str1 = "sunday"; 
	string str2 = "saturday"; 
	cout << editDistDP(str1, str2, str1.length(), str2.length()); 
	return 0; 
}
