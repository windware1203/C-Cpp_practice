#include <bits/stdc++.h>
using namespace std;
int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int64_t> big;
    vector<int64_t> small;
    
    big.push_back(0);
    small.push_back(1);
    for(int i = 1; i <= n;i++)
    {
    	int64_t big_num = 0, small_num = 0;
    	
    	big_num = big[i-1] + small[i-1];
    	small_num = big[i-1];
    	
    	big.push_back(big_num);
    	small.push_back(small_num);
    	
    	if(i >= 3) big[i] -= small[i-3];
	}
	
	cout<< small[n] <<'\n';
    return 0;
}