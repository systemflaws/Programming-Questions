/*
 TC: O(N * log(N))
 SC: O(N)
 log(N) -> map/set operation;
*/

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> answer;
        map<int, int> frequency;
        for (auto i : nums)
        {
            frequency[i]++;
        }
        int counteven = 0;
        int remaining = 0;
        for (auto i : frequency)
        {
            counteven += i.second / 2;
            remaining += i.second % 2;
        }
        answer.push_back(counteven);
        answer.push_back(remaining);
        return answer;
    }
};

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        set<int> store;
        int num = nums.size();
        int pair = 0;
        for (int i = 0; i < num; i++)
        {
            int element = nums[i];
            if (store.count(element) & 1)
            {
                pair++;
                store.erase(element);
            }
            else
            {
                store.insert(element);
            }
        }
        return {pair, (int)store.size()};
    }
};