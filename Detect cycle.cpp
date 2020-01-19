// A linked list is said to contain a *cycle* if any node is visited more than once while traversing the list. For example, in the following graph there is a cycle formed when node 5 points back to node 3.

// ![](https://s3.amazonaws.com/hr-assets/0/1527604250-43ac8fbfaf-filtrationExample.png)

// **Function Description**

// Complete the function *has_cycle* in the editor below. It must return a boolean *true* if the graph contains a cycle, or *false*.

// has_cycle has the following parameter(s):

// - head: a pointer to a *Node* object that points to the head of a linked list.
// **Note:** If the list is empty, head will be *null*.
// **Input Format**

// There is no input for this challenge. A random linked list is generated at runtime and passed to your function.

// **Output Format**

// If the list contains a cycle, your function must return *true*. If the list *does not* contain a cycle, it must return *false*. The binary integer corresponding to the boolean value returned by your function is printed to stdout by our hidden code checker.

// **Sample Input**

// The following linked lists are passed as arguments to your function:

// ![](https://s3.amazonaws.com/hr-assets/0/1527605967-9c8887640c-hascycleS0.png)

// ![](https://s3.amazonaws.com/hr-assets/0/1527605730-b50d823d5c-hascycleS1.png)

// **Sample Output**

// `0
// 1`

// **Explanation**

// The first list has no cycle, so we return *false* and the hidden code checker prints 0 to stdout.

// The second list has a cycle, so we return *true* and the hidden code checker prints 1 to stdout.

//one pointer will move with 2X speed than other and hence if they meet they will detect a cycle
bool has_cycle(SinglyLinkedListNode* head) {
    if(head==NULL)
        return 0;
    SinglyLinkedListNode *p=head,*q=p;
    while(q!=NULL && q->next!=NULL){
            p=p->next;
            q=q->next->next;
        if(p==q)
          return 1;
    }
    return 0;
}