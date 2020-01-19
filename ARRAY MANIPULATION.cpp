// Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each of the array
// element between two given indices, inclusive. Once all operations have been performed, return the maximum value in
// your array.
// For example, the length of your array of zeros . Your list of queries is as follows:
// a b k
// 1 5 3
// 4 8 7
// 6 9 1
// Add the values of between the indices and inclusive:
// index-> 1 2 3 4 5 6 7 8 9 10
// [0,0,0, 0, 0,0,0,0,0, 0]
// [3,3,3, 3, 3,0,0,0,0, 0]
// [3,3,3,10,10,7,7,7,0, 0]
// [3,3,3,10,10,8,8,8,1, 0]
// The largest value is after all operations are performed.
// Function Description
// Complete the function arrayManipulation in the editor below. It must return an integer, the maximum value in the resulting
// array.
// arrayManipulation has the following parameters:
// n - the number of elements in your array
// queries - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
// Input Format
// The first line contains two space-separated integers and , the size of the array and the number of operations.
// Each of the next lines contains three space-separated integers , and , the left index, right index and summand.
// Output Format
// Return the integer maximum value in the finished array.
// Sample Input
// 5 3
// 1 2 100
// 2 5 100
// 3 4 100
// Sample Output
// 200
// Explanation
// After the first update list will be 100 100 0 0 0 .
// After the second update list will be 100 200 100 100 100 .
// After the third update list will be 100 200 200 200 100 .
// The required answer will be 200.


//Tle error for this approach
long arrayManipulation(int n, vector<vector<int>> queries) {
           vector<long> a(n,0);
           long t=queries.size(),i=0,ab,b,k;
            while(i<t){
                   ab=queries[i][0]-1;
                   b=queries[i][1]-1;
                   k=queries[i][2];
                   for(long j=ab;j<=b;j++){
                           a[j]+=k;
                   }
            i++;
            }
        long mx=*max_element(a.begin(),a.end());
    return mx;
}

// we just update the margin values, 

// reference video - 

// https://www.youtube.com/watch?v=f04Q_XZUy4Y&feature=youtu.be

#include <stdio.h>
typedef long long l;
l a[10000077];
int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int i,x,y;
    l t;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %lld",&x,&y,&t);
        a[x] +=t;
        a[y+1]-=t;
    }
    for(i=0;i<n;i++)
    {
        printf("%lld\t",a[i]);
    }
    l ma = 0,sum=0;
    for(i=0;i<=n;i++)
    {
        sum+=a[i];
        if(sum>ma)ma = sum;
    }
    printf("%lld\n",ma);
    return 0;
}

//O(n) time complexity using difference array for range query updation
long arrayManipulation(int n, vector<vector<int>> queries) {
           vector<long> a(n+1,0);
           long t=queries.size(),j=0,ab,b,k;
            for(j=0;j<t;j++){
                   ab=queries[j][0];
                   b=queries[j][1];
                   k=queries[j][2];
                   a[ab]+=k;
                   if((b+1)<=n)
                      a[b+1]-=k;
            }
        long mx=INT_MIN,x=0;
        for(long i=1;i<=n;i++){
            x+=a[i];
            if(mx<x) mx=x;
        }
        //*max_element(a.begin(),a.end());
    return mx;
}
