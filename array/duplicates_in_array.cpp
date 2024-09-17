class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Tortoise and Hare
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Move hare twice as fast as tortoise
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Phase 2: Find the entrance to the cycle (the duplicate number)
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare; // or return tortoise, both are the duplicate number
    }
};

/*Floyd's Tortoise and Hare: This algorithm works based on cycle detection, just like in linked lists. We treat the array as a linked list where the value at each index represents the next pointer. Since there is one duplicate number, there will be a cycle formed in this "linked list."

The tortoise moves one step at a time.
The hare moves two steps at a time.
If there's a cycle (i.e., a repeated number), the two will eventually meet.
Phase 1: Find the intersection point of the cycle using the tortoise and hare.

Phase 2: Find the entrance to the cycle, which is the repeated number.

*/