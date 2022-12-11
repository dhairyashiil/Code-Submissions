class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>> &intervals) 
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // sort on the basis of start points
        int cnt = 0;
        int i = 0;
        int j = 1;
        
        while(j<n) {
            
            // CASE 1 :- i.second < j.first [Non-Overlapping intervals, take both intervals]
            // |   Interval i   |   |   Interval j  |
            
            if(intervals[i][1] <= intervals[j][0]) { // Non-overlapping case(Case 1)
                i = j;
                j++;
            }
            
            // CASE 2 :- i.second <= j.second [Overlapping intervals, take interval "i"  and greedly remove right interval "j"]
            // |   Interval i   |
            //            |    Interval j  |
            
            else if(intervals[i][1] <= intervals[j][1]) { // Case 2
                cnt++;
                j++;
            }
            
            // CASE 3 :- i.second > j.second [Overlapping intervals, take interval "j" and greedly remove left interval "i"]
            //  |    Interval i    |
            //     | Interval j |
            
            else if(intervals[i][1] > intervals[j][1]) { // Case 3
                cnt++;
                i = j;
                j++;
            }
        }
        return cnt;
    }
};
