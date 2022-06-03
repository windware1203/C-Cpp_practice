#include <stdio.h>
#include <stdlib.h>

void printM(double** matrix,int m,int n)
{
   for( int i = 0; i < m; i++ )
   {
      for( int j = 0; j < n; j++ )
      {  
         printf( " %2.2lf ",matrix[i][j]);
      }
      printf( " \n");
   }
   printf( "..................\n");
}
void topBest(double** matrix,int m,int n)
{
   for(int i = 0;i < m;i++)
   { 
      if( matrix[i][0] > matrix [0][0])
      {
         for( int j = 0; j < n; j++)
         {
             double temp = matrix[i][j];
             matrix[i][j] = matrix[0][j];
             matrix[0][j] = temp;
         }
      }
   }     
}

int main()
{
	int m ,n;
   printf( "\nenter the m:");
   scanf("%d",&m);
   
   printf( "\nenter the n:");
   scanf("%d",&n);
   printf( "It is a %d x %d matrix!\n",m,n);

   double **matrix = ( double** ) malloc( m * sizeof( double* ) );
   for(int i = 0; i < m ; i++)
   {
        matrix[i] = (double* ) malloc(n * sizeof(double ) );
   }

   
   printf( "Enter the matrix:\n");
   for( int i = 0; i < m; i++ )
   {
      for( int j = 0; j < n; j++ )
         scanf( "%lf",&matrix[i][j]);
   }



   topBest(matrix, m, n);
   printM(matrix, m, n);
   
   int i = 0, j = 0, k = 0;
   for(k = 0; k < m - 1; k++)
   {
      for(j = k+1; j < n; j++)
      {  
         if(matrix[k][k] != 0 )
            matrix[k][j] = matrix[k][j] / matrix[k][k];
      }
      matrix[k][k] = 1.0;
               
      for(i = k + 1; i < m; i++)
      {
         for(j = k+1; j < n; j++)
            matrix[i][j] = matrix[i][j] - matrix[i][j] * matrix[k][j];
         matrix[i][k] = 0.0;
      }
      topBest(matrix, m, n);
      printM(matrix, m, n);
   }
   
   printf( "......DONE........\n");
   free(matrix);
   return 0;
}
