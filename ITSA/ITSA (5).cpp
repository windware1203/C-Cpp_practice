#include <bits/stdc++.h>
using namespace std;

int f(int get,int now)
{
	if(get > now)return 0;
	if(get == now)return 1;
	
	return f(1,now-get)+f(2,now-get);
}

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
    	cout << f(1,s)+f(2,s) << '\n';
	}
    return 0;
}