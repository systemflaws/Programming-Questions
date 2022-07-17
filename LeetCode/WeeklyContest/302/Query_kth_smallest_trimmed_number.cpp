/*
 TC: O(Q*NlogN *max(trims))
 SC: O(2 * N)
*/

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> answer;
        int num = nums.size();
        for (int i = 0; i < queries.size(); i++)
        {
            int charsRetain = queries[i][1];
            int index = queries[i][0];
            vector<pair<string, int>> store;
            for (int i = 0; i < num; i++)
            {
                int sz = nums[i].size();
                store.push_back({nums[i].substr(sz - charsRetain, charsRetain), i});
            }
            sort(store.begin(), store.end());
            answer.push_back(store[index - 1].second);
        }
        return answer;
    }
};