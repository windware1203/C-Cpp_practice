#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    
    ofstream img ("p2img.bmp",ios::trunc|ios::binary);
    ofstream txt ("p2.txt",ios::trunc|ios::binary);
    ifstream iout("iout.txt",ios::binary);
    ifstream tout("tout.txt",ios::binary);

    cout << 's' <<(char)32 << 's';
    

    if(!iout.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout << ".........OK1!........\n";
    if(!tout.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout <<".........OK1~........\n";

    int c;
    while(tout>>c)
    {
        
        txt << (char)c;
    }
    
    while(iout>>c)
    {
        img << (char)c;
    }

    img.close();
    txt.close();
    iout.close();
    tout.close();


    char tt = getchar();
    return 0;
}
