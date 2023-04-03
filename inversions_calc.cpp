//Daniel Jolin
/*INVERSION NUMBER aka cardinality of the inversion set
common measure of sortedness
an inversion is a sequence of elements that are out of their natural order
*/
#include <iostream>
#include <vector>
#include <algorithm> // For call to copy

int mergeInv(std::vector<int>& nums, std::vector<int>& left, std::vector<int>& right) {
    //find middle
    int mid = nums.size()/2;
    //divide into 3 parts and sum for result
    int x = 0;
    int y = 0;
    int z = 0;
    int count = 0;

    // Checks between the left and right vector.
    while(x < left.size() && y < right.size()){
        //swap only if right is larger than left.
        if (left[x] <= right[y]){
            nums[z++] = left[x++];
        }
        
        //for every swap, increase counter. 
        else {
            nums[z++] = right[y++];
            count += mid;
        }
    }
    //copy whats left in left into the vector.
    while (x < left.size()) {
        nums[z++] = left[x++];
    }
    //whats left in right into the vector.
    while (y < right.size()) {
        nums[z++] = right[y++];
    }
    return count;
}

int countInv(std::vector<int>& nums) {
	// Base case - one element, nothing to sort
	if (nums.size() > 1) {
		int mid = nums.size()/2;
		std::vector<int> left(mid);
		std::vector<int> right(nums.size()-mid);
		std::copy(nums.begin(), nums.begin() + mid, left.begin());
		std::copy(nums.begin() + mid, nums.end(), right.begin());
		int numInvLeft = countInv(left);
		int numInvRight = countInv(right);
		int numInvMerge = mergeInv(nums, left, right);
		return numInvLeft + numInvRight + numInvMerge;
		
	}
	return 0;
}
int main()
{
    int n;
    std::vector<int> numvec{4, 5, 6, 1, 2, 3};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 9
    
    numvec = {1, 2, 3, 4, 5, 6};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 0
    
    numvec = {6, 5, 4, 3, 2, 1};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;  // Should be 15
    
    numvec = {0, 0, 0, 0, 0, 0};
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;;  // Should be 0
}
