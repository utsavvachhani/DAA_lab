//pr-4 Quick Sort
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
int part(int arr[],int low,int high)
{
	int temp,j,i;
	int pivot;
	pivot=arr[high];
	i=(low-1);
	for(j=low;j<=high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return(i+1);
}
void condition(int arr[],int low,int high){   
	if(low<high)
	{
	int pv=part(arr,low,high);
	condition(arr,low,pv-1);
	condition(arr,pv+1,high);
	}
}
void main(){
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\data.txt","r");
	int ch,j,x=0;
	clock_t starttime,endtime;
	int arr[15000];
	int i=0,n;
	FILE *uv=fopen("C:\\TURBOC3\\BIN\\project\\quiinput.txt","w");
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\quioutput.txt","w");

	clrscr();
	printf("code bu utsav vachhani(uv)");
	printf("\nthis code is the Quick sorting using taken value from user by '.txt' file ,");
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
	printf("Inputing data are store in quiinput.txt");

	//callling bubblesort function
	starttime=clock();
	condition(arr,0,n-1);
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
	printf("\nOutput means sorting data store in quioutput.txt");
	printf("\nNote : last colum of input/output show the index of row.");
	printf("\n\ntime=%f",(endtime-starttime)/CLK_TCK);         }
	else{
		printf("\n\nooooppppppssss!!!!!\nYour data is higher then 15000");
	}
	fclose(wr);
	fclose(uv);
	fclose(fp);
	getch();

}