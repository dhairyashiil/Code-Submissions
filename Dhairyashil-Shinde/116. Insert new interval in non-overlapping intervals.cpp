class Solution {
public:

    vector<vector<int>> result;

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // Constant to help us access start point and end point of interval
        const int START = 0, END = 1;
        
        int s = newInterval[START];
        int e = newInterval[END];
        vector<vector<int>> left, right;
        
        for( auto& curInterval : intervals ) {
            
            if (curInterval[END] < s) {
                // current interval is on the left hand side of newInterval
                left.push_back( curInterval );    
            }
            else if( curInterval[START] > e ) {
                // current interval is on the right hand side of newInterval
                right.push_back( curInterval );
            }
            else {
                // current interval has overlap with newInterval
                // merge and update boundary
                s = min(s, curInterval[START] );
                e = max(e, curInterval[END] );
            }
        }
        
        result.insert( result.end(), left.begin(), left.end() );
        result.push_back( {s, e} );
        result.insert( result.end(), right.begin(), right.end() );
        
        return result;
    }
};
