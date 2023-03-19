#include <bits/stdc++.h>
using namespace std;


int main()
{
 	ios::sync_with_stdio(false);
    cin.tie(0);
    int arr[20] = {};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3;i <= 20;i++)
    {
    	arr[i] = arr[i-1] + arr[i-2] + 2;
	}
	
    int n;
    cin >> n;
    while(n--)
    {
    	int s;
    	cin >> s;
    	cout << arr[s-1] << '\n';
	}
    return 0;
}