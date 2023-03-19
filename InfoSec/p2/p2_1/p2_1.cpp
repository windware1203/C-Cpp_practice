#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    
    ofstream img ("p2img.bmp",ios::trunc);
    ofstream txt ("p2.txt",ios::trunc);
    ifstream iout("iout.txt");
    ifstream tout("tout.txt");

    cout << 's' <<(char)32 << 's';
    

    if(!iout.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout << ".........OK!........\n";
    if(!tout.is_open())
        cout << ".........NO FOUND........" << endl;
    else
        cout <<".........OK~........\n";

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