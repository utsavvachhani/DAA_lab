//insertion Sort
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void insertionsort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		j=i;
		while(j>0 && arr[j-1]>arr[j]){
			int temp;
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j-=1;
		}
	}
}
int main(){
	FILE *fp=fopen("data.txt","r");
	int ch,j,x=0;
	clock_t starttime,endtime;
	int arr[15000];
	int i=0,n;
	FILE *uv=fopen("insinput.txt","w");
	FILE *wr=fopen("insoutput.txt","w");

	printf("code bu utsav vachhani(uv)");
	printf("\nthis code is the Insertion sorting using taken value from user by '.txt' file ,");
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
	printf("Inputing data are store in inssinput.txt");

	//callling insertionsort function
	starttime=clock();
	insertionsort(arr,n);
	endtime=clock();

	//makng sorting file of data
	j=0,i=1;
	while(j!=n){
	    fprintf(wr,"%d\t",arr[j]);
	    j++;
	    if(j%10==0){
		fprintf(wr,"\t---%d\n",i++);
	    }
	}
	printf("\nOutput means sorting data store in insoutput.txt");
	printf("\nNote : last colum of input/output show the index of row.");
	printf("\n\ntime=%f",(endtime-starttime)/CLOCKS_PER_SEC);         }
	else{
		printf("\n\nooooppppppssss!!!!!\nYour data is higher then 15000");
	}
	fclose(wr);
	fclose(uv);
	fclose(fp);

	printf("\n");
	return 0;
}