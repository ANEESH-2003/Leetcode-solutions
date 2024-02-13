class Solution {

private:
    bool isPalindrome(string s){
        int st = 0, e = s.length() - 1;
        while(st < e){
            if(s[st++] != s[e--]) return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for(auto s : words){
            if(isPalindrome(s)) return s;
        }
        return "";
    }
};