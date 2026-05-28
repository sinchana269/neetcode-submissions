class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> frequencyMap;

        for(int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> buckets(nums.size() + 1);

        for(auto it : frequencyMap) {

            int number = it.first;
            int frequency = it.second;

            buckets[frequency].push_back(number);
        }

        // Step 3: Collect top k frequent elements
        vector<int> result;

        for(int i = nums.size(); i >= 0; i--) {

            for(int num : buckets[i]) {

                result.push_back(num);

                if(result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};