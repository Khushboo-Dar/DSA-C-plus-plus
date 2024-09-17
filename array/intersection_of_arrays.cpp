class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // Sort the arrays if they are not sorted
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> ans;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                // Ensure uniqueness in the result
                if (ans.empty() || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }
};
/*Sorting: Ensure the arrays are sorted first. This step may be skipped if the arrays are already sorted, but if not, sorting ensures that the two-pointer technique works as expected.

Uniqueness Check: Before adding an element to the result (ans), check if it is not already present. This is done by checking if ans is either empty or if the last element (ans.back()) is different from the current element.*/
