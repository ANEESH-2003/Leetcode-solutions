class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    
    RandomizedSet() {
        mp.clear();
        arr.clear();
    }
    
    bool insert(int val) {
        
        if(mp.find(val) == mp.end())
        {
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        
        if(mp.find(val) != mp.end())
        {
            int t = mp[val];
            int s = arr.size();
            
            arr[t] = arr[s-1];
            mp[arr[t]] = t;
            
            arr.pop_back();
            mp.erase(val);
            
            return true;
        }
        
        return false;
    }
    
    int getRandom() {      
        
        int s = arr.size();
        
        return arr[rand() % s];
    }
};