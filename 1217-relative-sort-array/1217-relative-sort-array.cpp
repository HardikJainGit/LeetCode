class Solution {
public:

    static bool customCompare(int& a, int& b, vector<int>& arr2) 
    {
        auto itA = find(arr2.begin(), arr2.end(), a);
        auto itB = find(arr2.begin(), arr2.end(), b);

        if (itA == arr2.end() && itB == arr2.end()) 
        {
            return a < b; // ascending if not present in arr2
        }

        // sort on index in arr2

        return distance(arr2.begin(), itA) < distance(arr2.begin(), itB);
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        sort(arr1.begin(), arr1.end(), [&arr2](int& a, int& b)
        {
            return customCompare(a, b, arr2);
        });

        return arr1;
    }
};