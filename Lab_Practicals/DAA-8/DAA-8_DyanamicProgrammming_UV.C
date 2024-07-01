//DAA-8_uv Dynamic Programming
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int c[150][150];
int Dynamic_programming(int d[],int n,int N){
	int i,j,x;
	for(i=1;i<=n;i++){
		c[i][0]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=N+1;j++){
			if(i==1 && j<d[i]){
				c[i][j]=32000;
			}//1
			else if(i==1){
				c[i][j]=1+c[1][j-d[1]];
			} //2
			else if(j<d[i]){
				c[i][j]=c[i-1][j];
			} //3
			else {
				if( c[i-1][j] < ( 1+c[i][j-d[i]] ) ){
					x=c[i-1][j];
				}
				else{	x=1+c[i][j-d[i]];		}
				c[i][j]=x;
			}
		}
	}
	return c[n][N];
}
int main(){
	int N;
	int d[165];
	int n;
	int i,j;
	int ch,x=0;
	clock_t starttime,endtime;
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\Output_m.txt","w");
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\arrayD.txt","r");
	clrscr();
	printf("Code by utsav vachhani(uv).");
	printf("\nThis is code of Dyanmic Programming ");
	printf("\n\"Data size of all operter in maxium 165.\"\n ");
	printf("What is the value of N \n(where N is the number of units for which to make change) :");
	scanf("%d",&N);
	if(N>165) {
		printf("\n\"Data size is Higher then 165.\"");
		return 0;
	}
	printf("\nHow many coines in your problem :");
	scanf("%d",&n);
	if(n>165) {
		printf("\n\"Data size is Higher then 165.\"");
		return 0;
	}

	i=1;
	ch=getc(fp);
	while(ch!=EOF){
		if(ch>=48 && ch<=57){
				x=(x*10)+(ch-48);
		}
		else if(x!=0) {
			i++;
			d[i-1]=x;
			x=0;
			if(i==n+1){
				break;
			}
		}
		ch=getc(fp);
	}
	if(ch==EOF){
		i++;
		d[i-1]=x;
	}
	printf("\nValues are copy Sucessful from ArrayD.txt ");

	starttime=clock();
	Dynamic_programming(d,n,N);
	endtime=clock();

	for(j=1;j<=N+1;j++){
		fprintf(wr,"\t%d",j-1);
		//printf("\t%d",j-1);
	}
	//printf("\n");
	fprintf(wr,"\n--------");
	for(j=1;j<=N+1;j++){
	fprintf(wr,"--------");
	//printf("--------");
	}
	for(i=1;i<=n;i++){
		//printf("\n%d |",d[i]);
		fprintf(wr,"\n%d |",d[i]);
		for(j=1;j<=N+1;j++){
		  //	printf("\t%d",c[i][j]);
			fprintf(wr,"\t%d",c[i][j]);
		}
	}

	printf("\nData are Write sucesfully in OUTPUT_M.txt");

	printf("\n\nThe required coines are %d",c[n][N]);
	printf("\n\nTime=%f\n",(endtime-starttime)/CLOCKS_PER_SEC);
	fclose(fp);
	fclose(wr);
	return -1;
}