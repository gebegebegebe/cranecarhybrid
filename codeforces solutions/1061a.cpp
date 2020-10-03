#include <iostream>
using namespace std;

int main(){
	int outputs;
	int outputf = 0;
	int remainder;
	int n;
	int s;
	cin>>n;
	cin>>s;
	remainder = s;
	for (int i = n ; i>0 ; --i){
		if (i<=remainder){
			outputs = remainder/i;
			outputf += outputs;
			remainder -= i*outputs;	
		}
		else{}
	}
	cout<<outputf;
}