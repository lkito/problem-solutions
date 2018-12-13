#include <iostream>
#include <map>
#include <math.h>
#include <set>
using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(0);
    long long n, ar[100001], result = 0;
    cin >> n;
    map<long, int> map;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        for(int j = 0; j <= 32; j++){
            result += map[pow(2, j) - ar[i]];
        }
        map[ar[i]]++;
    }
    cout << result << endl;
    return 0;
}