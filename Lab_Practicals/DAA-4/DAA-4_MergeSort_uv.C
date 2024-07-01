//pr-4 Merge Sort
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
void merge(int arr[],int L,int M,int R)
{
	int i,j,k;
	int n1=M-L+1;
	int n2=R-M;

	//create temp array
	int l[15000];
	int r[15000];
	
	for(i=0;i<n1;i++)
		l[i]=arr[L+i];
	for(j=0;j<n2;j++)
		r[j]=arr[M+1+j];

	i=0;
	j=0;
	k=L;

	while(i<n1 && j<n2){
		if(l[i]<=r[j]){
			arr[k]=l[i];
			i++;
		}
		else{
			arr[k]=r[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k]=l[i];
		i++;
		k++;
	}

	while(j<n2){
		arr[k]=r[j];
		j++;
		k++;
	}
}
//-------------------------- mergeSort function -------------------------
void mergeSort(int arr[],int L,int R)
{
	if(L<R)
	{
		int M=(L+(R-1))*0.5;
		mergeSort(arr,L,M);
		mergeSort(arr,M+1,R);
		merge(arr,L,M,R);
	}
}
void main(){
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\data.txt","r");
	int ch,j,x=0;
	clock_t starttime,endtime;
	int arr[15000];
	int i=0,n;
	FILE *uv=fopen("C:\\TURBOC3\\BIN\\project\\merinput.txt","w");
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\meroutput.txt","w");

	clrscr();
	printf("code bu utsav vachhani(uv)");
	printf("\nthis code is the Merge sorting using taken value from user by '.txt' file ,");
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
	printf("Inputing data are store in merinput.txt");

	//callling bubblesort function
	starttime=clock();
	mergeSort(arr,0,n-1);
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
	printf("\nOutput means sorting data store in meroutput.txt");
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