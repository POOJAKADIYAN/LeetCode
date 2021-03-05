// Given a string, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

// **example:** 

// **input:**  str = "AABEBCDD"

// **output:**  3

// **the longest repeating subsequence is** "ABD"

// ## **Dynamic Solution -**

// ```cpp
#include <bits/stdc++.h> 
using namespace std; 
int dp[1000][1000]; 
int fun(string X, int m, int n) 
{ 	
	if(dp[m][n]!=-1) 
	return dp[m][n];
	if (m==0||n==0) 
		return dp[m][n]=0; 
	if (X[m-1]==X[n-1]&&m!=n) 
		return dp[m][n]=fun(X,m-1,n-1)+1; 
	return dp[m][n]=max(fun(X,m,n-1),fun(X,m-1,n)); 
}
int main() 
{ 
	string str;
	cin>>str;
	int m = str.length(); 
    memset(dp,-1,sizeof(dp)); 
    cout<<fun(str,m,m);
	return 0;
}


// PS - In love with dp 01-09-2019 2:21 AM