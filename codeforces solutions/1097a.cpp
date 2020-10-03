#include<iostream>
#include<string>
using namespace std;

int main(){
	bool o = true;
	string input;
	string a,b,c,d,e;
	string f,g,h,j,k,l;
	cin>>input;
	cin>>a>>b>>c>>d>>e;
	for ( int i = 0 ; i<2 ; ++i){
		f = a[i];
		g = b[i];
		h = c[i];
		j = d[i];
		k = e[i];
		l = input[i];
		if (l == f || l == g || l == h || l == j || l == k || l == k){
			o = false;
			cout<<"YES";
			break;
		}
		else if (i == 1 && o == true){
			cout<<"NO";
			break;
		}
		
	}
		
}