#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10

size_t checkValue(char begin[])
{
	char array[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'J', 'K', 'L','M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V','X', 'Y', 'W', 'Z', 'I','O'};
    int arrB[26]={10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
	long long arrC[SIZE]={};
		if(strlen(begin)!=10)
			return -1;
			
		if(!isupper(begin[0]))
			return  -2;
			
		for(size_t i=1;i<=(strlen(begin)-1);i++)
			if(!isdigit(begin[i]))
				return -3;
		

			int itr;
			for(int i=0;i<26;i++)
   				if(begin[0] == array[i])
   					itr = arrB[i];
   		
   			itr = (itr/10) + (itr%10)*9;
   			for(int i=1;i<=9;i++)
   			{
   				long long tmp = strtoll(begin+i,  NULL, 0);
   				while(tmp>10)
   					tmp /= 10;
   				arrC[i] = tmp;
			}
   			long long sum = itr;
			for(int i=1;i<=8;i++)
			{
				int j = 9-i;
				sum += arrC[i]*j;
			}
			sum += arrC[9];

   			if(sum%10 != 0)
   			{
   				return 0;
   				
			}
   			else
   			{
   				return 1;
			}	
}

void checkID()
{
	puts("Your command is ::National ID check::");
	
	char begin[SIZE+1]="";

	/*do
	{*/
		printf("Enter your National ID (A uppercase with nine numbers):");
		scanf("%s",&begin);
		
		if(checkValue(begin) == -1)
		{
			puts("!!!");
			puts("Error format! Check your ID lenth!!");
			puts("!!!");
		}
		if(checkValue(begin) == -2)
		{
			puts("!!!");
			puts("Error format! Check your FIRST is a uppercase!!");
			puts("!!!");
		}
		if(checkValue(begin) == -3)
		{
			puts("!!!");
			printf("Error format!The some words is not isdigit expect the first!!\n");
			puts("!!!");
		}
		else if(checkValue(begin) == 1)
		{
			puts("");
   			puts("---OOOOO_ real ID _OOOOO---");
   			puts("");
		}
		else if(checkValue(begin) == 0)
		{
			puts("");
   			puts("---XXXXX_ fake ID _XXXXX---");
   			puts("");
		}
	//}while(! (strcmp(begin,"#") ==0));
	puts("");
}

int alphaToInt(char zone)
{
	if(zone >= 65 && zone <=72)
		return (zone-55);
	if(zone == 73)
		return (zone-39);
	if(zone >= 74 && zone <=78)
		return (zone-56);	
	if(zone == 79)
		return (zone-44);
	if(zone >= 80 && zone <=86)
		return (zone-57);
	if(zone == 87)
		return (zone-55);	
	if(zone >= 88 && zone <=89)
		return (zone-58);	
	if(zone == 90)
		return (zone-57);	
			
	return 0;
}

int countValue(const char* iarray)
{
	int result = alphaToInt(iarray[0])/10;
	result += (alphaToInt(iarray[0])%10)*9;
	for(size_t i=8;i>=1;i--)
		result += i * (iarray[9-i]-48);
	return result;
}

void generation()
{
	char city;
	printf("Enter your city code:");
	scanf("%s",&city);
	char product[SIZE+1]="";
	product[0] = city;
	srand(time(NULL)%32767);
	for(size_t i=1; i<=(SIZE-2) ;i++)
	{
		if(i == 1)
		{
			size_t tmp = rand()%2;
			if(tmp)product[i] = '2';
			else product[i] = '1';
		}
		else
		product[i] = (rand()%10)+48;
	}
	product[SIZE-1] = 10 - (countValue(product)%10) + 48;
	if(product[SIZE-1] ==58)
		product[SIZE-1] -= 10;
	product[SIZE] = '\0';

	printf("\n\nHere you are:%s\n",product);
	puts("");
}

void findFirstLetter()
{
	char array[26] = {'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'J', 'K', 'L','M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V','X', 'Y', 'W', 'Z', 'I','O'};
	char input[10];
	char id[SIZE+1];
	printf("Enter your last 9 numbers:");
	scanf("%s",input);
	strncpy(id+1,input,9);
	printf("You can use : ");
	id[SIZE]='\0';
	for(int i=0;i<26;i++)
	{
		id[0] = array[i];
		if(checkValue(id) == 1)
			printf("%c ",array[i]);
	}
	puts("");
}

int main()
{
	size_t cmdCode;
	do
	{
		puts("==============================");
		puts(" (0) Exit\n (1) National ID check\n (2) National ID generating\n (3) Find the uppercases can be used\n");
		puts("==============================");
		printf("Enter your command code : ");
		scanf("%d",&cmdCode);
		switch(cmdCode)
		{
			case 0:
				break;
			case 1:
				checkID();
				break;
			case 2:
				generation();
				break;
			case 3:	
				findFirstLetter();
				break;
			default:
				puts("Error code! Please again!!\n");
				continue;
				break;
		}
	}while(cmdCode != 0);
	
	puts("Good bye!!");
	return 0;
}
