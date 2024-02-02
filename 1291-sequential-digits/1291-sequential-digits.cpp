class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string space = "123456789";

        for(int wd = to_string(low).size(); wd <= to_string(high).size(); wd++){
            for(int i = 0; i+wd < 10; i++){
                int num = stoi(space.substr(i, wd));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};