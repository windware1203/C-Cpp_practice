#include <bits/stdc++.h>
using namespace std;

struct Item{
	string id,name,num;	
};

int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(0);
   
    Item arr[5] = { {"123","iPhone_13","12"},
					{"456","iPad","5"},
					{"789","AirPods_Pro","14"},
					{"321","iPhone_14","0"},
					{"654","Apple_Watch","6"}};
    
    while(1)
    {
    	int n;
    	cin >> n;
    	if(n == 0)break;
    	
    	string s;
    	cin >> s;
    	bool flag = 0;
    	if(n == 1)
    	{
    		for(int i = 0; i < 5;i++)
    		{
    			if(arr[i].id == s)
    			{
    				flag = 1;
    				cout << arr[i].id <<' ' << arr[i].name << ' ' << arr[i].num <<'\n';
				}
			}
		}
		else
		{
			for(int i = 0; i < 5;i++)
    		{
    			if(arr[i].name == s)
    			{
    				flag = 1;
    				cout << arr[i].id <<' ' << arr[i].name << ' ' << arr[i].num <<'\n';
				}
			}
		}
		if(!flag)cout <<"404\n";
	}
    return 0;
}