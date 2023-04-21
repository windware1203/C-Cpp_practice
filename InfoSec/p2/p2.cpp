#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <cstddef>
using namespace std;

int main()
{
    fstream img ("p2img.bmp",ios::in|ios::binary);
    fstream txt ("p2.txt",ios::in|ios::binary);
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
        
        tout  <<(int)c;
        tout << ' ';
    }
   
    char s;
    while(img)
    {
        img.get(s);
        iout.put(s);
    }
    /*
    stringstream ss;
    ss << img.rdbuf();
    string str(ss.str());
    iout << str;*/

    img.close();
    txt.close();
    iout.close();
    tout.close();

    return 0;
}
