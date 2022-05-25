#include <iostream>
using namespace std;
double f[50][50][50];
int a[50];//1 ~ n, n + 1 ~ n + m
int n,m,d;
void solve() {
	for(int i = 1;i <= n + m;i++) {
		f[0][i][a[i]] = 1;
		for(int j = 0;j < a[i];j++) {
			f[0][i][j] = 0;
		}
	}
	for(int k = 1;k <= d;k++) {
		for(int i = 1;i <= n + m;i++) {
			int cnt = 0;
			for(int j = 1;j <= n + m;j++) {
				if(f[k-1][j][0] == 0) {
					cnt++;
				}
			}
			double kk = (double) 1 / cnt;
			for(int j = a[i];j >= 0;j--) {
				f[k][i][j] = kk*f[k-1][i][j] + kk * f[k-1][i][j+1];
			}
		}
	}
	double ans = 0.0;
	for(int i = n + 1;i <= n+m;i++) {
		ans += f[d][i][0];
	}
	printf("%.4lf", ans);
	for(int k = 0;k <= d;k++) {
		cout << "k=" << k << endl;
		for (int i = 1; i <= n + m; i ++) {
			cout << "i=" << i << endl;
			for (int j = 0; j <= a[i]; j ++) {
				cout << f[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
double dfs(int x) {
	if(x == 0) {
		bool flag = true;
		for(int j = n + 1;j <= n + m;j++) {
			if(a[j] != 0) flag = false;
		}
		if(flag) return 1.0;
		else return 0.0;
	}
	double ans = 0;
	int check = 0;
	for(int i = 1;i <= n + m;i++) {
		if(a[i] > 0) {
			int cnt = 0;
			for(int j = 1;j <= n + m;j++) cnt += (a[j] != 0);
			a[i]--;
			ans += (1.0/cnt)*dfs(x-1);
			a[i]++;
		}
	}
	return ans;
}
int main () {
	cin >> n >> m >> d;
	for(int i = 1;i <= n + m;i++) {
		cin >> a[i];
	}
	solve();
	//printf("%.4lf",dfs(d));
	return 0;
}
