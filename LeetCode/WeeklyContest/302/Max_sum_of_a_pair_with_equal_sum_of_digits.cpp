/*
 TC: O(NlogN)
 SC: O(2 * N)
*/

class Solution
{
public:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int maximumSum(vector<int> &nums)
    {
        vector<int> digitSum(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            int sum = 0;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }
            digitSum[i] = sum;
        }
        vector<pair<int, int>> combined;
        for (int i = 0; i < nums.size(); i++)
        {
            pair<int, int> k = {digitSum[i], nums[i]};
            combined.push_back(k);
        }
        sort(combined.begin(), combined.end(), compare);
        int ans = -1;
        for (int i = 1; i < combined.size(); i++)
        {
            if (combined[i].first == combined[i - 1].first)
            {
                ans = max(ans, combined[i].second + combined[i - 1].second);
            }
            continue;
        }
        return ans;
    }
};

/*
 TC: O(N*(numberOfDigits + log(N)))
 SC: O(N)
*/

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int ans = -1;
        map<int, int> store;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            int sum = 0;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (store.count(sum))
            {
                ans = max(ans, nums[i] + store[sum]);
            }
            store[sum] = max(store[sum], nums[i]);
        }
        return ans;
    }
};