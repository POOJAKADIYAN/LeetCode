// Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. Output should be printed in **sorted** **increasing** order of strings.

// Input: str[] = "ABC"Output: (A B C)(A BC)(AB C)(ABC)

// **Input:**First line contains the test cases T. 1<=T<=10Each test case have one line string S of characters of length N. 1<=N<=10

// **Output:**One line per test case, every string enclosed in ().**(See example).** Output should be printed in **sorted** order.

// Example:Input:2 AB  ABC

// Output: (A B)(AB)

// (A B C)(A BC)(AB C)(ABC)

// ```cpp
// void su(vector<vector<char>>& ans,vector<char> res,string s,int n,int i)
// {
//     if(i==n)
//     {
//         ans.push_back(res);
//         return;
//     }
//     if(i>=n) 
// 		    return ;
//     res.push_back(s[i]);
//     if(i<n-1)
//     {
// 	    char ss=' ';
//       res.push_back(ss);
// 	    su(ans,res,s,n,i+1);
// 	    res.pop_back();
//     }
//     su(ans,res,s,n,i+1);
// }
// int main()
//  {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	    string s;
// 	    cin>>s;
// 	    vector<vector<char>> ans;
// 	    vector<char> res;
// 	    int n=s.length();
// 	    su(ans,res,s,n,0);
// 	    for(int i=0;i<ans.size();i++)
// 	    {
// 	        cout<<'(';
// 	        for(int j=0;j<ans[i].size();j++)
// 	        {
// 	            cout<<ans[i][j];
// 	        }
// 	        cout<<')';
// 	    }
// 	    cout<<endl;
// 	}
// 	return 0;
// }
// ```

// Short code - 

// ```cpp
#include<bits/stdc++.h>
using namespace std;
void find(int i, string s, string t)
{
    int n = s.length();
    if(i==n-1)
    {
        t+= s[i];
        cout<<"("<<t<<")";
        return;
    }
    find(i+1, s, t+s[i]+" ");
    find(i+1, s, t+s[i]);
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;   
	    cin>>s;
	    find(0, s, "");
	    cout<<endl;
	}
	return 0;
}
// ```