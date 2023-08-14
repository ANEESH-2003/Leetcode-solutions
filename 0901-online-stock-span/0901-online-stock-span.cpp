class StockSpanner {
public:
    stack<pair<int,int>> s;
    int c;
    StockSpanner() {
        s.push({INT_MAX,-1});
        c=0;
    }
    
    int next(int price) {
        while(s.top().first<=price)
            s.pop();
        int ans=c-s.top().second;
        s.push({price,c});
        c++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */