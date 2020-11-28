// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// **Example :**

// ```
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// ```

// The above binary tree is symmetric.

// But the following is not:

// ```
//     1
//    / \
//   2   2
//    \   \
//    3    3
// ```

// Return `0 / 1` ( 0 for false, 1 for true ) for this problem.

// ## SOLUTION 

int fun(TreeNode*A, TreeNode* B)
{
    if(A==NULL&&B==NULL)
        return 1;
    if(A==NULL||B==NULL)
        return 0;
    if(A->val!=B->val)
        return 0;
    return fun(A->left,B->right)&&fun(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) 
{
    return fun(A->left,A->right);
}
