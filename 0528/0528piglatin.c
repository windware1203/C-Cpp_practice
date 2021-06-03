#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void pigLatin(const char*);

char* doubleVowel(char* instring)
{
	const char* vowel={"AEIOUaeiou\0"};
	char outstring[45];
	char* output = malloc(1000000);
	strcpy(output,"");
	strcpy(outstring,instring);
	outstring[0] = tolower(outstring[0]);
	outstring[strlen(outstring)-1] = '\0';
	size_t sz_s = strlen(instring);                            
    size_t sz = sz_s + 1;
    char** valueArr=malloc(sz * sizeof(char)*sizeof(char)); 
    int tmp = 0;
	//record = strtok(buffer, " ");//push value into vector
	char* tokenPtr = strtok(outstring," ");
	int len = 0;
    while(tokenPtr != NULL)
	{
		char* haystack = malloc(10000);
		strcpy(haystack,tokenPtr);
		size_t szp_s = strlen(haystack);                            
   	 	size_t szp = szp_s + 10;
   		char *out = malloc(10000); 
   		haystack[0] = tolower(haystack[0]);
		strcpy(out,haystack);
   		char vowel[]="AEIOUaeiou";
   		char value = *strpbrk(haystack,vowel);
   		int itr = -1;
   		for(int i=0;i<szp_s;i++)
   		{	
			   if(haystack[i]==value)
   			{
				itr=i;
				break;
			}
		}
		strcpy(out+itr+1,haystack+itr);
		//printf("%s\n",out);
		//len += strlen(out);
		//strcpy(output+len,out);
		strcat(output,out);
		//printf("%s ",out);
		strcat(output," ");	
		
       	free(out);
        tokenPtr = strtok(NULL, " ");
    }
	//output[sz_s] ='\0';
	strcat(output,".");
	output[0] = toupper(output[0]);
	return output;
	free(output);
}

int main()
{
	srand(time(NULL)%32767);
	const char* word[4][5] = {"the","a","one","some","any",
	"boy","girl","dog","town","car",
	"drove","jumped","ran","walked","skipped",
	"to","from","over","under","on"};
	char sentence[20][35]={'\0'};
	puts("===============\nSource sentence:\n===============");
	for(size_t i=0;i<=19;i++)
	{
		for(size_t j=0;j<=5;j++)
		{
			strcat(sentence[i],word[j%4][rand()%5]);
			if( j!= 5)
				strcat(sentence[i]," ");
			else
				strcat(sentence[i],".");
		}
		sentence[i][0] = toupper(sentence[i][0]);
		printf("[%d]\t%s\n",i+1,sentence+i);
	}
	printf("\n");
	//getchar();
	puts("===============\nDouble Vowel sentence:\n===============\n");
	for(size_t i=0;i<=19;i++)
		printf("[%d]\t%s\n",i+1,doubleVowel(sentence[i]));
		
	puts("");puts("");
	puts("===============\npigLatin sentence:\n===============\n");
	for(size_t i=0;i<=19;i++)
	{
		printf("[%d]\t",i+1);
		pigLatin(doubleVowel(sentence[i]));
	}
	return 0;
}

void pigLatin(const char*instring)
{
	char outstring[45];
	strcpy(outstring,instring);
	outstring[0] = tolower(outstring[0]);
	outstring[strlen(outstring)-1] = '\0';
	
	char* tokenPtr = strtok(outstring," ");
	int c = 0;
	while(tokenPtr != NULL){
		
		if(strlen(tokenPtr) != 1)
		{
			char temp = tokenPtr[0];
			for(size_t i = 0;i <= strlen(tokenPtr)-2;i++)
				tokenPtr[i] = tokenPtr[i+1];
			tokenPtr[strlen(tokenPtr)-1] = temp;
		}
		if(c == 0)
		{
			tokenPtr[0] = toupper(tokenPtr[0]);
			printf("%say ",tokenPtr);
			c++;
		}
		else
		{
			printf("%say ",tokenPtr);
		}
		
		tokenPtr = strtok(NULL," ");
	}
	printf(".\n");	
}

  	
