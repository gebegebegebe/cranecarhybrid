#include<iostream>
#include<string>
using namespace std;

int main(){
	int count;
	string w,x,y;
	string z = "I ";
	cin>>count;
	for (int i = 1 ; i<=count ; ++i){
		z = "";
		if (i % 2 == 0){
			x = "love ";
			z = x;
		}
		else{
			y = "hate ";
			z = y;
		}
		if (i == count)
		w = "I " + z + "it ";
		else 
		w = "I " + z + "that ";
		cout<<w;
	}
	
}