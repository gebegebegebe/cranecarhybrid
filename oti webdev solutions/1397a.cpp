#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int  count2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};   
    string str;
    vector<int> vec;
    int iteration;
    int count;
    int total = 0;
    cin >> iteration; 
    for (int i = 0 ; i < iteration ; i++){
        cin >> count;
        for (int k = 0 ; k < count ; k++){
            cin >> str;
            
            for (int j = 0 ; j < str.length() ; j++){
                for (int coun = 0 ; coun < 26 ; coun++){
                    if (str[j] == arr[coun]){
                        count2[coun] += 1;
                    }
                }
            }
 
        }
        for(int i = 0 ; i < 26 ; i++){
            if(count2[i] != 0){
                if(count2[i] % count != 0){
                    total += 1;
                }
            }
        }
        if(total!=0){
            vec.push_back(0);
        }
        else{
            vec.push_back(1);
        }
        for(int i = 0 ; i < 26 ; i++){
            count2[i] = 0;
        }
        total = 0;
    }
    for (int i = 0 ; i < iteration ; i++){
        if (vec[i] == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
 
}