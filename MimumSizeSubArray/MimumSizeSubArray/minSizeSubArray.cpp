#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
	
	int length = nums.size();
	if (length==0) {
		return 0;
	}
	bool Flag = false;
	int minLength = length+1;
	int sum = 0;
	int currentSubSize;

	for (int i = 0; i < length;i++) {
		sum = 0;
		for (int j = i; j < length;j++) {
			sum += nums[j];
			currentSubSize = j - i + 1;
			if (sum>=s&&currentSubSize<minLength) {
				Flag = true;
				minLength = currentSubSize;
				break;
			}
		}

	}

	if (!Flag) { 
		return 0; 
	}
	else 
		return minLength;




}
void main(){

	return;
}