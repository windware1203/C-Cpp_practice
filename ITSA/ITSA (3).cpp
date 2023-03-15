#include <bits/stdc++.h>
using namespace std;
int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--)
    {
    	int s;
    	cin >> s;
    	if(s <= 1500)cout << 70 <<'\n';
    	else
    	{
    		int cost = 75;
    		s -= 1500;
    		cost += (s/500*5);
    		cout << cost <<'\n';
		}
	}
    return 0;
}