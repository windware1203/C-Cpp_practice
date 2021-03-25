#include <bits/stdc++.h>
#define MAX 100
using namespace std;
void add(int *a, int *b, int *c)
{
	int carry = 0;
	memset(c, 0, sizeof(int)*MAX);
	for(int i = 0 ; i<MAX ; ++i)
	{
		c[i] = a[i] + b[i] + carry;
		carry = c[i]/10;
		c[i] %= 10;
	}
}
void mul( int *a, int *b,int *rst)
{
    int i, j, carry;
    memset(rst, 0, sizeof(int)*MAX); // clean 0
    for(i=0; i<MAX; ++i) {
        if(a[i]==0) continue;
        for(j=0; i+j<MAX; ++j)
            rst[i+j]+= a[i]*b[j];
    }
    // move all
    for(carry=i=0; i<MAX; ++i) {
        rst[i]+=carry;
        carry = rst[i] / 10;
        rst[i] %= 10;
    }
}
void b_print(int *big)
{
    int i=MAX-1;
    for(i=MAX-1;i>0 && big[i]==0; --i);
    while(i>=0)
		printf("%d", big[i]), --i;
}
void read_from_int(int *big, int x)
{
    int i=0;
    memset(big, 0, sizeof(int)*MAX); 
    while(x!=0){
        big[i++]=x%10;
        x/=10;
    }
}
void read_from_string(int *big, string str)
{
    int i=0, len=str.size();
    memset(big, 0, sizeof(int)*MAX);
    for(i=len-1; i>=0; --i)
        big[len - i - 1] = str[i] - '0';
}

int main()
{
	string input;
	while(cout<<"enter your formula:" && cin>>input)
	{ 
		int len = input.size();
		while(len > 1500)//input error check
		{
			cout<<"Error! Too long!\n";
			cout<<"enter your formula:";
			cin>>input;
		}
		if(input == "@")
			break;
		char buffer[1500];
		strcpy(buffer,input.c_str()); 
		vector <string> valueArr;
		vector <char> operatorArr;
		char* record; 
		record = strtok(buffer, "*+");//push value into vector
        	do
			{
       		    valueArr.push_back(record);
        	    record = strtok(NULL, "*+");
      	  	}while(record);
      	for(auto index : input)//push operator into vector
      	{
      		if(index=='+' or index=='*')
      			operatorArr.push_back(index);
		}
		int operatorLen = operatorArr.size();
		int valueLen = valueArr.size();
		vector <int*> intArr;
		for(auto n:valueArr)//chang value into int array
		{
			int valueOne[MAX];
			read_from_string(valueOne,n);
			intArr.push_back(valueOne);
		}
		int intArrLen = intArr.size();
    	for(int i = 0 ; i<operatorLen ; i++)
    	{
    		if(operatorArr[i] == '*')
    		{
    			int valueMul[MAX] = {};
    			if(operatorArr[i+1] == '*')
    			{
    				mul(intArr[i],intArr[i+1], valueMul);
    				intArr[i]={0};
    				intArr[i+1]=valueMul;
				}
				else
				{
    				mul(intArr[i],intArr[i+1], valueMul);
    				intArr[i+1]={0};
    				intArr[i]=valueMul;
				}
			}
		}
		for(int i = 0 ; i<operatorLen ; i++)
		{
			int valueAdd[MAX]={};
			add(intArr[i],intArr[i+1], valueAdd);
    		intArr[i]={0};
    		intArr[i+1]=valueAdd;
		}
		int* valueEnd = {};
		valueEnd = intArr.back();
		for(int i = 4 ; i<MAX ; i++)
			valueEnd[i] = 0;
		b_print(valueEnd);
    } 
 	return 0;
}

