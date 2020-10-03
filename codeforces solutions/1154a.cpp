#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int number;
	int a,b,c;
	vector<int> value;
	for (int i = 0 ; i<4 ; ++i){
		cin>>number;
		value.push_back(number);		
	}
	for (int i = 0 ; i<4 ; ++i){
		sort(value.begin(), value.end());
	}
	for (int i = 0 ; i<4 ; ++i){
		a = value[3] - value[0];
		b = value[3] - value[1];
		c = value[3] - value[2];
	}
	cout<<a<<" "<<b<<" "<<c;
}