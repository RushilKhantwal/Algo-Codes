#include<iostream>
using namespace std;
int main(){
	long long int numOfStudents, numOfDiscountCoupons, minCoupons, additionalCoupons;
	cin >> numOfStudents >> numOfDiscountCoupons >> minCoupons >> additionalCoupons;
	long long int start = 1, end = numOfStudents, mid, finalAns;
	while(start <= end){
		mid = (start + end) / 2;
		long long int new_numOfDiscountCoupons = numOfDiscountCoupons + ((numOfStudents - mid) * additionalCoupons);
		if(new_numOfDiscountCoupons < (mid * minCoupons)){
			end = mid -1;
		}
		else{
			finalAns = mid;
			start = mid + 1;
		}
	}
	cout << finalAns;
	return 0;
}
