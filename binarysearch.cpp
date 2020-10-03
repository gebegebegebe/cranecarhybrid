#include<iostream>
using namespace std;

int findmid(int input){
	int l = 0;
	int r = 9;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int mid;
	while(l<r){
		mid = l + (r-l)/2;
		if (arr[mid] == input){
			return mid;
		}
		else if(arr[mid] < input){
			l = mid + 1;
		}
		else {
			r = mid - 1;

	}
	}

}

int main(){
	int input;
	cin>>input;
	int answer = findmid(input);
	cout<<answer;
	return 0;
}
