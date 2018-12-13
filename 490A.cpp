#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv){
    stack<int> prg;
    stack<int> math;
    stack<int> pe;
    int n;
    cin >> n;
    int cur;
    for(int i = 1; i <= n; i++){
        cin >> cur;
        if(cur == 1){
            prg.push(i);
        } else if(cur == 2){
            math.push(i);
        } else {
            pe.push(i);
        }
    }
    int prgSize, mathSize, peSize;
    prgSize = prg.size(), mathSize = math.size(), peSize = pe.size();
    int curMin = min(prgSize, mathSize);
    curMin = min(curMin, peSize);
    cout << curMin << endl;
    for(int k = 0; k < curMin; k++){
        cout << prg.top() << " ";
        cout << math.top() << " ";
        cout << pe.top() << endl;
        prg.pop(), math.pop(), pe.pop();
    }
    return 0;
}