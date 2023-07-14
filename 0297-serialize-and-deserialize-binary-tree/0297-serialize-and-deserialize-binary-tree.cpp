/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
/*string ans;
    string serialize(TreeNode* root) {
        if(!root)
            return "$";
        int x=root->val;
        string s="";
        if(x<0)
            s="-"
        x=abs(x);
        s+=to_string(x);
        s+="#";
        s+=cal(root->left);
        s+"#";
        s+=cal(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==1)
            return NULL;
        TreeNode* temp=NULL;
        int i=0;
        int n=data.size();
        queue<TreeNode*> q;
        while(i<n)
        {
            string x="";
            for(;i<n;i++)
            {
                if(data[i]=='#')
                    break;
                x+=data[i];
            }
            i++;
        }
        int num=stoi(x);
        temp=new TreeNode(x);
    }
};*/
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));