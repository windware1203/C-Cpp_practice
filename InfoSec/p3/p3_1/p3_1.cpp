#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    
    ofstream img ("p3img.bmp",ios::trunc);
    ofstream txt ("p3.txt",ios::trunc|ios::binary);
    ifstream iout("../iout.txt");
    ifstream tout("../tout.txt");

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
    
    stringstream ss;
    ss << iout.rdbuf();
    string str(ss.str());
    img << str;

    img.close();
    txt.close();
    iout.close();
    tout.close();


    //char tt = getchar();
    return 0;
}
