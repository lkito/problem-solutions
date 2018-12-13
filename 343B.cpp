#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv){
    string s = "";
    cin >> s;
    stack <int> st1;
    stack <int> st2;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+'){
            st1.push(1);
        } else st1.push(0);
    }
    if(st1.size() % 2 == 1){
         cout << "No" << endl;
         return 0;
    }
    int stSize = st1.size();
    int cur = 0;
    for(int k = 0; k < stSize; k++){
        cur = st1.top();
        st1.pop();
        if(!st2.empty() && st2.top() == cur){
            st2.pop();
        } else {
            st2.push(cur);
        }
    }
    if(st2.empty()){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
    return 0;
}