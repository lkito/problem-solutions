#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int elem, quer, cur;
    cin >> elem;
    cin >> quer;
    int arr[elem + 1];
    int posArr[elem + 1];
    for(int i = 1; i < elem + 1; i++){
        cin >> cur;
        arr[i] = cur;
        if(i == 1) posArr[i] = 1;
        if(cur == arr[i - 1]){
            posArr[i] = posArr[i - 1];
        } else {
            posArr[i] = i - 1;
        }
    }
    int left, right, x;
    for(int k = 0; k < quer; k++){
        cin >> left;
        cin >> right;
        cin >> x;
        if(arr[right] != x){
            cout << right << endl;
        } else if(posArr[right] < left){
            cout << "-1" << endl;
        } else cout << posArr[right] << endl;
    }
    return 0;
}