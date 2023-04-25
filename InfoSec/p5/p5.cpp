#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;



int main()
{
    uint32_t arr[] = {1, 1, 2, 6, 24
                     ,120, 720, 5040, 40320
                     ,362880, 3628800, 39916800, 479001600};

    cout << "input a integer num:";
    uint32_t num;
    cin >> num;
    cout << (((arr[num-1] % num) == (num - 1)) ? "Prime" : "Not Prime") ;
    return 0;
}
