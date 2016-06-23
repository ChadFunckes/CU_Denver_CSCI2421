#include <iostream>
using namespace std;

int coins[] { 1, 5, 10, 25 };

void getChange(int n, int coins[], int sum){
	if (sum == n)
		cout << coins[0] << "q," << coins[1] <<"d," +
		coins[2]<< "n," << coins[3] << "p";
	else{
		if (sum + 25 <= n){
			coins[0]++;
			getChange(n, coins, sum + 25);
			coins[0]--;
		}
		if (sum + 10 <= n){
			coins[1]++;
			getChange(n, coins, sum + 10);
			coins[1]--;
		}
		if (sum + 5 <= n){
			coins[2]++;
			getChange(n, coins, sum + 5);
			coins[2]--;
		}
		if (sum + 1 <= n){
			coins[3]++;
			getChange(n, coins, sum + 1);
			coins[3]--;
		}
	}
}

int main(){

	getChange(17, coins, 0);



}