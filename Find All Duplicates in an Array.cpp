//Original solution
// Runtime: 160 ms
// Memory Usage: 33.7 MB
class Solution
{
public:
    void fixPosition(int position, vector<int> &nums)
    {
        if (nums[position] != position + 1)
        {
            if (nums[nums[position] - 1] == nums[position])
            {
                nums[position];
            }
            else
            {
                int temp = nums[nums[position] - 1];
                nums[nums[position] - 1] = nums[position];
                nums[position] = temp;

                fixPosition(position, nums);
            }
        }
        else
        {
            return;
        }
    }
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            fixPosition(i, nums);
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != j + 1)
            {
                answer.push_back(nums[j]);
            }
        }
        return answer;
    }
};

//Optimized solution
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n = nums.size();
        vector<int> res;
        for (int num : nums)
        {
            int ind = abs(num) - 1;
            if (nums[ind] < 0)
                res.push_back(ind + 1);
            else
                nums[ind] *= -1;
        }
        return res;
    }
};