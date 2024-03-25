class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        unordered_map<int, int> freqMap;

        // Count the frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }

        // Find numbers with frequency > 1
        for (auto& pair : freqMap) {
            if (pair.second > 1) {
                duplicates.push_back(pair.first);
            }
        }

        return duplicates;
    }
};