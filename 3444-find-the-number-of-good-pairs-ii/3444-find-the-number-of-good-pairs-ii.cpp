class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        unordered_map<long long, long long> m;

        for (int num : nums2) {
            m[(long long) num * k]++;
        }

        vector<long long> multiple_ofnums2_countinnum1(*max_element(nums1.begin(), nums1.end()) + 1, 0);

        for (auto& [mul, cc] : m) {
            for (long long j = mul; j < multiple_ofnums2_countinnum1.size(); j += mul) {
                multiple_ofnums2_countinnum1[j] += cc;
            }
        }


        long long ret = 0;

        for (int num : nums1) {
            ret += multiple_ofnums2_countinnum1[num];
        }

        return ret;
    }
};
