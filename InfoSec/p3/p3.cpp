#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    fstream img ("p3img.bmp",ios::in|ios::binary);
    fstream txt ("p3.txt",ios::in|ios::binary);
    ofstream iout("iout.txt",ios::trunc);
    ofstream tout("tout.txt",ios::trunc);

    if(!img.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout << ".........OK0!........\n";
    if(!txt.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout <<".........OK0~........\n";

    int8_t c;
    while(txt >> c)
    {
        
        tout  << (int)c + 4;
        tout << ' ';
    }
   
    stringstream ss;
    ss << img.rdbuf();
    string str(ss.str());
    for( int i = 0; i < str.size();i++)
    {
         str[i] += 4;
    }
    iout << str;

    img.close();
    txt.close();
    iout.close();
    tout.close();

    return 0;
}
