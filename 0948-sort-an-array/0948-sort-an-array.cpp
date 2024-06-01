class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l<n && nums[l] > nums[largest])
            largest = l;
        if(r<n && nums[r] > nums[largest])
            largest = r;
        
        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            maxHeapify(nums,n,largest);
        }
    }
    
    void buildHeap(vector<int>& nums, int n)
    {
        for(int i=n/2 - 1;i>=0;i--)
            maxHeapify(nums,n,i);
    }
    
    void heapSort(vector<int>& nums, int n)
    {
        buildHeap(nums,n);

        // keep swapping first and last
        // keep reducing size that we pass to buildHeap
        
        for(int i=n-1;i>=1;i--)
        {
            swap(nums[0],nums[i]);
            maxHeapify(nums,i,0);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        heapSort(nums,nums.size());
        
        return nums;
    }
};