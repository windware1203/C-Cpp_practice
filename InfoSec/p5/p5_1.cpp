#include <iostream>
#include <map>
using namespace std;

map<uint32_t, uint32_t> factorize(uint32_t n, map<uint32_t, uint32_t> map)
{
    while(n % 2 == 0)
    {
        map[2]++;
        n >>= 1;
    }

    for(uint32_t i = 3; i*i <= n; i += 2)
    {
        while( n % i == 0)
        {
            map[i]++;
            n /= i;
        }
    }

    if(n > 1)map[n] = 1;
    
    return map;
}

int main()
{
    uint32_t num{0};
    cout << "input the number:";
    cin >> num;
    map<uint32_t, uint32_t> map;
    map = factorize(num, map);

    cout << "the factors: ";
    for(auto i : map)
    {
        cout << i.first << '^'
        << i.second <<" ";
    }
    cout <<'\n';
    return 0;
}
