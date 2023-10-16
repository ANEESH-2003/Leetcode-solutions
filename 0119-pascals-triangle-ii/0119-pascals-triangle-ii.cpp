class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p={1};
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> c;
            c.push_back(1);
            for(int j=0;j<p.size()-1;j++)
            {
                c.push_back(p[j]+p[j+1]);
            }
            c.push_back(1);
            p=c;
        }
        return p;
    }
};