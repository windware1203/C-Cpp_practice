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
    	string s;
    	cin >> s;
    	int x = 0, y = 0;
    	bool flag = 1;
    	for(int i = 0 ; i < s.size(); i++)
    	{
    		if(s[i] == 'X')x++;
    		else
    		{
    			if(x > 0) x--;
    			else
    			{
    				cout << "No\n";
    				flag = 0;
    				break;
				}
			}
		}
		if(flag && (x == 0) && (y == 0)) cout << "Yes\n";
	}
    return 0;
}