#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void main(){
	int arr[15020]={23,45,33,89,12,30,21,93,20,75};
	int i=1,j,n=15000;
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\data.txt","w");
	clrscr();
	j=0;
	while(j!=n){
	    fprintf(wr,"%d\t",arr[j]);
	    if(arr[j]+28>32650){
		arr[j+10]=arr[j]%32000;
	    }
	    else{
		arr[j+10]=arr[j]+28;
	    }
	    j++;
	    if(j%10==0){
		fprintf(wr,"%d\n",i++);
		//printf("%d",i);
	    }
	}
	printf("\nData are write");
	fclose(wr);
	getch();
}