// You are given *q* queries. Each query is of the form two integers described below:
// - 1 x: Insert x in your data structure.
// - 2 y: Delete one occurence of y from your data structure, if present.
// - 3 z: Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.
// The queries are given in the form of a 2-D array *queries* of size q where queries[i][0] contains the operation, and queries[i][1] contains the data element. For example, you are given array

// queries=[(1,1),(1,2),(3,2),(1,1),(1,1),(2,1),(3,1)].
// The results of each operation are:
// Operation   Array   Output
// (1,1)            [1]
// (2,2)            [1]
// (3,2)                             0
// (1,1)           [1,1]
// (1,1)           [1,1,1]
// (2,1)           [1,1]
// (3,2)                            1
// Return an array with the output: [0,1].
// **Function Description**
// Complete the freqQuery function in the editor below. It must return an array of integers where each element is a 1 if there is at least one element value with the queried number of occurrences in the current array, or 0 if there is not.
// freqQuery has the following parameter(s):
// queries: a 2-d array of integer
// **Input Format**
// The first line contains of an integer , the number of queries.
// Each of the next lines contains two integers denoting the 2-d array .

// **Output Format**
// Return an integer array consisting of all the outputs of queries of type **3**.
// **Sample Input 0**
// 8
// 1 5
// 1 6
// 3 2
// 1 10
// 1 10
// 1 6
// 2 5
// 3 2
// **Sample Output 0**
// 0
// 1
// **Explanation 0**
// For the first query of type 3, there is no integer whose frequency is 2(array=[5,6]). So answer is 0.
// For the second query of type 3, there are two integers in array=[6,10,10,6] whose frequency 2(integers = 6 and 10). So, the answer is 1.
// **Sample Input 1**
// 4
// 3 4
// 2 1003
// 1 16
// 3 1
// **Sample Output 1**
// 0
// 1
// **Explanation 1**
// For the first query of type 3, there is no integer of frequency 4. The answer is 0.
// For the second query of type 3, there is one integer,16 of frequency 1 so the answer is 1.

vector<int> freqQuery(vector<vector<int>> queries) {
        long n=queries.size();
        map<long ,long> mp1;
        map<long,long> mp2;
        vector<int> vec;
        for(long i=0;i<n;i++){
            int a=queries[i][0];
            long b=queries[i][1];
            switch(a){
                case 1: mp2[mp1[b]]--;
                        mp1[b]++;
                        mp2[mp1[b]]++;
                        break;
                case 2: if(mp1.find(b)!=mp1.end() && mp1[b]>0)
                        { mp2[mp1[b]]--;
                            mp1[b]--;
                            mp2[mp1[b]]++;
                           }
                        break;
                case 3: bool fg=false;
                        if(mp2.find(b)!=mp2.end() && mp2[b]>0)
                            fg=true;
                        if(fg)
                           vec.push_back(1);
                        else
                           vec.push_back(0);                
                        break;
            }
        }
    return vec;
}