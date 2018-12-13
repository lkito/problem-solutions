#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n, cur, maxNum = 0;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> cur;
        if(m.count(cur) == 0){
            m[cur] = 1;
        } else m[cur]++;
    }
    vector<pair<int, int> > v;
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        v.push_back(make_pair(it->first, it->second));
    }
    long long result[v.size()];
    pair<int, int> p = v.at(0);
    result[0] = (long long) p.first * p.second;
    if(v.size() > 1){
        p = v.at(1);
        result[1] = (long long) p.first * p.second;
        if(v.at(0).first < p.first - 1) result[1] += result[0];
    }
    if(v.size() > 2){
        p = v.at(2);
        result[2] = result[0];
        if(v.at(1).first < p.first - 1) result[2] = result[1];
        result[2] += (long long) p.first * p.second;
    }
    for(int i = 3; i < v.size(); i++){
        p = v.at(i);
        result[i] = max(result[i - 2], result[i - 3]);
        if(v.at(i - 1).first < p.first - 1) result[i] = max(result[i], result[i - 1]);
        result[i] += (long long) p.first * p.second;
    }
    if(v.size() == 1){
        cout << result[v.size() - 1] << endl;
    } else cout << max(result[v.size() - 1], result[v.size() - 2]) << endl;
    return 0;
}