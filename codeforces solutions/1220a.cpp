#include <bits/stdc++.h> 
using namespace std;

int main(){
	string input;
	int length;
	int arr[length] = {};
	int countn = 0;
	int countz = 0;
	int countt = 0;
	cin>>length;
	cin>>input;
	for (int i = 0 ; i<length ; ++i){
		if (input[i] == 'n'){
			countn += 1;
			arr[i] = 1;
		}
		else if (input[i] == 'z'){
			countz += 1;
			arr[i] = 0;
		}
		else{}
	}
	countt = countn + countz;
	sort(arr, arr+countt ,greater<int>());
	for (int i = 0 ; i < countt ; ++i){
		cout<<arr[i]<<" ";
	}

}