#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int mas[n + 1];
    for(int i = 0; i < n + 1; i++){
        mas[i] = 0;
    }
    int cur;
    int turns = 0;
    int max;
    cin >> max;
    int last = max;
    int lastMax = max;
    mas[max] = 0;
    for(int i = 1; i < n; i++){
        cin >> cur;
        if(cur < last){
            mas[cur] = 1;
        } else if(cur > last && cur < max){
            if(lastMax == max){
                mas[cur] = 2;
            } else {
                if(cur < lastMax){
                    mas[cur] = mas[last] + 1;
                } else {
                    mas[cur] = mas[lastMax] + 1;
                }
            }
            lastMax = cur;
        } else if(cur > max){
            mas[cur] = 0;
            max = cur;
            lastMax = max;
        }
        if(mas[cur] > turns) turns = mas[cur];
        last = cur;
    }
    cout << turns  << endl;
    return 0;
}