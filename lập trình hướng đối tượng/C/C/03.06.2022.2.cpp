#include<stdio.h>

main(){
	FILE *f;
	int i, n;
	int a[100], max;
	f = fopen("ltnc.txt", "r");
	fscanf(f,"%d", &n);
	for(i=1; i<=n; i++) fscanf(f, "%d", &a[i]);
	fclose(f);
	printf("Day so co %d phan tu", n);
	for(i=1; i<=n; i++) printf("\n%d", a[i]);
	max = a[1];
	for(i=1; i<=n; i++) if(max < a[i]) max = a[i];
	f = fopen("output.txt", "w");
	fprintf(f, "%d", max);
	fclose(f);
}
