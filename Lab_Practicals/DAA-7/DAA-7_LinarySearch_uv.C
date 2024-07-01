//linear search
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
int linearsearch(int arr[],int n,int find){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==find){
			printf("Your number at %d",i);
			return 0;
		}
	}
	if(arr[i]!=find){
		printf("\nElement is not Founded");
	}
	return -1;
}
void main(){
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\data.txt","r");
	int ch,j,x=0;
	clock_t starttime,endtime;
	int arr[15000];
	int i=0,n,find;
	FILE *uv=fopen("C:\\TURBOC3\\BIN\\project\\lininput.txt","w");


	clrscr();
	printf("code bu utsav vachhani(uv)");
	printf("\nthis code is the linary search using taken value from user by '.txt' file ,");
	printf("\nYour data size is maximum 15000");
	printf("\nHow many data you went to Sort?:");
	scanf("%d",&n);
	if(n<=15000){
	ch=getc(fp);
	while(ch!=EOF){
		if(ch>=48 && ch<=57){
				x=(x*10)+(ch-48);
		}
		else{
			i++;
			arr[i-1]=x;
			x=0;
			if(i==n){
				break;
			}
		}
		ch=getc(fp);
	}
	if(ch==EOF){
		i++;
		arr[i-1]=x;
	}
	printf("\n");
	//making the input file of data
	j=0,i=1;
	while(j!=n){
	    fprintf(uv,"%d\t",arr[j]);
	    j++;
	    if(j%10==0){
		fprintf(uv,"\t---%d\n",i++);
	    }
	}
	printf("Inputing data are store in lininput.txt");
	printf("\nNote : last colum of input/output show the index of row.");

	printf("\n\nEnter the nember wich you find out ?  ");
	scanf("%d",&find);
	starttime=clock();
	linearsearch(arr,n,find);
	endtime=clock();


	printf("\n\ntime=%f",(endtime-starttime)/CLK_TCK);

	}
	else{
		printf("\n\nooooppppppssss!!!!!\nYour data is higher then 15000");
	}
	fclose(uv);
	fclose(fp);
	getch();

}