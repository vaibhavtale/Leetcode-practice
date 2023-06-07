// TC = O(N)
// SC = O(1)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& time, vector<int>& event) {
        vector<vector<int>> ans; // Initialize an empty vector to store the result
        int ind = -1; // Initialize index to -1 indicating no insertion point found

        // Iterate over each interval in the 'time' list
        for(int i = 0; i < time.size(); i++) {
            if(time[i].back() < event[0]) {
                // If the end of the current interval is less than the start of the 'event' interval,
                // add the current interval as it is to the result list
                ans.push_back(time[i]);
            }
            else if(time[i].back() > event[0] && time[i][0] > event[1]) {
                // If the end of the current interval is greater than the start of the 'event' interval,
                // and the start of the current interval is greater than the end of the 'event' interval,
                // insert the 'event' interval and the current interval into the result list,
                // update the insertion index, and break the loop
                ans.push_back(event);
                ans.push_back(time[i]);
                ind = i;
                break;
            }
            else if(time[i].back() >= event[0] && time[i][1] > event[1]) {
                // If the end of the current interval is greater than or equal to the start of the 'event' interval,
                // and the end of the current interval is greater than the end of the 'event' interval,
                // update the 'event' interval start and end points to merge the intervals
                event[1] = max(event[1], time[i][1]);
                event[0] = min(event[0], time[i][0]);
            }
            else if(time[i].back() >= event[0] && time[i].back() <= event[1]) {
                // If the end of the current interval is greater than or equal to the start of the 'event' interval,
                // and the end of the current interval is less than or equal to the end of the 'event' interval,
                // update the 'event' interval start point to merge the intervals
                event[0] = min(event[0], time[i][0]);
            }
        }

        // If no insertion point was found, add the 'event' interval to the end of the result list
        if(ind == -1) {
            ans.push_back(event);
            return ans;
        }

        // Add the remaining intervals after the insertion point to the result list
        for(int i = ind + 1; i < time.size(); i++) {
            ans.push_back(time[i]);
        }

        return ans; // Return the updated 'time' list
    }
};
