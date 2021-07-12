#include <bits/stdc++.h>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

void print(int arrCount[])
{
	for(int i = 0; i < 9; i++)
    {
	    cout << arrCount[i] <<" ";
    }
	cout << arrCount[9] <<'\n';
}

void init(int cnt[],string present)
{
    fill(cnt, cnt + 10, 0);
    present.assign(10, '0');
}

int main()
{
	
	unordered_map<char, string> dictionary
	{
	    {'c', "0111001111"},
	    {'d', "0111001110"},
	    {'e', "0111001100"},
	    {'f', "0111001000"},
	    {'g', "0111000000"},
	    {'a', "0110000000"},
	    {'b', "0100000000"},
	    {'C', "0010000000"},
	    {'D', "1111001110"},
	    {'E', "1111001100"},
	    {'F', "1111001000"},
	    {'G', "1111000000"},
	    {'A', "1110000000"},
	    {'B', "1100000000"}
	};

	int t;
	int arrCount[10];
	
	string buffer;
	
	(cin >> t).ignore();
	
	while(t--)
	{
		string arrOld="0000000000";
		init(arrCount,arrOld);
		
		getline(cin,buffer);
		
		for(char a : buffer)
		{

			for(int i = 0; i < 10; ++i)
			{
				if((dictionary[a][i] == '1') && (arrOld[i] == '0'))arrCount[i]++;
				//cout<<i<<": "<<dictionary[a][i]<<" "<<arrOld[i]<<" count: "<<arrCount[i]<<endl;
			}//puts("");
            arrOld = dictionary[a];
		}
		
		print(arrCount);
	}
	
	
    return 0;
}
