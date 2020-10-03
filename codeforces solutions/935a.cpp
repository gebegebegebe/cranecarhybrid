#include<iostream>

using namespace std;

int main(){
	int input, employees;
	cin>>input;
	int max = input;
	int count = 0;
	for (int i = 1 ; i<max ; ++i){
		input -= 1;
		if (input % i == 0)
			count += 1;
		else{}
	}
	cout<<count;
	}
