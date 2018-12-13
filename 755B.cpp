#include <iostream>
#include <set>
using namespace std;

int main(int argc, char **argv){
    int pol, enem;
    set<string> polSet, enemSet;
    cin >> pol;
    cin >> enem;
    string cur = "";
    int commonCount = 0;
    for(int i = 0; i < pol; i++){
        cin >> cur;
        polSet.insert(cur);
    }
    for(int k = 0; k < enem; k++){
        cin >> cur;
        if(polSet.count(cur) > 0){
            commonCount++;
            polSet.erase(cur);
        } else {
            enemSet.insert(cur);
        }
    }
    int polScore = polSet.size() + commonCount % 2;
    int enemScore = enemSet.size();
    if(polScore > enemScore){
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}