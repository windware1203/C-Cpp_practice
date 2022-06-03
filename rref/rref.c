#include <stdio.h>
#include <stdlib.h>
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

   for( int i = 0; i < m; i++ )
   {
      for( int j = 0; j < n; j++ )
         scanf( "%d",&matrix[i][j]);
   }

   for( int i = 0; i < m; i++ )
   {
      for( int j = 0; j < n; j++ )
         printf( " %d ",matrix[i][j]);
      printf( " \n");
   }





   free(matrix);
   return 0;
}
