#include <iostream>
#include <vector>
using namespace std;

int solver(int a, int b){
    
}

int main()
{
    int l,r;
    cin >> l >> r;
    
    for (int j = r ; j > l ; j--){
        for (int i = l ; i < r ; i++){
            if (j%i == 0){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1;
    return 0;
}
