// You are given weights and values of **N** items, put these items in a knapsack of capacity **W** to get the maximum total value in the knapsack. Note that we have only **one quantity of each item**.In other words, given two integer arrays **val[0..N-1]** and **wt[0..N-1]** which represent values and weights associated with **N** items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of **val[]** such that sum of the weights of this subset is smaller than or equal to **W.** You cannot break an item, **either pick the complete item, or don’t pick it (0-1 property)**.

// **Input:**The first line of input contains an integer **T** denoting the number of test cases. Then **T** test cases follow. Each test case consists of four lines.The first line consists of **N** the number of items.The second line consists of **W**, the maximum capacity of the knapsack.In the next line are **N** space separated positive integers denoting the values of the **N** items,and in the fourth line are **N** space separated positive integers denoting the weights of the corresponding items.

// **Output:**For each testcase, in a new line, print the **maximum possible** value you can get with the given conditions that you can obtain for each test case in a new line.

// **Constraints:**1 ≤ T ≤ 1001 ≤ N ≤ 10001 ≤ W ≤ 10001 ≤ wt[i] ≤ 10001 ≤ v[i] ≤ 1000
// **Example:**
// **Input:**2
// 3

// 4

// 1 2 3

// 4 5 1

// 2

// 3

// 1 2 3

// 4 5 6

// **Output:**

// 3

// 1

// ## SOLUTION -

// Using recursion, if the weight of last element is greater than the knapsack capacity, we exclude it and call function - fun(n-1, w, valueArray, weightArray)

// if weight of the last element is lesser of equal then the knapsack capacity, we take the max value returned by either including this element or excluding it.

// max(n-1,w-weightArray[n-1],,valueArray,weightArray)

#include<bits/stdc++.h>
using namespace std;

int fun(int n,int w, int val[], int wgt[])
{
    if(n==0||w==0)
        return 0;
    else if(wgt[n-1]>w)
        return fun(n-1,w,val,wgt);
    else
        return max(val[n-1]+fun(n-1,w-wgt[n-1],val,wgt),fun(n-1,w,val,wgt));
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,w;  //w is max capacity of the knapsack....
	    cin>>n>>w;
	    int val[n],wgt[n];
	    for(int j=0;j<n;j++)
	        cin>>val[j];
	    for(int j=0;j<n;j++)
	        cin>>wgt[j];
	    cout<<fun(n,w,val,wgt)<<endl;
	}
	return 0;
}

// TC - O(2^n)   

// Using DP - 

#include <bits/stdc++.h>
using namespace std;

int knapsack(int W,int wt[],int val[],int n)
{
    int i,w;
    int k[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0||w==0)
            {
                k[i][w]=0;
            }
            else if(wt[i-1]<=w)
            {
                k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else
            {
                k[i][w]=k[i-1][w];
            }
        }
    }
    return k[n][W];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int W;
	    cin>>n>>W;
	    int val[n],wt[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	     for(int i=0;i<n;i++)
	    {
	        cin>>wt[i];
	    }
	    cout<<knapsack(W,wt,val,n)<<endl;
	}
	return 0;
}