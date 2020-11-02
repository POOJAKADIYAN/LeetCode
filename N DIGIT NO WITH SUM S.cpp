// Find out the number of `N` digit numbers, whose digits on being added equals to a given number `S`. Note that a valid number starts from digits `1-9` except the number `0` itself. i.e. leading zeroes are not allowed.

// Since the answer can be large, output answer modulo `1000000007`

// `N = 2, S = 4`

// Valid numbers are `{22, 31, 13, 40}`

// Hence output `4`.

void minimumBribes(vector<int> q) {
    int bribe = 0;
   bool chaotic = false;
   int n = q.size();
   for(int i = 0; i < n; i++)
   {
       if(q[i]-(i+1) > 2)
       {              
           chaotic = true;
           break;    
       }
       for (int j = max(0, q[i]-1-1); j < i; j++)
           if (q[j] > q[i])
               bribe++;
   }
   if(chaotic)
       cout<<"Too chaotic"<<endl;
   else
       cout<<bribe<<endl;
}