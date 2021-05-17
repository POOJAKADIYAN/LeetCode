/*

https://www.interviewbit.com/problems/find-permutation/



Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive 
integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

    Length of given string s will always equal to n - 1
    Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

*/

# 1st method

public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> findPerm(final String A, int B) {
        
        int smallest =1;
        int largest = B;
        ArrayList<Integer> op = new ArrayList<Integer>();
        for(int i=0;i<A.length();i++)
        {
            if(A.charAt(i)=='D')
            {
                op.add(largest);
                largest = largest -1;
            }
            else
            {
                op.add(smallest);
                smallest = smallest+1;
            }
        }
        
        op.add(smallest);
        return op;
    }
}


# 2nd method


vector<int> Solution::findPerm(const string s, int B)
{
    vector<int> res(1, 1);
    
    auto x = res.begin(); int i = 2;
    
    for(auto ch : s)
    {
        if(ch == 'D')
            x = res.insert(x, i++);
        else
        {
            res.push_back(i++);
            x = prev(res.end());
        }
    }
    return res;
}

