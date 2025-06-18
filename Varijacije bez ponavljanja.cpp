#include <iostream>
#include <vector>
using namespace std;


void bezp(int n, int k, vector<int>& x, vector<bool>& zauzet) {
    if (x.size() == k) {
        for (int j=0;j<x.size();j++) cout << x[j] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!zauzet[i]) {
            zauzet[i] = true;
            x.push_back(i);
            bezp(n, k, x, zauzet);
            x.pop_back();    
            zauzet[i] = false;
        }
    }
}

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> x;       
    vector<bool> zauzet(n+1, false);
    bezp(n, k, x, zauzet);
    return 0;
}