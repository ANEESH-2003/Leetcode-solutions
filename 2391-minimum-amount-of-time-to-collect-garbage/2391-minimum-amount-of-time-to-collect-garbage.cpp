class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // time 
        int p_time=0, m_time=0, g_time=0;

        // last index
        int last_p=0, last_g=0, last_m=0;
        for(int i=0;i<garbage.size();i++)
        {
            for(auto j:garbage[i])
            {
                
                if(j=='M')
                {
                    last_g=i;
                    g_time++;
                }
                    
                else if(j=='P')
                {
                    last_p=i;
                    p_time++;
                }
                else
                {
                    last_m=i;
                    m_time++;
                }
            }
        }

        for(int i=0;i<travel.size();i++)
        {
            if(i<last_g)
                g_time+=travel[i];
            if(i<last_p)
                p_time+=travel[i];
            if(i<last_m)
                m_time+=travel[i];
        }
        return (g_time+p_time+m_time);
    }
};