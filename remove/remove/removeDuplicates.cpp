#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	int length = nums.size();
	
	int i = 1;
	int same = nums[0];
	
	int j = 1;
	while (j<length) {
		if (nums[j] == same) j++;
		else { 
			same = nums[j++];
			nums[i++] = same;
		}
	}
	return i;
}
void main() {}