#include <iostream>
#include <map>
#include <limits.h>
using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int arr[7]; //B u l b a s r
    for(int j = 0; j < 7; j++){
        arr[j] = 0;
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B') arr[0]++;
        if(s[i] == 'u') arr[1]++;
        if(s[i] == 'l') arr[2]++;
        if(s[i] == 'b') arr[3]++;
        if(s[i] == 'a') arr[4]++;
        if(s[i] == 's') arr[5]++;
        if(s[i] == 'r') arr[6]++;
    }
    arr[1] /=2;
    arr[4] /=2;
    int min = INT_MAX;
    for(int k = 0; k < 7; k++){
        if(arr[k] < min) min = arr[k];
    }
    cout << min << endl;
    return 0;
}