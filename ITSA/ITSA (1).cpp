#include <bits/stdc++.h>
using namespace std;
int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    
    while(n--)
    {
    	string s;
    	set<int> set;
    	getline(cin, s);
    	cout << s.size()<<' ';
    	for(int i = 0; i < s.size();i++)
    		set.insert(s[i]);
    	cout << set.size() <<'\n';
	}
    return 0;
}