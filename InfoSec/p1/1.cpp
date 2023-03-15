#include <iostream>


int main()
{
    int m;
    std::cin >> m;

    while(m--)
    {
        int n;
        std::cin >> n;
        std::cout << n*(n+1)/2 << std::endl;
    }
    
    return 0;
}