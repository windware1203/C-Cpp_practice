#include <dlfcn.h>
#include <stdio.h>
#define PI 3.1415926

int main()
{
	void *handle = dlopen("libm.so",RTLD_LAZY);
	if(handle == NULL)
		printf("Dynamic linking error!!\n");
	else
	{
		double 	(*cosine)	(double);
		double 	(*sine)		(double);
		float	(*fmax)		(float, float);
		float 	(*fmin)		(float, float);
		int flag;
		do	
		{
			printf("\n.......Function Table.......\n");
			printf("....[ 0 ]:  exit\n");
			printf("....[ 1 ]:  sin \n");
			printf("....[ 2 ]:  cos \n");
			printf("....[ 3 ]:  max \n");
			printf("....[ 4 ]:  min \nEnter what function you want to use: ");
		
			scanf("%d",&flag);
			switch(flag)
			{
				float input1,input2;
				double ina,inb;
				case 0:
					break;
				case 1:
					printf("\n....You choose sin()....\n");
					printf("input a double-type value(degree):");
					int ind;
					scanf("%d",&ind);
					ind %= 360;
					ina = (ind /180.0)*PI;
					sine = dlsym(handle, "sin");
					printf("sin( deg(%d)) = %lf\n",ind,(*sine)(ina));
					break;
				case 2:
					printf("\n....You choose cos()....\n");
					printf("input a double-type value(degree):");
					int indd;
					scanf("%d",&indd);
					indd %= 360;
					inb = (indd /180.0)*PI;
					cosine = dlsym(handle, "cos");
					printf("cos( deg(%d)) = %lf\n",indd,(*cosine)(inb));
					break;
				case 3:
					printf("\n....You choose fmax()....\n");
					printf("input the first float-type value:");
					scanf("%f",&input1);
					printf("input the second float-type value:");
					scanf("%f",&input2);
					fmax = dlsym(handle, "fmax");
					printf("fmax(%f,%f) = %f\n",input1,input2,(*fmax)(input1, input2));
					break;
				case 4:	
					printf("\n....You choose fmin()....\n");
					printf("input the first float-type value:");
					scanf("%f",&input1);
					printf("input the second float-type value:");
					scanf("%f",&input2);
					fmin = dlsym(handle, "fmin");
					printf("fmin(%f,%f) = %f\n",input1,input2,(*fmin)(input1, input2));
					break;
			}
		}while(flag != 0);
		printf("Good bye\n");
	}
	dlclose(handle);		
}
