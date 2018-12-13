#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv){
    map<int, int> m;
    stack<int> s;
    int size;
    cin >> size;
    int arr[size];
    vector<int> result;
    result.push_back(0);
    int curInt;
    for(int i = 0; i < size; i++){
        cin >> curInt;
        if(i == 0){
            arr[i] = curInt;
        } else {
            arr[i] = arr[i - 1] + curInt;
        }
    }
    int cur;
    for(int k = 0; k < size; k++){
        cin >> cur;
        s.push(cur);
    }
    int left, right, lCount, rCount, curSum, max = 0;
    for(int j = 0; j < s.size(); j++){
        cur = s.top();
        s.pop();
        lCount = m.count(cur - 1);
        rCount = m.count(cur + 1);
        if(lCount > 0 && rCount > 0){
            m[m[cur - 1]] = m[cur + 1];
            m[m[cur + 1]] = m[cur - 1];
            right = m[cur + 1];
            left = m[cur - 1];
        } else if(lCount > 0){
            right = cur;
            m[cur] = m[cur - 1];
            left = m[cur];
            m[left] = cur;
        } else if(rCount > 0){
            right = m[cur + 1];
            left = cur;
            m[right] = m[cur];
            m[cur] = right;
        } else {
            m[cur] = cur;
            left = cur;
            right = cur;
        }
        if(left == 0){
            curSum = arr[right];
        } else {
            curSum = arr[right] - arr[left - 1];
        }
        if(curSum > max) max = curSum;
        result.push_back(max);
    }
    for(int f = result.size() - 2; f >= 0; f--){
        cout << result[f] << endl;
    }
    return 0;
}