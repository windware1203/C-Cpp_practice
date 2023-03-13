#include <iostream>
#include <vector>
#include <algorithm>
int16_t powB(int8_t power);
int16_t toDec(std::string source);

int main()
{
    std::cout << "Enter a 8 bits Binary Number(00000000~11111111)" << std::endl;
    std::string bin;
    std::cin >> bin;
    int len = bin.size();
    len < 8 ? len = 8 - len : len = 0;
    reverse(bin.begin(), bin.end());
    while(len--)bin += "0";
    std::cout << toDec(bin) << std::endl;
    
    return 0;
}

int16_t powB(int8_t power)
{
    int16_t reslut = 1;
    while (power--)
    {
        reslut *= 2;
    }
    return reslut;
}
int16_t toDec(std::string source)
{
    int16_t result = 0;
    for (size_t i = 0; i < source.size(); i++)
    {
        result += (source[i] == '1' ? 1 : 0)*powB(i);
    }
    return result;
}