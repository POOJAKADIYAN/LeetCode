// Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

// **Example :**Given binary tree

// ```
//     3
//    / \
//   9  20
//     /  \
//    15   7
// ```

// return

// ```
// [
//          [3],
//          [20, 9],
//          [15, 7]
// ]
// ```

// ## SOLUTION -

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
     int level=1;
    stack<TreeNode*>p,q;
    p.push(A);
    vector<vector<int> >ans;
    while(p.empty()==false)
    {
        vector<int>v;
        v.clear();
        if(level%2==0)
        {
            while(p.empty()==false)
            {
                TreeNode* temp=p.top();
                p.pop();
                v.push_back(temp->val);
                if(temp->right)
                {
                    q.push(temp->right);
                    
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
            }
          
        }
        else
        {
                while(p.empty()==false)
                {
                    TreeNode* temp=p.top();
                    p.pop();
                    v.push_back(temp->val);
                    if(temp->left)
                    {
                        q.push(temp->left);
                        
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
          
        }
            level++;
            ans.push_back(v);
            stack<TreeNode*>t;
            t=p;
            p=q;
            q=t;
    
        
    }
    return ans;
}