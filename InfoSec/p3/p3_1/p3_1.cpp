#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    try
    {
    	ofstream img ("p3img.bmp",ios::trunc);
	    ofstream txt ("p3.txt",ios::trunc|ios::binary);
	    ifstream iout("../iout.txt",ios::binary);
	    ifstream tout("../tout.txt");
	}catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
    

    int c;
    while(tout>>c)
    {
        txt << (char)c;
    }
    
    char s;
    while(iout)
    {
        iout.get(s);
        img.put(s);
    }

    img.close();
    txt.close();
    iout.close();
    tout.close();


    //char tt = getchar();
    return 0;
}
