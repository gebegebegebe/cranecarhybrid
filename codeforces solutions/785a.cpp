#include<bits/stdc++.h>
using namespace std;

int main(){
	int count;
	string s;
	map<string,int> m;
	m["Tetrahedron"] 	= 4;
	m["Cube"] 			= 6;
	m["Octahedron"]		= 8;
	m["Dodecahedron"]   = 12;
	m["Icosahedron"] 	= 20;
	cin>>count;
	int total = 0;
	for(int i = 0; i<count ; ++i){
		cin>>s;
		total += m[s];
	}
	cout<<total<<endl;
}