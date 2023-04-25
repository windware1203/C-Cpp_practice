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
    uint32_t factorial[] = {1, 1, 2, 6, 24
                     ,120, 720, 5040, 40320
                     ,362880, 3628800, 39916800, 479001600};

    cout << "input a integer num:";
    uint32_t num;
    cin >> num;
    
    cout << (((factorial[num-1] % num) == (num - 1)) ? "Prime" : "Not Prime") ;
    return 0;
}
