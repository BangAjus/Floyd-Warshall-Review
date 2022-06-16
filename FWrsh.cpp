#include <iostream>
using namespace std;

int main(){
    int n; cout << "Masukkan jumlah vertex : "; cin >> n;
    int g[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                g[i][j] = 0;
            }
            else if(i > j){
                g[i][j] = g[j][i];
            }
            else{
                cout << "Hubungan vertex " << i << j << " : "; cin >> g[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == 0){
                    g[i][j] = 999;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == 999){
                continue;
            }
            else{
                if(i > j){
                g[i][j] = g[j][i];
            }
            else {
                cout << "Bobot vertex " << i << j << " : "; cin >> g[i][j];
            }
            }
        }
    }
    for (int k = 0; k <= n; k++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				if(i == j){
					g[i][j] = 0;
				}
				else if ((i == k) or (j == k)){
					g[i][j] = g[i][j];
				}
				else {
					if (g[i][j] < (g[i][k] + g[k][j])){
						g[i][j] = g[i][j];
					}
                    else if(g[i][j] > (g[i][k] + g[k][j]) && (g[k][j] != 999 && g[i][k] != 999)){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}
	}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){
                cout << " " << " ";
            }
            else if(i < j){
                cout << g[i][j] << " ";
            }
            else {
                cout << g[i][j] << " ";
            }
        }
        cout << endl;
    }
}
