#include <stdio.h>
// bài 4 vo ghi
// ma tran
main (){
    int m,n,i,j;
	FILE *f;
	f= fopen("matran.txt", "r");
	fscanf (f,"%d%d", &m,&n);
	int a[50][50];
	for ( i =1; i<=m; i++) {
		for ( j =1; j<=n; j++) {
		    fscanf (f,"%d", &a[i][j]); 
		}
	}  
	fclose (f);
	printf (" cap ma tran là %dx%d \n",m,n);
	
	for ( i =1; i<=m; i++) {
		for ( j =1; j<=n; j++) { printf ("%d ", a[i][j]);
		} printf ("\n");
	}
	int t = 1;
	for ( i =1; i<=m; i++) {
		for ( j =1; j<=n; j++) {
			if ( i > j && m == n && a[i][j] != 0) t = 0;
		}
	}
	f = fopen ("output.txt","w");
	fprintf (f, "%d",t);
	fclose(f);
}
