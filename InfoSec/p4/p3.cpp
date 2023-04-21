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
		fstream img ("p3img.bmp",ios::in|ios::binary);
	    fstream txt ("p3.txt",ios::in|ios::binary);
	    ofstream iout("iout.txt",ios::trunc);
	    ofstream tout("tout.txt",ios::trunc);
	}catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }

    int8_t c;
    while(txt >> c)
    {
        
        tout  << (int)c + 4;
        tout << ' ';
    }
   
   	/*int8_t ss = 0;
   	iout.put(ss);*/
    char s;
    while(img)
    {
        img.get(s);
        s >>= 4;
        iout.put(s);
    }

    img.close();
    txt.close();
    iout.close();
    tout.close();

    return 0;
}
