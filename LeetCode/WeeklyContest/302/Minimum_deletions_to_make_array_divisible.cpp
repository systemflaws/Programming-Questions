/*
 TC: O(NlogN)
 SC: O(2 * N)
*/

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        sort(nums.begin(), nums.end());
        map<int, int> frequency;
        set<int> store;
        for (int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
            store.insert(nums[i]);
        }
        int divs = numsDivide.size();
        if (divs == 1)
        {
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (numsDivide[0] % nums[i] == 0)
                {
                    return count;
                }
                count++;
            }
            return -1;
        }
        int gcd = numsDivide[0];
        for (int i = 1; i < divs; i++)
        {
            gcd = __gcd(gcd, numsDivide[i]);
        }
        int count = 0;
        for (auto i : store)
        {
            if ((gcd % i) == 0)
            {
                return count;
            }
            count += frequency[i];
        }
        if (count == nums.size())
        {
            return -1;
        }
        return count;
    }
};