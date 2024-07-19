#include <stdio.h>
#include <conio.h>
 main()
{
    FILE *fp;
    char ch;
    printf("Nhap cac ki tu : ");
    fp=fopen("D:\\textfile.txt","wt");
 
    while ((ch=getchar())!=EOF)
        putc(ch,fp);
    fclose(fp);
    getch();
  }

