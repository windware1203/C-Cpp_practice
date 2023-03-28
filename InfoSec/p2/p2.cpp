#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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

    char c;
    while(txt>>c)
    {
        
        tout  <<hex <<(int)c;
        tout << ' ';
    }
    

    
    while(img>>c)
    {
        iout << hex <<(int)c;
        iout << ' ';
    } 

    img.close();
    txt.close();
    iout.close();
    tout.close();

    return 0;
}
