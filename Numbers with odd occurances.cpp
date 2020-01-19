// You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.

// **Input :**The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

// **Output :**Print in a new line the two numbers in ascending order.

// **Constraints :**1<=T<=1001<=N<=10^61<=A[i]<=5*10^8

// **Example:Input :**221 2 3 2 1 412 1 3 2

// **Output :**3 41 3

// ## SOLUTION -
// using hashmap to store the number if they appear once.
// if the number already exists in the map we erase it. In the end the map contains the numbers with odd occurrence.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[(2*n)+2];
        for(int j=0;j<(2*n)+2;j++)
            cin>>arr[j];
        unordered_map <int,int> mp;
        for(int j=0;j<(2*n)+2;j++)
        {
            if(mp.find(arr[j])==mp.end())
                mp[arr[j]]=arr[j];
            else
                mp.erase(arr[j]);
        }
        vector <int> ans;
        for (auto it:mp)
             ans.push_back(it.first);
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<" "<<ans[1];
        cout<<endl;
    }
   // cout<<endl;
	return 0;
}

// Most efficient way would be to perform XOR of all numbers and storing it in a variable x.

// then we extract the 2 numbers from the variable x.

// "Take the XOR of all elements let's call the value t. Then find the first bit whose value is 1 in t and call it index. Then take xor of all values whose bit at index position is 1 and let call it n. Then your output is min(n,t^n) and max(n,t^n)."

#include <bits/stdc++.h> 
using namespace std; 

/* This finction sets the values of 
*x and *y to nonr-epeating elements 
in an array arr[] of size n*/
void get2NonRepeatingNos(int arr[], int n, int *x, int *y) 
{ 
	int Xor = arr[0]; /* Will hold Xor of all elements */
	int set_bit_no; /* Will have only single set bit of Xor */
	int i; 
	*x = 0; 
	*y = 0; 
	
	/* Get the Xor of all elements */
	for(i = 1; i < n; i++) 
	Xor ^= arr[i]; 
	
	/* Get the rightmost set bit in set_bit_no */
	set_bit_no = Xor & ~(Xor-1); 
	
	/* Now divide elements in two sets by comparing rightmost set 
	bit of Xor with bit at same position in each element. */
	for(i = 0; i < n; i++) 
	{ 
		if(arr[i] & set_bit_no) 
		*x = *x ^ arr[i]; /*Xor of first set */
		else
		*y = *y ^ arr[i]; /*Xor of second set*/
	} 
} 

/* Driver code */
int main() 
{ 
	int arr[] = {2, 3, 7, 9, 11, 2, 3, 11}; 
	int *x = new int[(sizeof(int))]; 
	int *y = new int[(sizeof(int))]; 
	get2NonRepeatingNos(arr, 8, x, y); 
	cout<<"The non-repeating elements are "<<*x<<" and "<<*y; 
} 

// This code is contributed by rathbhupendra