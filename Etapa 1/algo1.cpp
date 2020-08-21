//Square Root Decomposition

#include <bits/stdc++.h>
using namespace std;
 
int n, m, rmq[20][100005], lg[100005], a, b;
 
ifstream f ("test0.in");
ofstream g ("test0.out");
 
int main (){
    f >> n >> m;
    for (int i = 0; i < n; i++){
        f >> rmq[1][i];
    }

    lg[1] = 1;
    for (int i = 2; i <= 100003; i++){
        lg[i] = lg[i / 2] + 1;
    }

    int d = 2;
    for(int i = 2; i <= lg[n]; i++){
        for (int j = 0; j < n - d + 1; j++){
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (d / 2)]);
        }
        d *= 2;
    }
 
    for (int i = 0; i < m; i++){
        f >> a >> b;
 
        int l = lg[b - a + 1];
        int p = 1 << (l - 1);
        g << min(rmq[l][a], rmq[l][b - p + 1]) << '\n';
 
    }
 
}
