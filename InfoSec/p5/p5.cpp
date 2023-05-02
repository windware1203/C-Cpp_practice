/*
//	Name: Prime number test
//	Copyright: Takeda Nana - wind.ware1203@gmail.com
//	Author: Takeda Nana(Cheng-Hao,Zhang)
//	Date: 25/04/23 19:09
//
//	Description: 
// 	This program implemented by Wilson's theorem for testing the prime number.
// 	Following is the content:
// 	A natural number n>1 will be prime if and only if
// 	(n−1)! + 1≡ 0(mod n) => (n−1)! mod n = n-1
// 
// 	This test is not recommended for practical use,
// 	since the factorial involved rapidly becomes very large. 
// 	Because 123456789 is not very large, it used in this project.
//
*/
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	//
    vector<uint64_t> factorial= {1, 1};
    uint64_t num;
    do{
	    cout << "input a integer num(0 for end):";
	    cin >> num;
	    if(num == 0)
		{
			break;
		}
		if(num == 2)
		{
			cout<< "Prime\n";
			continue;
		}
	    if(!(num % 2) || num == 1)
		{
			cout << "Not Prime\n";
			continue;
		}
	    for(uint64_t i = 2; i <= num; i++)
	    {
	    	if((uint64_t)(factorial.size()-1) < i)
	    	{
	    		factorial.push_back((factorial[i-1]*i)%num);
			}
		}
		cout << (((factorial[num-1]%num) == (num - 1)) ? "Prime\n" : "Not Prime\n") ;
	}while(num);
	
    
    return 0;
}
