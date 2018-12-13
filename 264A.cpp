#include <iostream>
using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'r'){
            cout << i + 1 << " ";
        }
    }
    for(int k = s.size() - 1; k >= 0; k--){
        if(s[k] == 'l'){
            cout << k + 1 << " ";
        }
    }
    return 0;
}