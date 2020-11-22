// Given a binary search tree, write a function to find the kth smallest element in the tree.

// **Example :**

// `Input : 2`

//            `/ \
//        1  3
// and k = 2
// Return : 2
// As 2 is the second smallest element in the tree.`

// > NOTE : You may assume 1 <= k <= Total number of nodes in BST
// > 

// SOLUTION - 

// Inorder traversal is in sorted manner.


void fun(TreeNode* A,vector <int> &ans)
{
    if(A==NULL)
        return;
    fun(A->left,ans);
    ans.push_back(A->val);
    fun(A->right,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) 
{
    vector <int> ans;
    fun(A,ans);
    return ans[B-1];
}