//Sparse Table Algorithm
	
#include <stdio.h>

#define MAX_N 100000
#define MAX_L 18
 
int A[MAX_L][MAX_N];

int N, M;
 
	inline int MIN (int a, int b){
	     if (a < b) 
	     	return a; 
	     else 
	     	return b;
	}
 
	void rmq (){
		int i, j;
 
	    for (i = 1; 1 << i <= N; ++i)
		for (j = 0; j < N - (1 << i) + 1; ++j)
		   A[i][j] = MIN (A[i - 1][j], A[i - 1][j + (1 << (i - 1))]);
	}
 
 
int main (){
	freopen ("test0.in", "r", stdin);
	freopen ("test0.out", "w", stdout);
 
	scanf ("%d %d", &N, &M);
	int i;
	for (i = 0; i < N; ++i)
		scanf ("%d", A[0] + i);
 
	rmq();
 
	int x, y;
	for (i = 0; i < M; ++i){
		scanf("%d %d", &x, &y);
		int L = y - x + 1;
		int k = 1;
		int kc = 0;
		for (; k << 1 <= L; k <<= 1, ++kc);
			printf ("%d\n", MIN (A[kc][x], A[kc][y - k + 1]));
	}
 
	return 0;
}