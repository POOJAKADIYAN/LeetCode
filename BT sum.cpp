// Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

// For example:Given the below binary tree and sum = 22,

// ```
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// ```

// return

// `[` 

//    `[5,4,11,2],` 

//    `[5,8,4,5]
// ]`


void fun(TreeNode* A, int B, vector <vector <int>> &ans,vector <int> x)
{
    if(A!=NULL)
    {
        x.push_back(A->val);
    fun(A->left,B-A->val,ans,x);
    fun(A->right,B-A->val,ans,x);
    if(A->left==NULL&&A->right==NULL&&B==A->val)
        ans.push_back(x);
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector <vector <int> > ans;
    vector <int> x;
    fun(A,B,ans,x);
    return ans;
}
