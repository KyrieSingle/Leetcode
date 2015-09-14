/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }
        bool flag = false;
        int i = 0;
        for (i = 0; i < intervals.size(); ++i) {
            if(intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(newInterval);
                flag = true;
                break;
            } else {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
        }
        if(!flag) result.push_back(newInterval);
        for(; i < intervals.size(); ++i) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
