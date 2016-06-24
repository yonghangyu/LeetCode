#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j) {
	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

int majorityElement(vector<int>& nums) {
	int length = nums.size();
	bool isSwapped = false;
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i;j++) {
			if (nums[j]>nums[j+1]) {
				swap(nums[j],nums[j+1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) break;

	}
	vector<int> count;
	count.resize(length);
	int currentNum;
	for (int i = 0; i < length; i++) {
		if (i == 0) { count[0]++; currentNum = 0;}
		else {
			if (nums[i] > nums[i - 1]) {
				if (count[currentNum]>(length/2)) {
					return nums[i - 1];
				}
				else count[++currentNum]++;
				
			}
			else {
				count[currentNum]++;
			}
		}

	}

	if (length == 1) { return nums[0]; }
	else {
		return nums[length - 1];
	}

	
}

void main() {

}