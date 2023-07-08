/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    TreeNode* cal(vector<int>& pre, vector<int>& in,int l,int r,int& i)
    {
        if(i>=n)
            return NULL;
        TreeNode* temp=NULL;
        for(int x=l;x<r;x++)
        {
            if(in[x]==pre[i])
            {
                i++;
                temp=new TreeNode(in[x],cal(pre,in,l,x,i),cal(pre,in,x+1,r,i));
                break;
            }
        }
        return temp;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        n=pre.size();
        int i=0;
        return cal(pre,in,0,n,i);
    }
};