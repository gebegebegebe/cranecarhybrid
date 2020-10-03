#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string str;
    vector<int> vec;
    int iteration;
    int count;
    int total = 0;
    cin >> iteration; 
    for (int i = 0 ; i < iteration ; i++){
        cin >> count;
        for (int j = 0 ; j < count ; j++){
            cin >> str;
            total += str.length();
        }
        if (total % count == 0){
            vec.push_back(1);
        }
        else{
            vec.push_back(0);
        }
        total = 0;
    }
    for(int i = 0 ; i < vec.size() ; i++){
        if (vec[i] == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}