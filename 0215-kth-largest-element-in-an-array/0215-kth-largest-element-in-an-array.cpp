class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int k2 = nums.size() - k + 1;
        priority_queue <int> q;
        for(int i=0 ; i<k2;i++)
        {
            q.push(nums[i]);
        }
        for(int i=k2 ; i< nums.size() ; i++)
        {
            if(nums[i] < q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};