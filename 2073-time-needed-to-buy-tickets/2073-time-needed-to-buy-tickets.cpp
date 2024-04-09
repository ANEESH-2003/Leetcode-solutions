class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum=0;
        for(int i=0;i<tickets.size();i++){
            if(tickets[k]>tickets[i]){
                sum +=tickets[i];
            }else if(i>k){
                sum +=tickets[k]-1;
            }else{
                sum +=tickets[k];
            }
        }
        return sum;
        
    }
};