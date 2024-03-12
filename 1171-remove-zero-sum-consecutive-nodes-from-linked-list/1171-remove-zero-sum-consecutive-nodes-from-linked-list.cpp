class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        vector<int> v;
        unordered_set<int> s;
        int num_sum=0;
        s.insert(0);
        while(head!=nullptr)
        {
            if(s.find(num_sum+head->val)!=s.end())
            {
                int cur_sum=0,tar=num_sum+head->val;
                for(int j=v.size()-1;j>=0;j--)
                {
                    if(num_sum==tar) break;
                    s.erase(s.find(num_sum));
                    num_sum-=v[j];
                    v.pop_back();
                }
                head=head->next;
                continue;
            }
            num_sum+=head->val;
            s.insert(num_sum);
            v.push_back(head->val);
            head=head->next;
        }
        ListNode* ans;
        if(v.size()>0) ans = new ListNode(v[0]);
        else return nullptr;
        ListNode* curnode=ans;
        for(int i=1;i<v.size();i++)
        {
            ListNode* next_node = new ListNode(v[i]);
            curnode->next=next_node;
            curnode=curnode->next;
        }
        return ans;    
    }
};