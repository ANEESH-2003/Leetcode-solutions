class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char t='z';
        bool f=0;
        for(auto i:letters)
        {
            if(i>target)
            {
                f=1;
                t=min(t,i);
                break;
            }
        }
        return f?t:letters[0];
    }
};