//Segment Tree

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

    void init(int node, int beg, int end, vector<int>& M, vector<int>& m, const vector<int>& n){
	if (beg == end)
	    M[node] = m[node] = n[beg];
	else {
	    init(node * 2, beg, (beg + end) / 2, M, m, n);
	    init(node * 2 + 1,(beg + end) / 2 + 1, end, M, m, n);
	    M[node] = max(M[2 * node], M[2 * node + 1]);
	    m[node] = min(m[2 * node], m[2 * node + 1]);
	}
    }

pair<int,int> query(int node, int beg, int end, vector<int>& M, vector<int>& m, vector<int>& n, int i, int j) {
    pair<int,int> p1, p2;

    if (end < i || beg > j)
	return make_pair(-1, -1);

    if (beg >= i && end <= j)
	return make_pair(M[node], m[node]);

    p1 = query(2 * node, beg, (beg + end) / 2, M, m, n, i, j);
    p2 = query(2 * node + 1, ((beg + end) / 2) + 1, end, M, m, n, i, j);

    if (p1 == make_pair(-1, -1))
	return p2;

    if (p2 == make_pair(-1, -1))
	return p1;

    pair<int,int> res = make_pair(max(max(0, p1.first), max(0, p2.first)), min(max(0, p1.second), max(0, p2.second)));
    return res;
}


int main(){
	freopen ("test0.in", "r", stdin);
	freopen ("test0.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> n(N), m(4 * N), M(4 * N);
    for (int i = 0; i < N; i++)
	cin >> n[i];
    init(0, 0, N - 1, M, m, n);
    vector<pair<int,int>> results;

    for (int k = 0; k < Q; k++) {
		int i, j;
		cin >> i >> j;
		i--; j--;
		pair<int,int> res = query(0, 0, N - 1, M, m, n, i, j);
		results.push_back(res);
    }

    for(int i = 0; i < results.size();i++){
        cout << results[i].second << endl;
    }
    return 0;
}