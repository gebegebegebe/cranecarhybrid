#include<iostream>
using namespace std;

int main(){
	int	input;
	int total = 0;
	cin>>input;
	for(int i = 100; input >= 100 ; input -= i){
		if(input > 0){
			total += 1;
		}
		else{
			break;
		}
		}
	for(int i = 20; input >= 20 ; input -= i){
		if(input > 0){
			total += 1;
		}
		else{
			break;
		}
		}
	for(int i = 10; input >= 10 ; input -= i){
		if(input > 0){
			total += 1;
		}
		else{
			break;
		}
		}
	for(int i = 5; input >= 5 ; input -= i){
		if(input > 0){
			total += 1;
		}
		else{
			break;
		}
		}
	for(int i = 1; input >= 1 ; input -= i){
		if(input > 0){
			total += 1;
		}
		else{
			break;
		}
		}
	cout<<total;
}