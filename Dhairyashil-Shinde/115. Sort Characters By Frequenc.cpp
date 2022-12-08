class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> m1;
        multimap<int, char> m2;

        // Insert string elemets in unordered_map
        for(int i=0; i<s.length(); i++) m1[s[i]]++;

        // In multimap, Here 'Freq' is key and 
        // there corresponding character is variable
        for(auto &i:m1) m2.insert(pair<int, char>(i.second, i.first));

        string ans = ""; // empty string
        int temp = 0;
        for(auto &i:m2) {
            temp = i.first;
            while(temp--) ans += i.second; // concatenation of char in string
        }

        reverse(ans.begin(), ans.end()); // we want string in Decresing Order
        return ans;
    }
};
