// to find if any combination of elements in vector A will give sum 'sum'.

// n is size of A.

int fun(vector <int> A, int n, int sum) 
{ 
   if (sum == 0) 
     return 1; 
   if (n == 0 && sum != 0) 
     return 0; 
   if (A[n-1] > sum) 
     return fun(A, n-1, sum); 
   return fun(A, n-1, sum) || fun(A, n-1, sum-A[n-1]); 
}
