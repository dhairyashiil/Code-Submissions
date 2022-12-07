class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // If all have frequency equal to 1, Means all are unique elements
        if(k == nums.size()) return nums;

        vector<int> ans;
        unordered_map<int, int> m1;
        
        // Multimap will allow duplicate key (We are using this property)
        multimap<int, int> m2; 

        // Count the frequencies
        for(auto num : nums) m1[num]++; 

        // Now according to Frequency put elements into 'multimap'
        // It will automatically sort
        // so now most frequent elements present at bottom of multimap
        for(auto i:m1) m2.insert(pair<int, int>(i.second, i.first));

        // put all elements in 'stack' (In order as they present in multimap)
        stack<int> st; // Last in First Out (We are using this property)
        for(auto i:m2) st.push(i.second);

        int temp;
        while(k--) {
            temp = st.top(); st.pop();
            ans.push_back(temp);
        }

        return ans;
    }

};
