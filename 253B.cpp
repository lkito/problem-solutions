#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int ar[n + 1];
    int cur;
    for(int i = 0; i < n; i++){
        cin >> cur;
        ar[i] = cur;
    }
    sort(ar, ar + n - 1);
    int result = INT_MAX;
    int end = 1;
    for(int k = 0; k < n; k++){
        while(end < n && ar[end] <= ar[k]* 2){
            result = min(result, n - end + k - 1);
            end++;
        }
    }
    
    cout << result << endl;
    return 0;
}
