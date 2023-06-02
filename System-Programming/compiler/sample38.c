#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char stringIn[100] = {};
    char stringArray[50]  = "";
    int lineNo = 1;
    FILE *In;
    FILE *Out;
    In = fopen("sample.txt","r");
    Out = fopen("output.txt","w");
    if(In == NULL){
        printf("讀檔失敗!\n"); 
        return 0;
    }
    while(fgets(stringIn , 100, In) != NULL){
        int x = 0;
        int y = 0;
        while(stringIn[x] != '\n'){
            switch(stringIn[x]){
                case '/':
                    x++;
                    if(stringIn[x] == '/'){
                        fprintf(Out,"%d ",lineNo);
                        fprintf(Out,"SC ");
                        fgets(stringIn , 100, In);
                        lineNo++;
                        x = -1;
                        fprintf(Out,"//%s  \n",stringArray);
                        fprintf(Out,"\n");
                    }
                
                    else{
                        fprintf(Out,"%d ",lineNo);
                        fprintf(Out,"OPER ");
                        fprintf(Out,"/ \n");
                        x--;
                    }
                    break;
                case 'e':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'l':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='s')&&(stringIn[x+1]=='e')){
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"else \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop2=0;
       		 		while(loop2<50){
        				stringArray[loop2]  = ' ';
        				loop2++;
        			}
                    break;
                   case 'g':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'o':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='t')&&(stringIn[x+1]=='o')){
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"goto \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop11=0;
       		 		while(loop11<50){
        				stringArray[loop11]  = ' ';
        				loop11++;
        			}
                    break;
                  case 'u':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'n':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='s')&&(stringIn[x+1]=='i')&&(stringIn[x+2]=='g')&&(stringIn[x+3]=='n')&&(stringIn[x+4]=='e')&&(stringIn[x+5]=='d')){
                        		x++;
                        		x++;
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"unsigned \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop12=0;
       		 		while(loop12<50){
        				stringArray[loop12]  = ' ';
        				loop12++;
        			}
                    break;
                  case 't':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'y':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='p')&&(stringIn[x+1]=='e')&&(stringIn[x+2]=='d')&&(stringIn[x+3]=='e')&&(stringIn[x+4]=='f')){
                        		x++;
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"utypedef \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop13=0;
       		 		while(loop13<50){
        				stringArray[loop13]  = ' ';
        				loop13++;
        			}
                    break;
                   case 'v':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'o':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='i')&&(stringIn[x+1]=='d')){
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"void \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop14=0;
       		 		while(loop14<50){
        				stringArray[loop14]  = ' ';
        				loop14++;
        			}
                    break;
                  case 'l':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                    case 'o':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if(stringIn[x]=='n'&&stringIn[x+1]=='g'){
                			    x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"long \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop10=0;
       		 		while(loop10<30){
        				stringArray[loop10]  = ' ';
        				loop10++;
        			}
                    break;
                case 'w':
                    stringArray[y]=stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'h':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='i')&&(stringIn[x+1]=='l')&&(stringIn[x+2]=='e')){
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"while \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
            		y=0;
        			int loop3=0;
       		 		while(loop3<50){
        				stringArray[loop3]  = ' ';
        				loop3++;
        			}
                    break;
                case 'i':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                    	case 'f':
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"REWD ");
                        	fprintf(Out,"if \n");
                			break;
                		case 'n':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if(stringIn[x]=='t'){
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"int \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop1=0;
       		 		while(loop1<50){
        				stringArray[loop1]  = ' ';
        				loop1++;
        			}
                    break;
                case 'f':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                    	case 'o':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if(stringIn[x]=='r'){
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"for \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                		case 'l':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
							if((stringIn[x]=='o')&&(stringIn[x+1]=='a')&&(stringIn[x+2]=='t')){
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"float \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop4=0;
       		 		while(loop4<50){
        				stringArray[loop4]  = ' ';
        				loop4++;
        			}
                    break;
                case 's':
                    stringArray[y]=stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'w':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='i')&&(stringIn[x+1]=='t')&&(stringIn[x+2]=='c')&&(stringIn[x+3]=='h')){
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"switch \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        
            		}
            		switch(stringIn[x]){
                		case 'h':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='o')&&(stringIn[x+1]=='r')&&(stringIn[x+2]=='t')){
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"short \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                    }
            		switch(stringIn[x]){
                		case 'i':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='g')&&(stringIn[x+1]=='n')&&(stringIn[x+2]=='e')&&(stringIn[x+3]=='d')){
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"signed \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop6=0;
       		 		while(loop6<50){
        				stringArray[loop6]  = ' ';
        				loop6++;
        			}
                    break;
                case 'd':
                    stringArray[y] = stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                		case 'o':
                			if((stringIn[x+1]=='u')&&(stringIn[x+2]=='b')&&(stringIn[x+3]=='l')&&(stringIn[x+4]=='e')){
                        		x++;
                        		x++;
                        		x++;
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"double \n");
                    		}
                    		else{
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"do \n");
                    		}
                    		break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop5=0;
       		 		while(loop5<50){
        				stringArray[loop5]  = ' ';
        				loop5++;
        			}
                    break;
                case 'c':
                    stringArray[y]=stringIn[x];
                    x++;
                    y++;
                    switch(stringIn[x]){
                        case 'o':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='n')&&(stringIn[x+1]=='s')&&(stringIn[x+2]=='t')){
                				x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"const \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                    	case 'a':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
                			if((stringIn[x]=='s')&&(stringIn[x+1]=='e')){
                				x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"case \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                		case 'h':
                			stringArray[y] = stringIn[x];
                    		x++;
                    		y++;
							if((stringIn[x]=='a')&&(stringIn[x+1]=='r')){
                        		x++;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"REWD ");
                        		fprintf(Out,"char \n");
                    		}
                    		else{
                        		while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            		stringArray[y] = stringIn[x];
                            		y++;
                            		x++;
                       			}
                        		x--;
                        		fprintf(Out,"%d ",lineNo);
                        		fprintf(Out,"IDEN ");
                        		fprintf(Out,"%s  \n",stringArray);
                    		}
                			break;
                        default :
                        	while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]=='_')||(stringIn[x]>='a'&& stringIn[x]<='z')){
                            	stringArray[y] = stringIn[x];
                            	y++;
                            	x++;
                        	}
                        	x--;
                        	fprintf(Out,"%d ",lineNo);
                        	fprintf(Out,"IDEN ");
                        	fprintf(Out,"%s  \n",stringArray);
                    		break;
            		}
                    y=0;
        			int loop7=0;
       		 		while(loop7<50){
        				stringArray[loop7]  = ' ';
        				loop7++;
        			}
                    break;         
                case 'a': case 'b': case 'h': case 'j': case 'k': case 'Y': case 'Z': case '_': case 'm': case 'n':
                case 'r': case 'x': case 'y': case 'Q': case 'R': case 'T': case 'U': case 'V': case 'X':
                case 'z': case 'A': case 'B': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P':
                case 'o': case 'p': case 'q':
                	stringArray[y]=stringIn[x];
                    x++;
                    y++;
                    if((stringIn[x]>='a'&&stringIn[x]<='z')||(stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]== '_')){
                        while((stringIn[x]>='A'&&stringIn[x]<='Z')||(stringIn[x]>='a'&& stringIn[x]<='z')||(stringIn[x]=='_')){
                            stringArray[y]=stringIn[x];
                            y++;
                            x++;
                        }
                    }
                    x--;
                    fprintf(Out,"%d ",lineNo);
                    fprintf(Out,"IDEN ");
                    fprintf(Out,"%s  \n",stringArray);
                    y=0;
        			int loop9=0;
       		 		while(loop9<50){
        				stringArray[loop9]  = ' ';
        				loop9++;
        			}
                    break;
                case '{':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"SPEC ");
                     fprintf(Out,"{ \n");
                     break;
                case '}':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"SPEC ");
                     fprintf(Out,"} \n");
                     break;
                case '(':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"SPEC ");
                     fprintf(Out,"( \n");
                     break;
                case ')':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"SPEC ");
                     fprintf(Out,") \n");
                     break;
                case ';':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"SPEC ");
                     fprintf(Out,"; \n");
                     break;
                case '0': case '1': case '6': case '7': case '8': case '9': case '2': case '3': case '4': case '5':
                	stringArray[y]=stringIn[x];
                    x++;
                    y++;
                    while(stringIn[x]>='0'&&stringIn[x]<='9'){
                        stringArray[y]=stringIn[x];
                        x++;
                        y++;
                    }
                    if(stringIn[x]=='.'){
                        stringArray[y]=stringIn[x];
                        x++;
                        y++;
                        while(stringIn[x]>='0'&&stringIn[x]<='9'){
                            stringArray[y]=stringIn[x];
                            x++;
                            y++;
                        }
                        if((stringIn[x]=='e')||(stringIn[x]=='E')){
                            stringArray[y]=stringIn[x];
                            x++;
                            y++;
                            if((stringIn[x]=='+')||(stringIn[x]=='-')||(stringIn[x]>='0'&&stringIn[x]<='9')){
                                stringArray[y]=stringIn[x];
                                x++;
                                y++;
                                while(stringIn[x]>='0'&&stringIn[x]<='9'){
                                    stringArray[y]=stringIn[x];
                                    x++;
                                    y++;
                                }
                            }
                        }
                        x--;
                        fprintf(Out,"%d ",lineNo);
                        fprintf(Out,"FLOT ");
                        fprintf(Out,"%s  \n",stringArray);
                    }
                    else{
                        fprintf(Out,"%d ",lineNo);
                        fprintf(Out,"INTE ");
                        fprintf(Out,"%s  \n",stringArray);
                        x--;
                    }
                    y=0;
        			int loop8=0;
       		 		while(loop8<50){
        				stringArray[loop8]  = ' ';
        				loop8++;
        			}
                    break;
              
                case '+':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"+ \n");
                     break;
                case '=':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"= \n");
                     break;
                case '-':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"- \n");
                     break;
                case '*':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"* \n");
                     break;
                case ',':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,", \n");
                     break;
                case '%':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"% \n");
                     break;
                case '>':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"> \n");
                     break;
                case '<':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"< \n");
                     break;
                case '!':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"! \n");
                     break;
                case '&':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"& \n");
                     break;
                case '[':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"[ \n");
                     break;
                case ']':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"] \n");
                     break;
                case '|':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"| \n");
                     break;
                case '^':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,"^ \n");
                     break;
                case '.':
                     fprintf(Out,"%d ",lineNo);
                     fprintf(Out,"OPER ");
                     fprintf(Out,". \n");
                     break;
                default :
                    break;
            }     
            x++;         
        }
        lineNo++;
        int loop=0;
        while(loop<50){
        	stringArray[loop]=' ';
        	loop++;
        }
        fprintf(Out,"\n");
    } 
    fclose(In);
    fclose(Out);
    system("PAUSE"); 
    return 0;
}
