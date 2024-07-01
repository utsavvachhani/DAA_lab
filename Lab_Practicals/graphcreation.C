//making of graph
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
void main(){
	int a[165][165];
	int i,j,n=165;
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\graph.txt","w");
	clrscr();
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	a[0][1]=1;
	a[0][3]=1;
	a[0][6]=1;
	a[0][9]=1;
	a[1][5]=1;
	a[2][4]=1;
	a[3][2]=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				a[i][j]=0;
			}
			if(a[i][j]==1){
				a[j][i]=1;
			}
			if(a[j][i]==1){
				a[i][j]=1;
			}
			fprintf(wr,"%d ",a[i][j]);
			printf("%d",a[i][j]);
			a[i+(i%10)][j+10]=a[i][j];
		}
		fprintf(wr,"\n");
	}
	printf("\n\nData are write in graph.txt");
	fclose(wr);
	getch();
}