// Merge k sorted linked lists and return it as one sorted list.

// **Example :**

// `1 -> 10 -> 20
// 4 -> 11 -> 13
// 3 -> 8 -> 9`

// will result in

// `1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20`

// ## SOLUTION -

Node * merge(Node *n1, Node *n2)
{
    if(n1 == NULL)
        return n2;
    if(n2 == NULL)
        return n1;
        
    if(n1->data < n2->data)
    {
        n1->next = merge(n1->next, n2);
        return n1;
    }
    else
    {
        n2->next = merge(n1, n2->next);
        return n2;
    }
}
  

Node * mergeKLists(Node *arr[], int N)
{
    if(N == 1)
        return arr[0];
    Node *n1 = arr[0];
    Node *n2 = arr[1];
    Node *ans = merge(n1, n2);
    
    for(int i=2; i<N; i++)
    {
        Node *n= arr[i];
        if(n != NULL)
            ans = merge(ans, n); 
    }
        
    return ans;
}
