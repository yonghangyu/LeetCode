#include<iostream>
using namespace std;
#include<cmath>
#include<vector>

int maxProfit(vector<int>& prices) {

	/*
	int dayPeriod = prices.size();
	int maxProfit = -1;
	int currentProfit;
	for (int i = 0; i < dayPeriod-1;i++) {
	for (int j = i + 1; j < dayPeriod;j++) {
	currentProfit = abs(prices[i]-prices[j]);
	if (currentProfit>maxProfit) {
	maxProfit = currentProfit;
	}
	}
	}
	return maxProfit;*/


	int dayPeriod = prices.size();
	
	if (dayPeriod==0) {
		return 0;
	}
	
	int minPrice = numeric_limits<int>::max();// the minimal price before the ith day
	int maxProfit = 0;
	int w;// the current maxProfit if sold at the ith day  
	
	for (int i = 0; i < dayPeriod;i++) {
		if (prices[i] < minPrice) { minPrice = prices[i]; }// the minimal price until the ith day
		w = prices[i] - minPrice;// current maxProfit 
		if (maxProfit < w)
			maxProfit = w;
	}
	return maxProfit;
	


}



void main() {}