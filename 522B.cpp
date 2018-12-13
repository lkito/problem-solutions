#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int widths[n];
    int max = 0;
    int maxIndex;
    int secondMax = 0;
    int curW;
    int curH;
    int wSum = 0;
    for(int i = 0; i < n; i++){
        cin >> curW;
        cin >> curH;
        wSum += curW;
        widths[i] = curW;
        if(curH > max){
            secondMax = max;
            max = curH;
            maxIndex = i;
        } else if(curH > secondMax){
            secondMax = curH;
        }
    }
    for(int k = 0; k < n; k++){
        int curWidth = wSum - widths[k];
        int curHeight;
        if(k == maxIndex){
            curHeight = secondMax;
        } else {
            curHeight = max;
        }
        cout << curWidth * curHeight << " ";
    }
    return 0;
}