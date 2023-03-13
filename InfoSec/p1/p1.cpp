#include <iostream>
#include <vector>
#include <algorithm>
std::string toBinary(int16_t source, std::vector<char> arr);

int main()
{
    std::cout << "Enter a 8 bits Digital Number(0-255)" << std::endl;
    int16_t num;
    std::vector<char> arr;
    std::cin >> num;
    std::cout << toBinary(num,arr) << std::endl;
    
    return 0;
}

std::string toBinary(int16_t source, std::vector<char> arr)
{
    while(source)
    {
        arr.push_back(source%2 ? '1' : '0');
        source /= 2;
    }
    int len = arr.size();
    len < 8 ? len = 8 - len : len = 0;
    while(len--)arr.push_back('0');
    reverse(arr.begin(), arr.end());
    std::string str(arr.begin(), arr.end());
    return str;
}