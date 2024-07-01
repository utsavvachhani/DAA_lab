#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
int main(){
	int arr[200]={1,2,3,4,5,6};
	int i,n=175;
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\arrayD.txt","w");
	clrscr();
	for(i=0;i<=n;i++){
		fprintf(fp,"%d ",arr[i]);
		arr[i+6]=(arr[i]+10)%165;
		if(i%10==9){
			fprintf(fp,"\n");
		}
	}
	printf("Data are write.");
	close(fp);
	return 0;
}